#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/**
 * This function takes two vectors of integers, A and B, and returns the
 * maximum length of any contiguous subarray of A that is also a contiguous
 * subarray of B.
 *
 * The function uses a dynamic programming approach to solve the problem. The
 * dp array is used to store the maximum length of any contiguous subarray of
 * B that ends at the current index. The dp array is initialized to 0.
 *
 * The outer loop iterates over the elements of A, and the inner loop iterates
 * over the elements of B in reverse order. For each pair of elements, the
 * function checks if the elements are equal. If they are, the function updates
 * the dp array at the current index to be one more than the value at the
 * previous index. If they are not equal, the function sets the dp array at the
 * current index to 0.
 *
 * The function keeps track of the maximum length of any contiguous subarray of
 * A that is also a contiguous subarray of B in the variable ans. The function
 * returns ans at the end.
 */
int max_subarray(vector<int>& A, vector<int>& B){
    /******************Brute Force***************/
    // int max_count = INT_MIN;
    // for(int i=0;i<nums1.size();++i){
    //     for(int j=0;j<nums2.size();++j){
    //         int temp_i = i, temp_j = j, count = 0;
    //         if(nums1[i] == nums2[j]){
    //             while(nums1[temp_i] == nums2[temp_j]){
    //                 temp_i++;
    //                 temp_j++;
    //                 count++;
    //             }
    //             max_count = max(count , max_count);
    //             count = 0;
    //         }

    //     }
    // }

    // return max_count;

    /******************DP***************/
    if (A.size() < B.size()) swap(A, B);
        int M = A.size(), N = B.size();
        vector<int> dp(N + 1, 0);
        int ans = 0;
        
        // Iterate over the elements of A
        for(int i = 0; i < M; i++) {
            // Iterate over the elements of B in reverse order
            for(int j = N - 1; j >= 0; j--) {
                // Check if the current elements of A and B are equal
                if (A[i] == B[j]) {
                    // If they are equal, update the dp array at the current index
                    // to be one more than the value at the previous index
                    dp[j + 1] = 1 + dp[j];
                } else {
                    // If they are not equal, set the dp array at the current index to 0
                    dp[j + 1] = 0;
                }
                
                // Update the maximum length of any contiguous subarray of A that is also a contiguous subarray of B
                ans = max(ans, dp[j + 1]);
            }
            
        }
        
        // Return the maximum length
        return ans;

}

int main(){
    vector<int> nums1, nums2;
    int n,m,temp;

    cin >> m >> n;
    for(int i=0;i<m;++i){
        cin >> temp;
        nums1.push_back(temp);
    }

    for(int i=0;i<n;++i){
        cin >> temp;
        nums2.push_back(temp);
    }

    cout << max_subarray(nums1, nums2) << endl;

    return 0;
}