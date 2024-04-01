#include <iostream>
#include <vector>

using namespace std;

int min_subarray_sum(vector<int> &num, int t){

    int sum = 0, start = 0, end = 0, min_len = INT_MAX;

    while(end < num.size()){
        sum += num[end];

        if(sum >= t){
            while(sum >= t){
                min_len = min(min_len, end - start + 1);
                sum -= num[start];
                start++;
            }
        }
        end++;
    }

    return min_len == INT_MAX ? 0 : min_len;
}

int main(){

    int n, t;
    cin >> n >> t;

    vector<int> num;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }

    cout << min_subarray_sum(num, t) << "\n";
    return 0;
}