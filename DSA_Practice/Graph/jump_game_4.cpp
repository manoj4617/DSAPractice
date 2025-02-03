#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;


/**
 * This function takes a vector of integers as an argument and returns the
 * minimum number of jumps needed to reach the last index from the first index.
 * A jump is defined as either moving one step forward or backward, or moving
 * to any index that has the same value as the current index.
 *
 * The function starts by adding the first index to a queue and marking it as
 * visited. It then enters a loop that continues until the queue is empty.
 *
 * In each iteration of the loop, the function dequeues all elements from the
 * queue, and for each element, it checks all of its neighbors (i.e., the
 * indices that can be reached by either moving one step forward or backward
 * or by moving to an index with the same value). If a neighbor is not visited
 * before, it is added to the queue and marked as visited.
 *
 * The function also keeps track of the number of steps taken so far, and
 * returns this number once the last index is reached.
 */
int minJumps(vector<int>& nums){
    if(nums.size() == 1) return 0;

    int n = nums.size(), steps = 0;
    unordered_map<int, list<int>> mp;
    queue<int> q;
    vector<bool> visit(n, false);

    // Create a map that maps each value to a list of indices that have that value
    for(int i=0;i<n;++i){
        mp[nums[i]].push_back(i);
    }

    // Initialize a queue to keep track of the indices to visit
    q.push(0);
    visit[0] = true;

    while(!q.empty()){
        int len = q.size();
        for(int i=0;i<len;++i){
            int cur = q.front();
            q.pop();
            if(cur == n - 1) return steps;
            // Check all neighbors of the current index
            for(int node : mp[nums[cur]]){
                if(!visit[node]){
                    // If the neighbor is not visited before, add it to the queue and mark it as visited
                    q.push(node);
                    visit[node] = true;
                }
            }

            // Clear the list of indices that have the same value as the current index
            mp[nums[cur]].clear();

            // Check if the next index can be reached by moving one step forward
            if(cur + 1 < n && !visit[cur + 1]){
                q.push(cur + 1);
                visit[cur + 1] = true;
            }

            // Check if the previous index can be reached by moving one step backward
            if(cur - 1 >= 0 && !visit[cur - 1]){
                q.push(cur - 1);
                visit[cur - 1] = true;
            }
        }
        steps++; // Increment the number of steps taken so far
    }
    return steps;
}


int main(){

    vector<int> nums = {100,-23,-23,404,100,23,23,23,3,404};
    cout << "Min jumps: " << minJumps(nums) << endl;
    nums.clear();
    nums = {7};
    cout << "Min jumps: " << minJumps(nums) << endl;
    nums.clear();
    nums = {7,6,9,6,9,6,9,7};
    cout << "Min jumps: " << minJumps(nums) << endl;


    return 0;
}