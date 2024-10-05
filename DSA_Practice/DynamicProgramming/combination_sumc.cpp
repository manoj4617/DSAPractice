#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> CombinationSum(vector<int>& nums, int target){
    if(nums.empty())
        return {{0}};
    
    int n = nums.size();
    vector<vector<vector<int>>> dp(target + 1);
    dp[0].push_back({});

    for(int i=1;i<=target;++i){
        for(int j=0;j<n;++j){
            if(nums[j] <= i){
                for(auto& p : dp[i - nums[j]]){
                    vector<int> temp = p;
                    temp.push_back(nums[j]);
                    sort(temp.begin(), temp.end());
                    if(find(dp[i].begin(), dp[i].end(), temp) == dp[i].end()){
                        dp[i].push_back(temp);
                    }
                }
            }
        }
    }
    return dp[target];
}


int main(){
    int n,t;
    cin >> n >> t;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    vector<vector<int>> res = CombinationSum(nums,t );
    for(auto& v : res){
        for(int &n : v){
            cout << n << " ";
        }
        cout << "\n";
    }
    return 0;

}