#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxAreaHistogram(const vector<int>& heights){
    int n = heights.size();
    stack<int> st;
    st.push(-1);
    int maxArea = 0;
    for(int i=0;i<n;++i){
        while(st.top() != -1 && heights[st.top()] >= heights[i]){
            int curHeight = heights[st.top()];
            st.pop();
            int width = i - st.top() - 1;
            maxArea = max(maxArea, curHeight * width);
        }
        st.push(i);
    }
    while(st.top() != -1){
        int curHeight = heights[st.top()];
        st.pop();
        int width = n - st.top() - 1;
        maxArea = max(maxArea, curHeight * width);
    }
    return maxArea;
}
/**
 * This function takes a 2D vector of characters and returns an integer. The
 * returned integer is the maximum area of a rectangle that can be formed from
 * the given matrix. The matrix is a 2D vector of characters, where '1' represents
 * a filled cell and '0' represents an empty cell.
 *
 * The algorithm works by iterating over the matrix row by row. For each row, it
 * calculates the maximum area of a rectangle that can be formed from the given
 * heights. The heights are calculated by taking the number of consecutive '1'
 * characters in the matrix from the current position to the left and adding one
 * to it if the current character is '1'. If the current character is '0', the
 * height is set to 0.
 *
 * The maximum area is then calculated by calling the maxAreaHistogram function
 * and taking the maximum of the current maximum area and the returned maximum
 * area.
 *
 * Finally, the function returns the maximum area.
 */
int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size(); // Get the number of rows in the matrix
    int n = matrix[0].size(); // Get the number of columns in the matrix
    vector<int> heights(n); // Create a vector to store the heights for each column
    int maxArea = 0; // Initialize the maximum area to 0
    for(int i=0;i<m;++i){ // Iterate over the matrix row by row
        for(int j=0;j<n;++j){ // Iterate over the matrix column by column
            // Calculate the height of the current column by taking the number of
            // consecutive '1' characters in the matrix from the current position
            // to the left and adding one to it if the current character is '1'
            heights[j] = (matrix[i][j] == '0') ? 0 : heights[j] + 1;
        }
        // Calculate the maximum area of a rectangle that can be formed from the
        // given heights
        maxArea = max(maxArea, maxAreaHistogram(heights));
    }
    // Return the maximum area
    return maxArea;  
}

int main(){
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << maximalRectangle(matrix) << endl;

    return 0;
}