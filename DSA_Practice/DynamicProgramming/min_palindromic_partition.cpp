#include <iostream>

using namespace std;

bool isPlindrome(string s, int i , int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
}


/**
 * This function takes a string s and two indices i and j and returns the
 * minimum number of cuts required to partition the substring s[i..j] into
 * palindromic substrings.
 *
 * The function uses a recursive approach to solve the problem. The base case
 * is when i >= j, in which case there is only one substring, so the number of
 * cuts required is 0.
 *
 * If the substring s[i..j] is a palindrome, then the number of cuts required is
 * 0.
 *
 * Otherwise, the function iterates over each possible split point from i to
 * j-1, and for each split point, it recursively calls itself to compute the
 * minimum number of cuts required to partition the substrings s[i..k] and
 * s[k+1..j] into palindromic substrings. The function then adds 1 to the sum
 * of the two results and assigns the minimum of this sum and the current answer
 * to the answer.
 *
 * Finally, the function returns the minimum number of cuts required to
 * partition the substring s[i..j] into palindromic substrings.
 */
int MCM(string& s, int i, int j){
    if(i >= j){
        return 0;
    }
    if(isPlindrome(s,i,j)){
        return 0;
    }
    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = MCM(s, i, k) + MCM(s, k + 1, j) + 1;
        ans = min(ans, temp);
    }
    return ans;
}
int minCut(string s) {
   
    return MCM(s, 0 , s.size() - 1);
}

int main(){
    string s;
    cin >> s;
    cout << minCut(s);
    return 0;
}