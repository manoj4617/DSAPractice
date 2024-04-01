#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
 * The main logic of the function is as follows:
 * 1. We use two pointers: start and end to iterate over the characters of the input string s.
 * 2. We use a hash map called mp to keep track of the number of occurrences of each character
 *    in the current substring.
 * 3. We keep track of the most frequently occurring character in the current substring and its count.
 * 4. We compare the number of occurrences of the most frequently occurring character in the current
 *    substring with the given integer k. If it is greater than k, then we need to shrink the current
 *    substring by moving the start index to the right and decrementing the count of the character at
 *    the start index in the map.
 * 5. If the number of occurrences of the most frequently occurring character in the current substring
 *    is not greater than k, then we update the maximum length of the current substring.
 * 6. We repeat step 2 to 5 until the end index reaches the length of the input string s.
 * 7. Finally, we return the maximum length of the substring.
 */
int max_rep_char_repl(string &s, int k){
    // A hash map to keep track of the number of occurrences
    // of each character in the current substring.
    unordered_map<char, int> mp;
    // Start and end indices to iterate over the input string s
    int start = 0, end = 0;
    // The maximum length of the substring
    int max_len = 0;

    // The most frequently occurring character in the current substring and its count
    char mostFreqChar;
    int mostFreqCharCount = 0;

    while(end < s.length()){
        // Add the current character to the map
        if(!mp[s[end]]){
            // If it is the first occurrence of the character, we add it to the map
            // with a count of 1
            mp[s[end]] = 1;
        }
        else{
            // If it is not the first occurrence of the character, we increment its count
            mp[s[end]]++;
        }
        // Update the most frequently occurring character and its count in the current substring
        mostFreqChar = s[end];
        mostFreqCharCount  = max(mp[mostFreqChar], mostFreqCharCount);

        if((end - start + 1) - mostFreqCharCount > k){
            // If the number of characters of the most frequently occurring character in the current
            // substring is greater than k, then we need to shrink the current substring by moving
            // the start index to the right and decrementing the count of the character at the start
            // index in the map.
            mp[s[start]]--;
            start++;
        }
        else{
            // Otherwise, we update the maximum length of the current substring.
            max_len = max(end - start + 1 , max_len);
        }
        end++;
    }

    return max_len;

}


int main(){
    string s;
    getline(cin, s);
    int k ;
    cin >> k;
    cout << max_rep_char_repl(s, k);
    return 0;
}