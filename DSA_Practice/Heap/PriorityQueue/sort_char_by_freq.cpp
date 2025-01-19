#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef pair<int,char> pr;
struct MyComparator {
    /**
     * This is a custom comparator for the priority queue. It is used to compare
     * two pairs of integers and characters. The first element of the pair is the
     * frequency of the character in the string, and the second element is the
     * character itself.
     *
     * The comparator first compares the frequencies of the characters. If the
     * frequencies are equal, it compares the characters themselves in
     * lexicographical order. If the characters are equal, it returns false.
     *
     * The reason for this comparison is that the priority queue is a max heap,
     * and we want the character with the highest frequency to be at the top of
     * the heap. If the frequencies are equal, we want the character that comes
     * first in lexicographical order to be at the top of the heap.
     */
    bool operator()(const pr& p1, const pr& p2) const{
        if(p1.first == p2.first){
            // If the frequencies are equal, compare the characters
            return p1.second < p2.second;
        }
        // If the frequencies are not equal, compare them
        return p1.first < p2.first;
    }
};

string sortByCharFrequency(string& s) {
    // Initialize an empty result string to store the characters sorted by frequency
    string res;

    // Create an unordered map to store the frequency of each character in the input string
    unordered_map<char, int> mp;

    // Create a max heap (priority queue) to store pairs of frequency and character,
    // using the custom comparator MyComparator to sort them
    priority_queue<pr, vector<pr>, MyComparator> max_heap;

    // Iterate over each character in the input string
    for (char& c : s) {
        // Increment the frequency of the character in the map
        mp[c]++;
    }

    // Iterate over the frequency map
    for (auto& m : mp) {
        // Push each character and its frequency as a pair into the max heap
        max_heap.push({m.second, m.first});
    }

    // While there are elements in the max heap
    while (!max_heap.empty()) {
        // Get the frequency of the character from the top of the heap
        int count = max_heap.top().first;
        
        // Get the character itself from the top of the heap
        int c = max_heap.top().second;

        // Remove the top element from the heap
        max_heap.pop();

        // Append the character 'count' number of times to the result string
        res += string(count, c);
    }

    // Return the result string with characters sorted by frequency
    return res;
}

int main(){
    string s;
    cin >> s ;
    string res = sortByCharFrequency(s);
    cout << res;
    return 0;
}