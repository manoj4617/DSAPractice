#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of integers and two indices, i and j, and
 * returns the minimum number of scalar multiplications required to
 * multiply the matrices from index i to j in the given vector.
 *
 * The function uses a recursive approach to solve the problem. It
 * iterates over each possible split point from i to j-1, and for each
 * split point, it recursively calls itself to compute the minimum
 * number of scalar multiplications required to multiply the matrices
 * from i to the split point and from the split point+1 to j. The
 * function then adds the cost of multiplying the two resulting
 * matrices (which is the product of the dimensions of the matrices at
 * indices i-1, k, and j) and assigns the minimum of this sum and the
 * current answer to the answer.
 *
 * The function returns the minimum number of scalar multiplications
 * required to multiply all the matrices from index i to j in the
 * given vector.
 */
int MatrixChainMultiplication(vector<int>& arr, int i, int j){
    // Base case: if i >= j, then there is only one matrix, so
    // the number of scalar multiplications required is 0
    if(i >= j){
        return 0;
    }

    // Initialize the answer to the maximum possible value
    int ans = INT_MAX;

    // Iterate over each possible split point from i to j-1
    for(int k=i;k<=j-1;++k){
        // Recursively call the function to compute the minimum
        // number of scalar multiplications required to multiply the
        // matrices from i to the split point and from the split
        // point+1 to j
        int temp = MatrixChainMultiplication(arr, i, k) +
                    MatrixChainMultiplication(arr, k+1, j);

        // Add the cost of multiplying the two resulting matrices
        temp += (arr[i-1] * arr[k] * arr[j]);

        // Update the answer to the minimum of this sum and the
        // current answer
        ans = min(ans, temp);
    }

    // Return the minimum number of scalar multiplications required
    // to multiply all the matrices from index i to j in the given
    // vector
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    cout << MatrixChainMultiplication(arr, 1, n-1);
    return 0;
}