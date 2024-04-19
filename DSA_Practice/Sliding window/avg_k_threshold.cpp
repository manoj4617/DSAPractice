#include <vector>
#include <iostream>

using namespace std;

/*
This function counts the number of subarrays of size 'k' in the given array 
'arr' which have an average greater than or equal to the 'threshold'.

The function iterates over the array and calculates the sum of the first 'k'
elements. This is the sum of the first subarray. It then calculates the average
of this subarray by dividing the sum by 'k'. If the average is greater than or
equal to the 'threshold', it increments the count of subarrays with average
greater than or equal to the threshold.

The function then iterates over the remaining elements of the array and does
the following:
    1. Subtracts the first element of the subarray from the sum.
    2. Adds the next element of the array to the sum.
    3. Calculates the average of the new subarray by dividing the sum by 'k'.
    4. If the average is greater than or equal to the 'threshold', it increments
       the count of subarrays with average greater than or equal to the
       threshold.

The function returns the count of subarrays with average greater than or
equal to the 'threshold'.
*/
int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int avg = 0, sum = 0;
        int n = arr.size();
        int count = 0;

        // Calculate sum of first 'k' elements and their average
        for(int i=0;i<k;++i){
            sum += arr[i];
        }
        avg = sum / k;

        // If the average is greater than or equal to the threshold, increment the count
        if(avg >= threshold)
            count++;

        // Iterate over the remaining elements of the array and calculate the average of
        // each subarray of size 'k' and increment the count if the average is greater
        // than or equal to the threshold
        for(int i=0;i<n-k;++i){
            sum -= arr[i];
            sum += arr[i+k];
            avg = sum / k;

            if(avg >= threshold)
                count++;
        }

        return count;
}

int main(){

    vector<int> arr;
    int k , t, n;
    cin >> n >> k >> t;
    for(int i=0;i<n;++i){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << numOfSubarrays(arr,k,t);

    return 0;
}