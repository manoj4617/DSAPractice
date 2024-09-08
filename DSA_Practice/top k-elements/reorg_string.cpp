#include <unordered_map>
#include <string>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

class mycomparator
{
    public:
    int operator() (pair<int, char>& pq, pair<int, char>& pq1){
        return pq.first > pq1.first;
    }
};

/**
 * Reorganize the string in such a way that the character which appears least
 * number of times is placed first, followed by the character which appears
 * second least number of times and so on. The string must be returned in this
 * order.
 *
 * @param str The input string.
 * @return The reorganized string.
 */
string ReorganizeString(string str){
    // Initialize the map to keep track of the frequency of each character
    unordered_map<char, int> mp;

    // Initialize the result string and the previous character
    string str_res = "";
    pair<int, char> prev = {'\0', ' '};

    // Store the frequency of each character in the priority queue
    for(auto ch: str){
        mp[ch]++;
    }

    // Create the priority queue and push the characters and their frequency into it
    priority_queue<pair<int, char>, vector<pair<int, char>>, mycomparator> pq;
    for(auto it = mp.begin(); it != mp.end(); it++){
        pq.push(make_pair(-it->second, it->first));
    }

    // While there are still characters left in the priority queue or the previous character is not '\0'
    while(pq.size() > 0 || prev.first != '\0'){
        // If the previous character is not '\0' and the priority queue is empty, it means we couldn't reorganize the string
        if(prev.first != '\0' && pq.size() == 0){
            return "";
        }

        // Get the character with the least frequency and pop it from the priority queue
        pair<int, char> t = pq.top();
        pq.pop();

        // Append the character to the result string
        str_res = str_res + t.second;

        // Decrease the frequency of the character
        t.first += 1;

        // If the previous character is not '\0', push it back into the priority queue
        if(prev.first != '\0'){
            pq.push(prev);
            prev = make_pair('\0', ' ');
        }

        // If the frequency of the character is not 0, push it back into the priority queue with the updated frequency
        if(t.first != 0){
            prev = make_pair(t.first, t.second);
        }
    }

    return str_res;
}

int main(){

    string str;
    getline(cin, str);
    cout << ReorganizeString(str);
    return 0;
}
