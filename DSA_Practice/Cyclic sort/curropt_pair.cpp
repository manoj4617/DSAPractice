#include <iostream>
#include <vector>

using namespace std;

void swap_num(int &x , int &y){
    int temp = x;
    x = y;
    y = temp;
}

vector<int> CurroptPair(vector<int> &nums){
    int i = 0;
    int n = nums.size();

    while(i < n){
        int val = nums[i] - 1;
        if(nums[i] != nums[val]){
            swap_num(nums[i], nums[val]);
        }
        else{
            i++;
        }
    }
    vector<int> res(2);
    for(int i=0;i<n;++i){
        if(i != nums[i] + 1){
            res[0] = i + 1;
            res[1] = nums[i];
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int>  num(n);
    for(int i=0;i<n;++i){
        cin >> num[i];
    }
    vector<int> res = CurroptPair(num);
    cout << res[0] << " " << res[1];
    return 0;
}