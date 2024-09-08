#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest{
    public:
    KthLargest(int k , vector<int>& nums){
        this->m_k = k;
        this->m_nums = nums;
        pq = priority_queue<int, vector<int>, greater<int>>();
        for(int i = 0; i < nums.size(); i++){
            int small = Add(nums[i]);
        }
    }

    /**
     * This function adds a new value to the priority queue if it is smaller than the current
     * kth largest value in the queue. If the queue is already full, it checks if the new value
     * is smaller than the current kth largest value. If it is, it removes the current kth largest
     * value from the queue and adds the new value to the queue.
     * 
     * @param val The value to be added to the queue.
     * @return The value of the current kth largest element in the queue.
     */
    int Add(int val){
        // Check if the queue is not full.
        if(pq.size() < m_k){
            // If the queue is not full, add the new value to the queue.
            pq.push(val);
        }
        else{
            // If the queue is full, check if the new value is smaller than the current kth largest value.
            if(pq.top() < val){
                // If the new value is smaller than the current kth largest value, remove the current kth largest value from the queue.
                pq.pop();
                // Add the new value to the queue.
                pq.push(val);
            }
        } 

        // Return the value of the current kth largest element in the queue.
        return pq.top();
    }

    private:
    vector<int> m_nums;
    int m_k;
    priority_queue<int, vector<int>, greater<int>> pq;

};

void printLargest(int large)
{
    cout << large << endl;
}
int main(){


    int k,n;
    cin >> k >> n;
    int val;

    vector<int> nums;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        nums.push_back(t);
    }

    KthLargest* obj = new KthLargest(k, nums);
    cin >> val;
    printLargest(obj->Add(val));
    return 0;
}