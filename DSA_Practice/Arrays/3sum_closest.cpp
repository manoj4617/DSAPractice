#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int threeSumClosest(vector<int>& nums, int target){

    if(nums.size() < 3)
        return -1;

    int closeDiff = nums[0] + nums[1] + nums[2];
    int diff = abs(closeDiff - target);

    sort(nums.begin(), nums.end());
    int sum = 0;
    for(int i=0;i<nums.size() - 2; i++){
        int low = i + 1;
        int high = nums.size() - 1;
        sum = 0;

        while(low < high){
            sum = nums[i] + nums[low] + nums[high];
            int newDiff = abs(sum - target);
            if(newDiff < diff){
                diff = newDiff;
                closeDiff = sum;
            }
            
            if(sum > target)
                high--;
            else
                low++;
        }   
    }

    return closeDiff;
}

int main(){

    int n, target;
    vector<int> nums;

    cin >> n >> target;

    for(int i=0;i<n;++i)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << threeSumClosest(nums, target) << "\n";
    return 0;
}
