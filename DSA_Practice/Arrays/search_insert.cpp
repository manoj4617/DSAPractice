#include<iostream>
#include<vector>

using namespace std;

int binarysearchinsert(vector<int> nums,int target){
    int l = 0, h = nums.size()-1;
    int mid;
    while(l<=h){
        mid = l+(h-l)/2;

        if(target > nums[mid]){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return l;
}
    

int main(){
    int n,temp,target;
    vector<int> arr;
    cin >> n >> target;
    for(int i=0;i<n;++i){
        cin >> temp;
        arr.push_back(temp);
    }
    cout << binarysearchinsert(arr,target);
    return 0;
}