#include<iostream>
#include<vector>
#include<deque>

using namespace std;

vector<int> max_in_window(int num[], int n, int w) {
    // res stores the result
    vector<int> res;

    // deque q is used to store indices of num[]
    // that form the maximum subarray of size w
    deque<int> q;

    // For the first window of size w, find the maximum
    // element in it and store its index in the queue q
    for(int i=0; i<w; ++i) {
        // Keep removing elements from rear of q while
        // they are smaller than num[i]
        while(!q.empty() && num[i] > num[q.back()]) {
            q.pop_back();
        }

        // Add num[i]'s index to q
        q.push_back(i);
    }

    // At this point, q contains indices of all elements
    // of the initial window of size w, and the largest
    // element is at q.front()
    res.push_back(num[q.front()]);

    // For remaining windows of size w, find the maximum
    // element in them, remove the element that is out
    // of the window and add the new element to the queue
    for(int i=w; i<n; ++i) {
        // Remove the elements from rear of q that are
        // out of this window. Note that q is sorted in
        // decreasing order, so we only need to remove
        // elements greater than or equal to i-w+1
        while(!q.empty() && num[i] > num[q.back()]) {
            q.pop_back();
        }

        // If removing elements from q made it empty, then
        // the previous q.front() is not in this window.
        // We need to remove it. 
        if(!q.empty() && q.front() <= i-w) {
            q.pop_front();
        }

        // Add the new element from num[] at index i to q
        q.push_back(i);

        // Store the maximum element in this window in
        // the result vector
        res.push_back(num[q.front()]);
    }
    return res;
}

int main(){
    int n,w;
    cin >> n >> w;
    int nums[n];
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }

    vector<int> res = max_in_window(nums,n,w);
    for(int i=0;i<res.size();++i){
        cout<<res[i]<<" ";
    }
    return 0;
}