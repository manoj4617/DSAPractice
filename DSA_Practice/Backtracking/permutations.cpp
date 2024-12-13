#include <iostream>
#include <vector>

using namespace std;

string swap_char(string str, int i, int j){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;

    return str;
}

/**
 * This function generates all possible permutations of a given string.
 * 
 * @param str The string for which permutations are to be generated.
 * @param currentIdx The current index of the string being processed.
 * @param res The vector to store the generated permutations.
 */
void PermutateStr(string str, int currentIdx, vector<string>& res){
    // Base case: when all characters have been processed, add the current string to the result vector.
    if(currentIdx == (str.size() - 1)){
        res.emplace_back(str);
        return;
    }
    
    // For each character starting from the current index, swap it with the current character.
    // Recursively call the function for the swapped string and the next index.
    for(int i=currentIdx; i < str.size(); ++i){
        // Swap the current character with the character at index i.
        string swapped = swap_char(str, currentIdx, i);
        
        // Recursively call the function for the swapped string and the next index.
        PermutateStr(swapped, currentIdx + 1, res);
    }
}

vector<string> Permutate(string str){
    vector<string> res;
    PermutateStr(str, 0, res);
    return res;
}

int main(){

    string str;
    cin >> str;
    vector<string> res = Permutate(str);

    for(auto& s : res){
        cout << s << endl;
    }
    return 0;
}
