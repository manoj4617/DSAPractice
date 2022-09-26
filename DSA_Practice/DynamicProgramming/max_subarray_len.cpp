#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

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
        
        for(int i = 0; i < M; i++) {
            for(int j = N - 1; j >= 0; j--) {
                
                if (A[i] == B[j]) {
                    dp[j + 1] = 1 + dp[j];
                } else {
                    dp[j + 1] = 0;
                }
                              
                ans = max(ans, dp[j + 1]);
            }
            
        }
        
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