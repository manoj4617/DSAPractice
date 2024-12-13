#include <iostream>
#include <queue>
#include <vector>


using namespace std;

typedef pair<int,int> pr;

/**
 * This function takes a vector of integers and two integers k and x as parameters.
 * It returns a vector of k integers which are closest to x.
 * The function uses a priority queue to store the k closest elements to x.
 * The priority queue is a max heap, so the largest element is always at the top.
 * The function then loops through the vector and adds each element to the priority queue.
 * If the size of the priority queue exceeds k, the function removes the largest element from the priority queue.
 * Finally, the function loops through the priority queue and adds each element to the result vector.
 * The function then returns the result vector.
 */
vector<int> kclosest(vector<int>& arr, int k, int x){
    // Declare a priority queue to store the k closest elements to x.
    // The priority queue is a max heap, so the largest element is always at the top.
    priority_queue<pr, vector<pr>, less<pr>> max_heap;

    // Get the size of the vector.
    int len = arr.size();

    // Declare a vector to store the result.
    vector<int> res;

    // Loop through the vector and add each element to the priority queue.
    for(int i=0;i<len;++i){ 
        // Calculate the absolute difference between the current element and x.
        int diff = abs(arr[i] - x);

        // Add the element to the priority queue.
        max_heap.push({diff, arr[i]});

        // If the size of the priority queue exceeds k, remove the largest element from the priority queue.
        if(max_heap.size() > k){
            max_heap.pop();
        }
    }

    // Loop through the priority queue and add each element to the result vector.
    while(!max_heap.empty()){
        // Get the element at the top of the priority queue.
        pr temp = max_heap.top();

        // Add the element to the result vector.
        res.push_back(temp.second);

        // Remove the element from the priority queue.
        max_heap.pop();
    }

    // Return the result vector.
    return res;
}

int main(){
    vector<int> arr;
    int n, k, x;
    cout << "Enter number of elements  (n), kth element and x\n";
    cin >> n >> k >> x;
    for(int i=0;i<n;++i){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    vector<int> res = kclosest(arr, k , x);
    for(int& i : res){
        cout << i << " ";
    }

    return 0;
}