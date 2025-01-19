#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int timeInterval(vector<char>& tasks, int n){
    // We need to get the count of each task.
    // This vector will store the count of each task.
    vector<int> count(26,0);
    for(char task : tasks){
        // For each task, increment the count of that task in the vector.
        count[task - 'A']++;
    }

    // We need a max heap to get the most frequent task.
    // A priority queue is a natural fit for this.
    priority_queue<int> maxHeap;
    for(int i : count){
        // Push each count to the max heap.
        if(i > 0){
            cout << i << endl;
            maxHeap.push(i);
        }
    }

    int time = 0;
    // We need a queue to keep track of the tasks that need to be inserted
    // back into the max heap.
    queue<pair<int,int>> q;

    // Continue until all tasks are processed.
    while(!q.empty() || !maxHeap.empty()){
        // Increment time.
        time++;

        // If the max heap is empty and the queue is not empty,
        // it means that all tasks have been processed and we need to
        // insert the tasks back into the max heap.
        if(maxHeap.empty()){
            // Set time to the time of the task that needs to be inserted
            // back into the max heap.
            time = q.front().second;
        }
        else{
            // Get the most frequent task from the max heap
            int rem = maxHeap.top() - 1;
            maxHeap.pop();
            if(rem > 0){
                // Insert the task back into the queue with the new time
                q.push({rem, time + n});
            }
        }

        // If the queue is not empty and the time is equal to the time of
        // the task at the front of the queue, it means that that task
        // needs to be inserted back into the max heap.
        if(!q.empty() && time == q.front().second){
            maxHeap.push(q.front().first);
            q.pop();
        }
    }
    return time;
}

int main(){
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << "MaxTime: " << timeInterval(tasks, n);
    return 0;
}