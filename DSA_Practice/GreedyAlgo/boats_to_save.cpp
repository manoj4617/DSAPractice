#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * This function takes a vector of people's weights and a weight limit for boats.
 * It then returns the minimum number of boats needed to save all the people.
 *
 * The algorithm works by first sorting the people by their weights in ascending order.
 * Then, it uses two pointers, one at the beginning of the array (l) and one at the end (r),
 * to greedily assign people to boats. If the person at the beginning and the person at the end
 * can both fit on the same boat, they are assigned to the same boat and the pointers are moved.
 * If not, the person at the end is assigned to a new boat and the pointer is moved down.
 * The total number of boats used is the number of iterations of the while loop.
 */
int RescueBoats(vector<int>& people, int limit){
    int boats = 0;
    // Sort the people by weight in ascending order
    sort(people.begin(), people.end());
    // Initialize two pointers, one at the beginning and one at the end
    int l = 0, r = people.size() - 1;

    // Iterate through the people, assigning them to boats
    while(l <= r){
        // If the person at the beginning and the person at the end can both fit on the same boat,
        // assign them to the same boat and move the pointers
        if(people[l] + people[r] <= limit){
            boats++;
            l++;
            r--;
        }
        // If not, assign the person at the end to a new boat and move the pointer down
        else{
            r--;
            boats++;
        }
    }
    return boats;
}

int main(){
    int n, limit;
    cin >> n >> limit;
    vector<int> nums;
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    cout << RescueBoats(nums,limit);
    return 0;
}