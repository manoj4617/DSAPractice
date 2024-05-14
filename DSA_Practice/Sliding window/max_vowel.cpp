#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u'){
                return true;
            }
            else{
                return false;
            }
}
// Function to find the maximum number of vowels in a window of size k.
// Time Complexity: O(n)
// Auxiliary Space: O(1)

int maxVowels(string s, int k) {
    
    // Initialize the count of vowels in the current window
    int maxVowelCount = 0;
    
    // Initialize the start and end indices of the window
    int start = 0, end = k;
    
    // Initialize the maximum number of vowels in the window
    int maxC = 0;
    
    // Loop through the characters in the string
    while(end < s.length()){
        
        // If the current character is a vowel, increment the count
        if(isVowel(s[end])){
            maxVowelCount++;
        }
        
        // If the character at the start index is a vowel, decrement the count
        if(isVowel(s[start])){
            maxVowelCount--;
        }
        
        // Update the maximum number of vowels in the window
        maxC = max(maxVowelCount, maxC);
        
        // Advance the start and end indices by 1
        start++;
        end++;
    }
    
    // Return the maximum number of vowels in the window
    return maxC;
}

int main() {
    
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << maxVowels(s, k) << endl;
    
    return 0;
}