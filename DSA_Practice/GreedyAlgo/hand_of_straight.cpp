#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * This function takes a vector of integers and an integer groupSize, and returns
 * a boolean indicating whether the vector can be divided into groups of size
 * groupSize such that each group contains consecutive integers.
 *
 * The function first checks if the vector size is divisible by groupSize. If
 * not, it returns false.
 *
 * The function then creates an unordered_map to keep track of the count of each
 * integer in the vector.
 *
 * The function then iterates over the vector and for each element, it finds the
 * starting element of the group by decrementing the element until it finds an
 * element that has not been used yet.
 *
 * The function then iterates over the elements in the group and decrements the
 * count of each element in the unordered_map. If the count of any element goes
 * to 0 before the group is complete, the function returns false.
 *
 * If the function completes the loop without returning false, it returns true.
 */
bool isNStraightHand(vector<int>& hand, int groupSize){
    if(hand.size() % groupSize != 0){
        return false;
    }

    unordered_map<int, int> mp;
    for(int val : hand){
        mp[val]++;
    }

    for(int val : hand){
        int start = val;
        // Find the starting element of the group
        while(mp[start - 1] > 0) start--;
        // Iterate over the elements in the group
        while(start <= val){
            // If the count of any element goes to 0 before the group is complete
            // return false
            while(mp[start] > 0){
                for(int i=start; i < start + groupSize; i++){
                    if(mp[i] == 0) return false;
                    mp[i]--;
                }
            }
            start++;
        }
    }
    return true;
}

int main(){

    vector<int> hand = {1,2,4,2,3,5,3,4};
    int gs = 4;
    cout << isNStraightHand(hand, gs)  << endl;
    hand.clear();
    hand = {1,2,3,3,4,5,6,7};
    gs = 4;
    cout << isNStraightHand(hand, gs);
    return 0;
}