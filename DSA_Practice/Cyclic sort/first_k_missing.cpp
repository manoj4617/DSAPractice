#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void swap_num(int &x , int &y){
    int temp = x;
    x = y;
    y = temp;
}

/**
 * Finds the first k missing positive integers in a given array of numbers.
 * The function uses a cyclic sort algorithm to solve the problem.
 *
 * The function first initializes an index i to 0.
 * It then enters a while loop that continues until i is equal to n.
 * Inside the loop, it checks if the value at index i is greater than 0
 * and if the value at index i is less than or equal to n, and if the value
 * at index i is not equal to the value at index nums[i] - 1.
 * If all the conditions are true, then it swaps the value at index i with
 * the value at index nums[i] - 1.
 * If the conditions are false, then it increments the index i.
 *
 * After the while loop, the function enters a for loop that iterates over
 * the array from index 0 to n-1.
 * Inside the loop, it checks if the value at index i is not equal to i + 1.
 * If the condition is true, then it adds the value i + 1 to the result vector.
 * It also adds the value i + 1 to an unordered set seen.
 *
 * If the loop completes without finding k missing positive integers, then
 * the function enters a while loop that continues until the result vector
 * has k elements.
 * Inside the loop, it checks if the value nextMissing is not in the seen set.
 * If the condition is true, then it adds the value nextMissing to the result
 * vector.
 * It also adds the value nextMissing to the seen set.
 * Finally, it increments the value nextMissing.
 *
 * The function then returns the result vector.
 */
vector<int> FirstKMissing(vector<int>& nums, int k){
    int i = 0;
    int n = nums.size();

    while(i < n){
        int correctIndex = nums[i] - 1;
        if(nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIndex]){
            swap_num(nums[i], nums[correctIndex]);
        }
        else {
            i++;
        }
    }
    vector<int> res;
    unordered_set<int> seen;
    for(int i=0;i<n && res.size() < k; i++){
        if(nums[i] != i + 1){
           res.push_back(i + 1);
           seen.insert(i + 1);
        }
    }
    int nextMissing = n + 1;
    while(res.size() < k){
        if(seen.find(nextMissing) == seen.end()){
            res.push_back(nextMissing);
            seen.insert(nextMissing);
        }
        nextMissing++;
    }
    return res;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>  num(n);
    for(int i=0;i<n;++i){
        cin >> num[i];
    }
    vector<int> res = FirstKMissing(num, k);
    for(int& n : res){
        cout << n << " ";
    }
    return 0;
}