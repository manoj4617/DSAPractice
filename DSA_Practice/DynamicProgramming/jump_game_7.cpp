#include <iostream>
#include <queue>


using namespace std;

bool canReach(string s, int minJump, int maxJump) {
/**
 * This function takes a string and two integers (minJump and maxJump) as input.
 * The string represents a sequence of 0s and 1s, where 0 means a "good" index
 * and 1 means a "bad" index. The two integers represent the minimum and maximum
 * number of steps that can be taken to jump from one good index to another.
 *
 * The function returns true if it is possible to reach the last index of the string
 * by starting from the first index and jumping between good indices within the
 * given range of jumps. Otherwise, it returns false.
 */
    if(s[0] == '1' || s[s.length() - 1] == '1'){
    // If the first or last index is a bad index, return false
        return false;
    }
    queue<int> q;

    // Initialize a queue to keep track of the indices to visit
    q.push(0);
    int far = 0;

    // Initialize the farthest index we've visited so far
    int n = s.length();

    // Initialize the length of the string
    while(!q.empty()){

    // Loop until the queue is empty
        int cur = q.front();
        // Get the current index from the queue
        q.pop();
        if(cur == n-1) return true;

        // If we've reached the last index, return true
        int start = max(cur + minJump, far + 1);

        // Calculate the start and end indices to visit
        int end = min(n-1, cur + maxJump);
        for(int i = start; i <= end; ++i){

        // Loop through the indices to visit
            if(s[i] == '0'){
            // If the index is a good index, add it to the queue
                q.push(i);
            }
        }
        far = cur + maxJump;

        // Update the farthest index we've visited so far
    }
    return false;

    // If we've finished visiting all the indices and haven't reached the last
    // index, return false
}

int main(){
    string s = "011010";
    int minJump = 2, maxJump = 3;
    cout << "Min jumps: " << canReach(s, minJump, maxJump);
    return 0;
}