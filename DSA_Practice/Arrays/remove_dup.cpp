#include<iostream>
#include<vector>

using namespace std;

void remove_dup(vector<int> arr){
    int j = 1;
    for(int i=1;i<arr.size();++i){
        if(arr[i-1] != arr[i]){
            arr[j] = arr[i];
            j++;
        }
    }
}

int removeElement(vector<int>& nums, int val) {
   int i=0, ans = 0;
   while(i < nums.size()){
    if(nums[i] == val){
        int j = i;
        while(j < nums.size()){
            nums[j] = nums[j+1];
            j++;
        }
        nums[j] = -1;
    }
    else{
        i++;
    }
   }
   return nums.size() - ans;
}

int main(){
    int n,temp,val;
    cin >> n >> val;

    vector<int> arr;
    for(int i=0;i<n;++i){
        cin >> temp;
        arr.push_back(temp);
    }
    cout << removeElement(arr,val);
    return 0;
}