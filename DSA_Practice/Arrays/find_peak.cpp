#include <iostream>
#include <vector>

using namespace std;

int find_peak(vector<int> &num){

    int start = 0;
    int end = num.size() - 1;

     while (start <= end) { // Corrected comparison for handling edges
        int mid = start + (end - start) / 2;

        // Check if we have found a peak
        if ((mid == 0 || num[mid - 1] <= num[mid]) && 
            (mid == num.size() - 1 || num[mid] >= num[mid + 1])) {
            return num[mid];
        }

        if (mid > 0 && num[mid - 1] > num[mid]) { // Move towards increasing side
            end = mid - 1;
        } else { 
            start = mid + 1; // Move towards potentially increasing side
        }
    }
    return -1;
}

int main(){

    int n;
    cin >> n;
    
    vector<int> peak;
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        peak.push_back(t);
    }

    cout << "peak: " << find_peak(peak) << endl;
    return 0;
}