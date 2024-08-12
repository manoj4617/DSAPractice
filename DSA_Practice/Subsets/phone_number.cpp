#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;




/**
 * This function is a backtracking algorithm that generates all possible
 * combinations of letters based on a given string of digits.
 *
 * @param index The current index being processed in the digits string.
 * @param path The current combination of letters being generated.
 * @param digits The string of digits to generate combinations from.
 * @param letters A map of characters to vectors of corresponding letters.
 * @param combinations The vector to store the generated combinations.
 */
void Backtrack(int index,  // The current index in the digits string
               vector<char>& path,  // The current combination of letters
               const string& digits,  // The digits string to generate combinations from
               unordered_map<char, vector<string>>& letters,  // A map of characters to vectors of corresponding letters
               vector<string>& combinations)  // The vector to store the generated combinations
{
    // Base case: when all characters have been processed, add the current combination to the results vector.
    if (path.size() == digits.size()) {
        // Convert the current combination of letters to a string and add it to the results vector.
        string combination(path.begin(), path.end());
        combinations.push_back(combination);
        return;
    }

    // Get the current digit from the digits string.
    char currentDigit = digits[index];

    // Get the possible letters for the current digit from the letters map.
    vector<string>& possibleLetters = letters[currentDigit];

    // For each possible letter, add it to the current combination, recurse with the next index, and then remove the letter from the current combination.
    for (const string& letter : possibleLetters) {
        path.push_back(letter[0]);  // Add the current letter to the current combination
        Backtrack(index + 1, path, digits, letters, combinations);  // Recurse with the next index
        path.pop_back();  // Remove the current letter from the current combination
    }
}

/**
 * This function generates all possible combinations of letters based on a given string of digits.
 *
 * @param digits The string of digits to generate combinations from.
 * @return A vector of strings containing all possible combinations of letters.
 */
vector<string> LetterCombination(string digits){
    // Initialize an empty vector to store the combinations.
    vector<string> combinations;

    // If the digits string is empty, return the empty vector.
    if(digits.empty()){
        return combinations;
    }

    // Define a map that associates each digit with its corresponding letters.
    unordered_map<char, vector<string>> mp = {
        {'1',{""}}, // Digit 1 corresponds to no letter.
        {'2', {"a","b","c"}}, // Digit 2 corresponds to letters a, b, and c.
        {'3', {"d","e","f"}}, // Digit 3 corresponds to letters d, e, and f.
        {'4', {"g","h","i"}}, // Digit 4 corresponds to letters g, h, and i.
        {'5', {"j","k","l"}}, // Digit 5 corresponds to letters j, k, and l.
        {'6', {"m","n","o"}}, // Digit 6 corresponds to letters m, n, and o.
        {'7', {"p","q","r","s"}}, // Digit 7 corresponds to letters p, q, r, and s.
        {'8', {"t","u","v"}}, // Digit 8 corresponds to letters t, u, and v.
        {'9', {"w","x","y","z"}} // Digit 9 corresponds to letters w, x, y, and z.
    };

    // Initialize an empty vector to store the current combination of letters.
    vector<char> path;

    // Call the Backtrack function to generate all possible combinations of letters.
    Backtrack(0,path,digits,mp,combinations);

    // Return the vector of combinations.
    return combinations;
}

void PrintList(vector<string> combinations){
    for(auto& com : combinations){
        cout << "\t" << com << endl;
    }
    cout << endl;
}

int main(){
    std::vector<std::string> digitsArray = {"23", "73", "426", "78", "925", "2345"};
    int counter = 1;
    for (int digits=0; digits < digitsArray.size(); digits++){
        std::cout<<counter<< ".\t All letter combinations for '"<< digitsArray[digits]<< "': " << endl;
        PrintList(LetterCombination(digitsArray[digits]));
        counter++;
        std::cout<<std::string(100,'-')<<std::endl;
    }
    return 0;
}