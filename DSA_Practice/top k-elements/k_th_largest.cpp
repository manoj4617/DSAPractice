#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * This function takes in a vector of integers and an integer k, and returns the kth largest element in the vector.
 * The function uses a priority queue to keep track of the largest elements.
 * The priority queue is sorted in descending order based on the integer values.
 *
 * Parameter(s):
 * list: A vector of integers representing a list of numbers.
 * k: An integer representing the kth largest element to be found.
 *
 * Return:
 * An integer representing the kth largest element in the vector.
 */
int kthLargest(vector<int> list, int k){
    
    // Declare a priority queue to store the largest elements.
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // Loop through the first k elements of the list and add them to the priority queue.
    for(int i=0;i<k;++i){
        pq.push(list[i]);
    }
    
    // Loop through the remaining elements of the list.
    for(int i=k;i<list.size();++i){
        
        // If the current element is larger than the top element of the priority queue,
        // remove the top element from the priority queue and add the current element.
        if(list[i] > pq.top()){
            pq.pop();
            pq.push(list[i]);
        }
    }
    
    // Return the top element of the priority queue, which is the kth largest element in the vector.
    return pq.top();
}

int main(){

    int k , n;
    cin >> n >> k;

    vector<int> list(n);

    for(int i=0;i<n;++i){
        cin >> list[i];
    }

    cout << kthLargest(list,k);
    return 0;
}