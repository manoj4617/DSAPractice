#include <iostream>
#include <vector>


using namespace std;

/**
 * This function merges two sorted arrays into a single sorted array.
 *
 * @param num: The array to be merged.
 * @param begin: The starting index of the first sorted array.
 * @param mid: The ending index of the first sorted array.
 * @param end: The ending index of the second sorted array.
 */
void merge(int num[], int begin, int mid ,int end){
    // Create a temporary array to hold the merged array.
    int temp[end-begin+1];
    
    // Initialize indices for the first sorted array.
    int i = begin;
    
    // Initialize indices for the second sorted array.
    int j = mid+1;
    
    // Initialize the index for the merged array.
    int k = 0;
    
    // Merge the two sorted arrays into the temporary array.
    while(i <= mid && j <= end){
        // If the element from the first sorted array is smaller,
        // add it to the temporary array and increment the index.
        if(num[i] < num[j]){
            temp[k++] = num[i++];
        }
        // If the element from the second sorted array is smaller,
        // add it to the temporary array and increment the index.
        else{
            temp[k++] = num[j++];
        }
    }
    
    // Add the remaining elements from the first sorted array to the temporary array.
    while(i <= mid){
        temp[k++] = num[i++];
    }
    
    // Add the remaining elements from the second sorted array to the temporary array.
    while(j <= end){
        temp[k++] = num[j++];
    }
    
    // Copy the elements from the temporary array back to the original array.
    for(int i = begin; i <= end; i++){
        num[i] = temp[i-begin];
    }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

/**
 * This function implements the Merge Sort algorithm to sort an array of integers.
 * 
 * @param num: The array of integers to be sorted.
 * @param begin: The starting index of the subarray to be sorted.
 * @param end: The ending index of the subarray to be sorted.
 */
void merge_sort(int num[], int begin, int end){
    // Base case: If the subarray has only one element or is empty, there is
    // nothing to be sorted, so we return.
    if(begin >= end)
        return;
    
    // Find the middle index of the subarray.
    int mid = begin + (end - begin) / 2;
    
    // Recursively sort the left and right subarrays.
    merge_sort(num, begin, mid);
    merge_sort(num, mid+1,  end);
    
    // Merge the sorted left and right subarrays into the original array.
    merge(num, begin, mid , end);

}



int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    merge_sort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
}
