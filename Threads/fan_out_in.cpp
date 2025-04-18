#include <atomic>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <random>
#include <chrono>

using namespace std;
using Matrix = vector<vector<double>>;
atomic<int> completed_jobs{0};
bool all_jobs_done = false;

struct MatrixQueue {
    int startRow;
    int endrow;
    Matrix a;
    Matrix b;
    MatrixQueue(int s_row, int e_row, Matrix &a_mat, Matrix &b_mat) : 
        startRow(s_row), endrow(e_row), a(a_mat), b(b_mat){}
    MatrixQueue(){}
};

queue<MatrixQueue> mat_q;
mutex job_mtx;
mutex res_mtx;
condition_variable job_cv;
Matrix generateRandomMatrix(size_t rows, size_t cols){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0,2.0);
    
    Matrix matrix(rows, vector<double>(cols));
    for(auto& row : matrix){
        for(auto& elem : row){
            elem = dis(gen);
        }
    }
    return matrix;
}

void multiplyMatrix(const Matrix& a, const Matrix& b, Matrix& res, 
    size_t startrow, size_t endrow, mutex& mtx){
    if(a.empty() || b.empty() || a[0].size() != b.size()){
        throw invalid_argument("Incompatible matrix dimension");
    }
    size_t m = a[0].size();
    size_t n = b[0].size();


    for(size_t i = startrow ; i < endrow ;++i){
        for(size_t  j = 0; j < n; ++j){
            double sum = 0.0;
            for(size_t k = 0; k < m; ++k){
                sum += a[i][k] * b[k][j];
            }
            lock_guard<mutex> lock(mtx);
            res[i][j] = sum;
        }
    }
}

void worker(int id, Matrix& res, int total_jobs){
    while(true){
        MatrixQueue job;
        {
            unique_lock<mutex> lock(job_mtx);
            job_cv.wait(lock, [](){return !mat_q.empty() || all_jobs_done;});
            if(all_jobs_done && mat_q.empty()){
                break;
            }
            job = mat_q.front();
            mat_q.pop();
        }

        cout << "Worker " << id << " Multiplying matrices" << endl;
        auto start = chrono::high_resolution_clock::now();
        multiplyMatrix(job.a, job.b, res, job.startRow, job.endrow, res_mtx);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "Worker " << id << " finished multiplication in: " << duration.count()  << " seconds" << endl;
        if(++completed_jobs == total_jobs){
            {
                lock_guard<mutex> lock(job_mtx);
                all_jobs_done = true;
            }
            job_cv.notify_all();
            break;
        }
    }
}

int main(){
    const size_t SIZE = 500;
    const size_t THREADS = thread::hardware_concurrency();

    cout << "Generating Matrices of " << SIZE << "x" << SIZE <<  ".." << endl;
    Matrix a = generateRandomMatrix(SIZE, SIZE);
    Matrix b = generateRandomMatrix(SIZE, SIZE);
    Matrix res(a.size(), vector<double>(b[0].size()));

    vector<thread> workers;
    for(int i=0;i<THREADS;++i){
        workers.push_back(thread(worker, i, ref(res), THREADS));
    }

    int rows_per_thread = a.size() / THREADS;
    int extra_rows = a.size() % THREADS;
    int startrow = 0;
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < THREADS; ++i){
        unique_lock<mutex> lock(job_mtx);
        int endrow = startrow + rows_per_thread + (i < extra_rows ? 1 : 0);
        mat_q.push(
            MatrixQueue{startrow, endrow, a, b}
        );
        startrow = endrow;
        job_cv.notify_all();
    }

    for(auto& t : workers){
        t.join();
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time_taken = end - start;
    cout << "Finished matrix multiplication in " << time_taken.count() << " second\n";
    
    std::cout << "Verifying one element..." << std::endl;
    size_t checkRow = 0;
    size_t checkCol = 0;
    double expected = 0.0;
    for (size_t k = 0; k < SIZE; ++k) {
        expected += a[checkRow][k] * b[k][checkCol];
    }
    
    std::cout << "Expected: " << expected << ", Got: " << res[checkRow][checkCol] 
              << " (Difference: " << std::abs(expected - res[checkRow][checkCol]) << ")" << std::endl;
    return 0;
}