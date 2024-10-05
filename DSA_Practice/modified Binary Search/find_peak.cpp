#include <iostream>
#include <vector>

using namespace std;

int Peak(const vector<int>& num){
    int low = 0;
    int high = num.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(mid == 0 || num[mid - 1] <= num[mid] &&
            mid == num.size() || num[mid] >= num[mid + 1]){
                return num[mid];
            }
        if(mid > 0 && num[mid - 1] > num[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i=0;i<n;++i){
        cin >> num[i];
    }
    cout << Peak(num);
    return 0;
}