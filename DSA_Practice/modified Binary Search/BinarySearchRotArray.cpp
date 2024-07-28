#include <iostream>
#include <vector>

using namespace std;

int BinarySearchRotated(vector<int>& nums, int target)
{
	// your code will replace this placeholder return statement
    int l = nums.size() - 1;
    int low = 0;
    int high = l;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && target < nums[mid]){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        else{
            if(nums[mid] < target && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

void reverse_array(vector<int>& arr, int start, int end){
    while(start < end){
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void rotate_array(vector<int>& arr,int d){
    if(d == 0)
        return;

    d = d%arr.size();

    reverse_array(arr,0,arr.size()-1);
    reverse_array(arr,0,d-1);
    reverse_array(arr,d,arr.size()-1);
}

int main(){
    int n, rotation;
    cin >> n >> rotation;
    vector<int> nums(n);

    for(int i=0;i<n;++i){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int k;
    cin >> k;

    rotate_array(nums,rotation);
    if(int result = BinarySearchRotated(nums, k) == -1){
        cout << "Not found!\n";
    }else{
        cout << "Found at: \n" << result;
    }

}
