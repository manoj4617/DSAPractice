#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int isValid(vector<int>& weights, int days, int cap){
        int d = 1;
        int sum  = 0;
        int n = weights.size();
        for(int i=0;i<n;++i){
            sum += weights[i];
            if(sum > cap){
                d++;
                sum = weights[i];
            }
            if(d > days){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if(n < days){
            return -1;
        }
        int high = accumulate(weights.begin(), weights.end(),0);
        int low = *max_element(weights.begin(), weights.end());

        int res = -1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(isValid(weights, days, mid)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    int res = shipWithinDays(weights, days);
    cout << res << endl;
    return 0;
}