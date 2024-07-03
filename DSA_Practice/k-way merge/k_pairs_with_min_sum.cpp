#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


// This function takes in two lists of integers and an integer k. It returns a vector of vectors of integers
// where each inner vector contains two integers from the original lists such that their sum is one of the k smallest
// sums. The function uses a priority queue to keep track of the smallest sums. The priority queue is sorted in
// descending order based on the sum of the two integers from the original lists.
vector<vector<int>> KSmallestPairs(vector<int>& list1, vector<int>& list2, int k){

    // Create a priority queue to store pairs of integers from the original lists and their sum. The priority queue
    // is sorted in descending order based on the sum of the two integers from the original lists.
    priority_queue<
        pair<int, pair<int,int>>, // The priority queue will store pairs of integers and their sum.
        vector<pair<int, pair<int,int>>>, // The priority queue will be implemented using a vector.
        greater<pair<int,pair<int,int>>>> pq; // The priority queue will be sorted in descending order.

    // Create a vector to store the final result.
    vector<vector<int>> res;

    // Calculate the length of the smaller list.
    int listLength = min(list1.size(), list2.size());

    // Initialize the priority queue with the first k elements from the smaller list.
    for(int i=0;i < min(k , listLength);i++){
        pq.push({list1[i] + list2[0], {i , 0}});
    }

    // Initialize a counter to keep track of the number of elements added to the result vector.
    int count = 0;

    // While there are still elements in the priority queue and the counter is less than k,
    // remove the smallest element from the priority queue and add it to the result vector.
    while(pq.size() > 0 && count <= k){

        // Get the smallest element from the priority queue.
        int sum = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        // Remove the smallest element from the priority queue.
        pq.pop();

        // Add the smallest element to the result vector.
        res.push_back({list1[i], list2[j]});

        // Calculate the index of the next element in the smaller list.
        int nextElement = j + 1;

        // If the next element exists, add it to the priority queue.
        if(nextElement < list2.size()){
            pq.push({list1[i] + list2[nextElement], {i , nextElement}});
        }

        // Increment the counter.
        count++;
    }

    // Return the result vector.
    return res;
}


int main(){
    int i , j;
    cin >> i >> j;
    vector<int> list1;
    vector<int> list2;

    for(int k=0;k<i;k++){
        int x;
        cin >> x;
        list1.push_back(x);
    }

    for(int k=0;k<j;k++){
        int x;
        cin >> x;
        list2.push_back(x);
    }

    for(int k=0;k<list1.size();k++){
        cout << list1[k] << " ";
    }

    cout << endl;

    for(int k=0;k<list2.size();k++){
        cout << list2[k] << " ";
    }

    int k;
    cin >> k;

    vector<vector<int>> res = KSmallestPairs(list1, list2, k);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}