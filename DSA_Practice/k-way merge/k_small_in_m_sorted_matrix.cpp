#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// This function takes in a 2D vector of integers and an integer k, and returns the kth smallest number in the matrix.
// The function uses a priority queue to keep track of the k smallest numbers from the matrix.
// The priority queue is sorted in descending order based on the value of the numbers.
int KSmallestNumber(vector<vector<int>> matrix, int k)
{
    // Declare a pair to store the number and its position in the matrix.
    pair<int, pair<int, int>> pr;
    // Declare a priority queue to store the numbers and their positions in the matrix.
    // The priority queue will be sorted in descending order based on the value of the numbers.
    priority_queue<pair<int, pair<int, int>>,
                    vector<pair<int, pair<int, int>>>,
                    greater<pair<int, pair<int, int>>>> pq;

    // Calculate the number of rows in the matrix.
    int row_len = matrix.size();
    // Initialize the priority queue with the first element from each row.
    for(int i=0;i<row_len;i++){
        pq.push({matrix[i][0], {i,0}});
    }

    // Initialize a counter to keep track of the number of elements popped from the priority queue.
    int count = 0;
    // Declare variables to store the row index, column index, and the number from the matrix.
    int r, c, num;
    // While there are still elements in the priority queue and the counter is less than k,
    while(pq.size() != 0 && count < k){
        // Get the smallest number from the priority queue.
        num = pq.top().first;
        r = pq.top().second.first;
        c = pq.top().second.second;

        // Remove the smallest number from the priority queue.
        pq.pop();

        // Calculate the index of the next element in the same row.
        int nextElement = c + 1;

        // If the next element exists, add it to the priority queue.
        if(nextElement < matrix[r].size()){
            pq.push({matrix[r][nextElement], {r, nextElement}});
        }
        // Increment the counter.
        count++;
    }

    // Return the kth smallest number from the matrix.
    return matrix[r][c];
}

void Print2dMatrix(vector<vector<int>> matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout << "\t" << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    std::vector<std::vector<std::vector<int>>> matrix ={
            {{2, 6, 8}, 
            {3, 7, 10}, 
            {5, 8, 11}}, 
           
            {{1, 2, 3}, 
            {4, 5, 6}, 
            {7, 8, 9}},
               
            {{5}},
            
            {{2, 5, 7, 9, 10},
            {4, 6, 8, 12, 14},
            {11, 13, 16, 18, 20},
            {15, 17, 21, 24, 26},
            {19, 22, 23, 25, 28}},

            {{3, 5, 7, 9, 11, 13},
            {6, 8, 10, 12, 14, 16},
            {15, 17, 19, 21, 23, 25},
            {18, 20, 22, 24, 26, 28},
            {27, 29, 31, 33, 35, 37},
            {30, 32, 34, 36, 38, 40}}
             };

    std::vector<int> k = {3, 4, 1, 10, 15};
    
    for (int i=0; i< k.size(); i++){
        std::cout<<i+1<< ".\tInput matrix: \n";
        Print2dMatrix(matrix[i]);
        std::cout<<std::endl;
        std::cout<<"\tK = "<<k[i]<<std::endl;
        std::cout<<"\tKth smallest number in the matrix is: "<<KSmallestNumber(matrix[i], k[i])<<std::endl;
        std::cout<< std::string(100, '-') << "\n";
    }
}