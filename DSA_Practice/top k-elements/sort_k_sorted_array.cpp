#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * This function takes a vector of integers and an integer k, and returns a vector of integers which is sorted in ascending order.
 * The function uses a priority queue to keep track of the k smallest elements in the vector.
 * The priority queue is sorted in ascending order based on the integer values.
 * The function iterates through the vector and adds each element to the priority queue.
 * If the priority queue size is greater than k, the function removes the largest element from the priority queue and adds it to the result vector.
 * Finally, the function returns the result vector.
 * 
 * @param arr The vector of integers to be sorted.
 * @param k The integer representing the number of elements to be kept in the priority queue.
 * @return The vector of sorted integers.
 */
vector<int> sortKSortedArray(vector<int>& arr, int k){
    // Declare a priority queue to store the k smallest elements in the vector.
    priority_queue<int, vector<int>, greater<int>> pq;

    // Declare a vector to store the final result.
    vector<int> res;

    // Iterate through the vector and add each element to the priority queue.
    int len = arr.size();
    for(int i=0;i<len;++i){
        pq.push(arr[i]);

        // If the priority queue size is greater than k, remove the largest element from the priority queue and add it to the result vector.
        if(pq.size() > k){
            res.push_back(pq.top());
            pq.pop();
        }
    }

    // Add the remaining elements in the priority queue to the result vector.
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }

    // Return the result vector.
    return res;
}


int main(){
    vector<int> arr = {3,2,1,5,6,4};
    int k = 2;
    vector<int> res = sortKSortedArray(arr, k);
    for(int& r : res){
        cout << r << " ";
    }
    return 0;
}