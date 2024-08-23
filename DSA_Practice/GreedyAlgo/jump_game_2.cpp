#include <iostream>
#include <vector>

using namespace std;

int JumpGame2(vector<int>& nums){
    int n = nums.size();
    vector<int> minJump(n, INT_MAX);
    minJump[n - 1] = 0;
    for(int i = n - 2;i >= 0; --i){
        int maxJump = min(i + nums[i], n - 1);
        for(int j = i + 1; j <= maxJump; ++j){
            if(minJump[j] != INT_MAX){
                minJump[i] = min(minJump[i], minJump[j] + 1);
            }
        }
    }
    return minJump[0];
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }

    cout << "Minimum number of jumps: " << JumpGame2(nums);
}