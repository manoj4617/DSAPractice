#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Finds the median of two sorted arrays.
 *
 * This function takes two sorted vectors of integers, nums1 and nums2, and
 * returns the median of the two vectors. The median is defined as the middle
 * value of the two vectors if they are concatenated and sorted.
 *
 * The core logic of this function is to find the partition point of the
 * two vectors such that the elements to the left of the partition point in
 * both vectors are less than or equal to the elements to the right of the
 * partition point in both vectors. This is done by using a binary search
 * approach to find the partition point. The binary search is performed on the
 * smaller of the two vectors, and the partition point is determined by
 * comparing the elements at the mid point of the smaller vector with the
 * elements at the mid point of the larger vector.
 *
 * The intuition behind this solution is to find the partition point of the
 * two vectors such that the elements to the left of the partition point in
 * both vectors are less than or equal to the elements to the right of the
 * partition point in both vectors. This is done by using a binary search
 * approach to find the partition point. The binary search is performed on the
 * smaller of the two vectors, and the partition point is determined by
 * comparing the elements at the mid point of the smaller vector with the
 * elements at the mid point of the larger vector.
 */
double medianOfSortedArrays(vector<int>& nums1, vector<int>& nums2){
    if(nums1.size() > nums2.size()){
        swap(nums1, nums2);
    }

    int m = nums1.size();
    int n = nums2.size();

    int total = m + n;
    int low = 0, high = m;

    // Binary search approach to find the partition point of the two vectors.
    while(low <= high){
        int mid1 = (high + low) / 2;
        int mid2 = (total + 1) / 2 - mid1;

        int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r1 = (mid1 == m) ? INT_MAX : nums1[mid1];
        int r2 = (mid2 == n) ? INT_MAX : nums2[mid2];

        // Check if the partition point is valid.
        if(l1 <= r2 && l2 <= r1){
            if(total % 2 == 0){
                // Calculate the median of the two vectors.
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else{
                // Calculate the median of the two vectors.
                return max(l1, l2);
            }
        }
        // If the partition point is not valid, adjust the search window.
        else if(l1 > r2){
            high = mid1 - 1;
        }
        else{
            low = mid1 + 1;
        }
    }
    return 0.0;
}

int main(){
    int m,n;
    cin >> m >> n;
    vector<int> nums1(m);
    vector<int> nums2(n);
    for(int i=0;i<m;++i){
        cin >> nums1[i];
    }

    for(int i=0;i<n;++i){
        cin >> nums2[i];
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    cout << medianOfSortedArrays(nums1,nums2);
    return 0;
}