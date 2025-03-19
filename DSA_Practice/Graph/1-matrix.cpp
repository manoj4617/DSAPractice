#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * This function takes a 2D vector of integers (a matrix) as an argument and
 * returns a new matrix of the same size, where each element is the minimum
 * number of steps to reach a 0 from that element's position in the matrix.
 *
 * The algorithm works by first initializing a new matrix called dist to the
 * same size as the input matrix, where all elements are set to INT_MAX.
 * Then, all elements of the input matrix that are 0 are added to a queue, and
 * the corresponding elements of the dist matrix are set to 0.
 *
 * Then, the algorithm works by popping elements from the queue, and for each
 * of them, it explores all of its neighboring elements in all four directions
 * (up, down, left, right). If the neighbor is not out of bounds of the matrix
 * and if the distance to the neighbor is greater than the current distance to
 * the popped element plus 1, the distance to the neighbor is updated to be
 * the current distance to the popped element plus 1, and the neighbor is
 * added to the queue.
 *
 * The algorithm continues until the queue is empty, at which point it returns
 * the dist matrix.
 */
vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    /**
     * The dist matrix is used to keep track of the minimum distance from each
     * cell to a 0 in the matrix.
     */
    vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
    /**
     * The dirs matrix is used to keep track of the four possible directions to
     * move in the matrix (up, down, left, right).
     */
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    /**
     * The q queue is used to keep track of all of the elements in the matrix
     * that are 0, and need to be processed.
     */
    queue<pair<int,int>> q;

    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(mat[i][j] == 0){
                /**
                 * If the element is a 0, add it to the queue and set its
                 * corresponding element in the dist matrix to 0.
                 */
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for(auto& dir : dirs){
            int newR = row + dir[0];
            int newC = col + dir[1];

            if(newR >= 0 && newR < m && newC >= 0 && newC < n){
                if(dist[newR][newC] > dist[row][col] + 1){
                    /**
                     * If the distance to the neighbor is greater than the
                     * current distance to the popped element plus 1, update
                     * the distance to the neighbor to be the current distance
                     * to the popped element plus 1, and add the neighbor to the
                     * queue.
                     */
                    dist[newR][newC] = dist[row][col] + 1;
                    q.push({newR, newC});
                }
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    cout << "Matrix before update: \n";
    for(int i=0;i<mat.size();++i){
        for(int j=0;j<mat[0].size();++j){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    vector<vector<int>> res = updateMatrix(mat);
    cout << "Matrix after update: \n";

    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[0].size();++j){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}