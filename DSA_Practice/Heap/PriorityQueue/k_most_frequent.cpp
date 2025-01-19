#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>


using namespace std;

class myComparator{
    public:
    int operator() (pair<int,int>& p1, pair<int,int>& p2){
        return (p1.second > p2.second);
    }
};

/**
 * This function takes a vector of integers called lists and an integer k.
 * It returns a vector of integers containing the k most frequent elements
 * from the lists vector. The function uses an unordered map to keep track
 * of the frequency of each element in the lists vector. Then it uses a priority
 * queue to keep track of the k most frequent elements. The priority queue is
 * sorted in descending order based on the frequency of each element. The function
 * then iterates through the unordered map and adds each element and its frequency
 * to the priority queue. If the priority queue size is greater than k, the function
 * removes the smallest element from the priority queue. Finally, the function
 * iterates through the priority queue and adds each element to a vector called res.
 * The function then returns the vector called res.
 *
 * @param lists The vector of integers containing the elements to find the most frequent
 * @param k The integer representing the number of most frequent elements to return
 * @return A vector of integers containing the k most frequent elements from the lists vector
 */
vector<int> TopKElements(vector<int> lists, int k){
    // Create an unordered map to keep track of the frequency of each element in the lists vector
    unordered_map<int, int> mp;

    // Iterate through the lists vector and increment the frequency of each element in the unordered map
    for(auto& n : lists){
        mp[n] = mp[n] + 1;
    }

    // Create a priority queue to keep track of the k most frequent elements
    priority_queue<pair<int,int>, vector<pair<int, int>>, myComparator> pq;

    // Iterate through the unordered map and add each element and its frequency to the priority queue
    for(auto it : mp){
        pq.push(make_pair(it.first, it.second));
        // If the priority queue size is greater than k, remove the smallest element from the priority queue
        if(pq.size() > k){
            pq.pop();
        }
    }

    // Create a vector to store the final result
    vector<int> res;

    // Iterate through the priority queue and add each element to the res vector
    while(pq.size() > 0){
        res.push_back(pq.top().first);
        pq.pop();
    }

    // Return the final result vector
    return res;
}

int main(){

    int k,n;
    cin >> n >> k;

    vector<int> lists(n);
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        lists.push_back(t);
    }

    vector<int> res = TopKElements(lists, k);

    for(auto& n : res){
        cout << n << " ";
    }

    return 0;
}