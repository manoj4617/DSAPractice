#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/**
 * This function uses backtracking to generate all possible combinations of
 * balanced brackets. A balanced bracket is a sequence of brackets that open
 * and close in the correct order. For example, "()(())" is a balanced bracket,
 * while "()()()(" is not.
 *
 * The function takes an integer parameter "n" which represents the number of
 * opening brackets to generate.
 *
 * The function uses recursion to generate all possible combinations of brackets.
 * It starts with an empty string and two counters, "opening" and "closing", both
 * initialized to 0.
 *
 * The function then calls the "Backtrack" function with the current state of
 * the counters and the empty string.
 *
 * The "Backtrack" function takes several parameters:
 *   - "n" is the total number of opening brackets to generate.
 *   - "opening" is the current number of opening brackets that have been added
 *     to the string.
 *   - "closing" is the current number of closing brackets that have been added
 *     to the string.
 *   - "combinations" is a vector of strings that will store all the generated
 *     combinations.
 *   - "path" is the current combination of brackets as a string.
 *
 * The "Backtrack" function uses recursion to generate all possible combinations
 * of brackets. It starts by checking if the current combination of brackets is
 * balanced. If it is, it adds the combination to the "combinations" vector.
 *
 * If the current number of opening brackets is less than the total number of
 * brackets to generate, the function adds an opening bracket to the current
 * combination and recurses with the updated counters.
 *
 * If the current number of opening brackets is greater than the number of closing
 * brackets, the function adds a closing bracket to the current combination and
 * recurses with the updated counters.
 *
 * The function then returns, and the "Backtrack" function backtracks by removing
 * the last added bracket from the current combination and decrementing the
 * appropriate counter. This process continues until all possible combinations
 * of balanced brackets have been generated.
 *
 * The generated combinations are then printed to the console.
 */

void Backtrack(int n, int opening , int closing, vector<string>& combinations, string path){
    if(opening == n && closing == n){
        combinations.push_back(path);
        return;
    }

    if(opening < n){
        Backtrack(n, opening + 1, closing, combinations, path + '(');
    }
    if(opening > closing){
        Backtrack(n, opening, closing + 1, combinations, path + ')');
    }
}

void GenerateBrackets(int n){
    vector<string> combinations;
    string path;
    int opening = 0;
    int closing = 0;

    Backtrack(n, opening, closing, combinations, path);
    for(auto &c : combinations){
        cout << c << endl;
    }

}

int main(){
    int n;
    cin >> n;
    GenerateBrackets(n);
    return 0;
}