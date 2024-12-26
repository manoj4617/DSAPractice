#include <iostream>
#include <vector>

using namespace std;

/**
 * This function performs a depth-first search on the given triangle, starting at row i and column j.
 * The function returns the minimum total sum of the elements in the triangle from the starting point to the bottom.
 * The function assumes that the given triangle is a valid triangle, i.e. it is a lower triangular matrix.
 * The function takes advantage of the fact that the minimum total sum of the elements in the triangle is the sum of the minimum total sum of the elements in the two sub-triangles formed by the current element and the two elements below it.
 *
 * @param triangle A vector of vectors of integers representing the input triangle.
 * @param i The row index of the current element in the triangle.
 * @param j The column index of the current element in the triangle.
 * @return The minimum total sum of the elements in the triangle from the starting point to the bottom.
 */
int dfs(vector<vector<int>>& triangle, int i, int j){
    // If the current element is at the bottom of the triangle, return its value
    if(j == triangle.size() - 1){
        return triangle[j][i];
    }
    // Recursively call the function on the left and right sub-triangles
    int x = dfs(triangle, i, j + 1);
    int y = dfs(triangle, i + 1, j + 1);
    // Return the minimum total sum of the two sub-triangles plus the value of the current element
    return triangle[j][i] +  min(x,y);
}


int minimumTotal(vector<vector<int>>& triangle) {
    return dfs(triangle, 0, 0);
}

int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(triangle) << endl;
    return 0;
}
