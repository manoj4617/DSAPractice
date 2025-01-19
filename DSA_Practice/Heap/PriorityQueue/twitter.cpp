#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;
class Twitter {
private:
    int count;
    unordered_map<int, set<int>> followMap;
    unordered_map<int, vector<vector<int>>> tweetMap;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Custom comparator for the priority queue to sort tweets by timestamp in descending order.
        /*
        compares the timestamp (a[0] and b[0]) of the two elements. It says:

            If a[0] < b[0], then b is more recent than a, so b should be higher in the heap.
            If a[0] >= b[0], then a is more recent or equally recent, so a should stay higher.
            This creates a max-heap for timestamps because larger timestamps are given priority.

            Example:
                {4, 301, 3, 0}   // timestamp 4
                {3, 202, 2, 1}   // timestamp 3
                {2, 102, 1, 1}   // timestamp 2

                Comparator compares {4, 301, 3, 0} and {3, 202, 2, 1}:
                    a = {4, 301, 3, 0}, b = {3, 202, 2, 1}
                    a[0] = 4, b[0] = 3
                    4 < 3 is false. So {4, 301, 3, 0} stays higher in the heap.

                Comparator compares {3, 202, 2, 1} and {2, 102, 1, 1}:
                    a = {3, 202, 2, 1}, b = {2, 102, 1, 1}
                    a[0] = 3, b[0] = 2
                    3 < 2 is false. So {3, 202, 2, 1} stays higher than {2, 102, 1, 1}.
 
                [{4, 301, 3, 0}, {3, 202, 2, 1}, {2, 102, 1, 1}] // max-heap
        */
        auto compare = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        };

        // Priority queue (min-heap) to store tweets with the most recent timestamp at the top.
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);
        
        // Result vector to store the IDs of the 10 most recent tweets.
        vector<int> res;
        
        // Add the user to their own follow list to include their tweets.
        followMap[userId].insert(userId);

        // Iterate over each followee of the user.
        for(auto& followee : followMap[userId]){
            // Check if the followee has any tweets.
            if(tweetMap.count(followee)){
                // Get the list of tweets for the followee.
                const vector<vector<int>> tweets = tweetMap[followee];
                
                // Get the index of the most recent tweet for the followee.
                int index = tweets.size() - 1;
                
                // Push the most recent tweet onto the priority queue.
                // The vector includes the timestamp, tweetId, followeeId, and index.
                minHeap.push({tweets[index][0], tweets[index][1], followee, index});
            }
        }

        // Get up to 10 most recent tweets by repeatedly extracting from the priority queue.
        while(!minHeap.empty() && res.size() < 10){
            // Extract the tweet with the most recent timestamp.
            vector<int> cur = minHeap.top();
            minHeap.pop();
            
            // Add the tweetId to the result list.
            res.push_back(cur[1]);
            
            // Get the index of the next most recent tweet for the followee.
            int index = cur[3];
            
            // If there are more tweets from this followee, push the next one onto the queue.
            if(index > 0){
                const vector<int> tweet = tweetMap[cur[2]][index-1];
                minHeap.push({tweet[0], tweet[1], cur[2], index - 1});
            }
        }
        
        // Return the list of tweet IDs.
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


int main(){
    Twitter* obj = new Twitter();
    obj->postTweet(1, 5);
    vector<int> param_2 = obj->getNewsFeed(1);
    obj->follow(1, 2);
    obj->postTweet(2, 6);
    param_2 = obj->getNewsFeed(1);
    obj->unfollow(1, 2);
    param_2 = obj->getNewsFeed(1);

    vector<int> res = obj->getNewsFeed(1);
    for(int& r : res){
        cout << r << " ";
    }

    return 0;
}