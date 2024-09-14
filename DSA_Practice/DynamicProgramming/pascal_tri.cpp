#include<iostream>
#include<vector>

using namespace std;

/**
 * This function takes an integer as input and returns a vector of integers.
 * The vector of integers is the nth row of the Pascal's triangle.
 *
 * The algorithm works by first creating a 2D vector of vectors of integers.
 * The outer vector is of size n+1, and the inner vectors are of size n+1.
 * The outer vector is indexed by the row number, and the inner vectors are
 * indexed by the column number.
 *
 * The algorithm then iterates over each row of the Pascal's triangle, and for
 * each row, it iterates over each column of the row. For each column, it
 * calculates the value of the cell by adding the two values above it.
 *
 * Finally, the algorithm returns a vector of integers which is the nth row of
 * the Pascal's triangle.
 */
vector<int> pascal_triangle(int num_rows){
    // Create a 2D vector of vectors of integers
    vector<vector<int>> p_tri;

    // Iterate over each row of the Pascal's triangle
    for(int i=0;i<=num_rows;++i){
        // Create a vector of size n+1, and initialize it to 1
        p_tri.push_back(vector<int>(i+1,1));

        // Iterate over each column of the row
        for(int j=1;j<i;++j){
            // Calculate the value of the cell by adding the two values above it
            p_tri[i][j] = p_tri[i-1][j] + p_tri[i-1][j-1];
        }
    }

    // Create a vector of integers to store the nth row of the Pascal's triangle
    vector<int> res;

    // Iterate over each element of the nth row of the Pascal's triangle
    for(int i=0;i<p_tri[num_rows].size();++i){
        // Add the element to the vector of integers
        res.push_back(p_tri[num_rows][i]);
    }

    // Return the vector of integers
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> res = pascal_triangle(n);
    return 0;
}