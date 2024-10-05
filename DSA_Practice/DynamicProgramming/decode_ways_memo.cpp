#include <iostream>
#include <vector>

using namespace std;

/**
 * This function is the recursive helper function for the Decode function.
 * It takes a string of digits, s, and an index into that string, i, as
 * input, and returns the number of ways to decode the string from the
 * given index to the end of the string. The function uses memoization to
 * store the results of subproblems and reuse them to avoid redundant
 * computation.
 *
 * The function first checks if the index is at the end of the string. If
 * it is, then there is only one way to decode the string from the given
 * index to the end of the string, which is to decode the current
 * character as a single digit. So the function returns 1.
 *
 * The function then checks if the current character is '0'. If it is, then
 * there is no way to decode the string from the current index to the end
 * of the string, since a '0' cannot be decoded on its own. So the function
 * returns 0.
 *
 * The function then checks if the subproblem has already been solved by
 * checking if the element at memo[i] is not -1. If it is not -1, the
 * function returns the value at memo[i] directly.
 *
 * If the subproblem has not been solved yet, the function uses two
 * recursive calls to compute the number of ways to decode the string from
 * the current index to the end of the string. The first recursive call
 * decodes the current character as a single digit and recursively calls
 * itself to compute the number of ways to decode the string from the next
 * index to the end of the string. The second recursive call decodes the
 * current character and the next character as a single two-digit number
 * and recursively calls itself to compute the number of ways to decode the
 * string from the index after the next index to the end of the string. The
 * function then adds the two results together and assigns the sum to the
 * answer.
 *
 * Finally, the function stores the answer in memo[i] and returns it.
 */
int BacktrackMemo(string& s, int i,vector<int>& memo){
    if(i == s.size()){ // base case: if index is at end of string
        return 1; // only one way to decode the string from the end of the
                  // string to the end of the string
    }
    if(s[i] == '0'){ // base case: if current character is '0'
        return 0; // no way to decode the string from the current index to the
                  // end of the string
    }
    if(memo[i] != -1){ // if subproblem has already been solved
        return memo[i]; // return the result directly
    }
    int count = 0;
    if(s[i] != '0'){ // decode current character as single digit
        count += BacktrackMemo(s,i+1,memo); // recursively call self to decode
                                            // string from next index to end of
                                            // string
    }
    if((s.size() - i >= 2) && (s[i] != '0')){ // decode current character and
                                               // next character as single two-
                                               // digit number
        int n = atoi(s.substr(i,2).c_str());
        if(n <= 26){ // if two-digit number is between 1 and 26
            count += BacktrackMemo(s, i + 2, memo); // recursively call self to
                                                    // decode string from index
                                                    // after next index to end of
                                                    // string
        }
    }
    memo[i] = count; // store result in memoization table
    return count;
}

int Decode(string& s){
    vector<int> memo(s.size(), -1);
    return BacktrackMemo(s, 0, memo);
}

int main(){
    string s;
    cin >> s;
    cout << Decode(s);
    return 0;
}