#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * This function takes a string of digits and returns the longest possible palindrome
 * that can be formed from the digits in the string.
 *
 * The approach is as follows:
 *  - Count the frequency of each digit in the string.
 *  - For each digit, if the frequency is greater than 1, add the digit to the first half
 *    of the palindrome that many times. If the frequency is 1, add it to the second half.
 *  - If there is a digit with an odd frequency, add it to the middle of the palindrome.
 *  - Reverse the first half to get the second half.
 *  - Return the full palindrome.
 */
string LongestPaliString(string nums){
    if(nums.length() == 0){
        // If the string is empty, return an empty string.
        return "";
    }

    unordered_map<char, int> mp;

    for(auto& n : nums){
        // Count the frequency of each digit in the string.
        mp[n]++;
    }
    vector<string> firstHalf;
    string middle;

    for(char digit = '9' ; digit >= '0' ; --digit){
        if(mp.find(digit) != mp.end()){
            int digitNum = mp[digit];
            int numPair = digitNum / 2;
             if(numPair){
                // If the frequency of the digit is greater than 1, add it to the first half
                // of the palindrome that many times.
                if(firstHalf.empty() && digit == '0'){
                    mp['0'] = 1;
                }
                else{
                    firstHalf.push_back(string(numPair,digit));
                }
             }
             if(digitNum % 2 == 1 && middle.empty()){
                // If the frequency of the digit is odd, add it to the middle of the palindrome.
                middle = digit;
             }
        }
    }

    string res;
    for(const auto& p : firstHalf){
        // Build the first half of the palindrome.
        res += p;
    }
    string secondHalf = res;
    reverse(secondHalf.begin(), secondHalf.end());
    // Reverse the first half to get the second half.
    res += middle + secondHalf;

    // Return the full palindrome.
    return res;
}

int main(){
    string nums;
    cin >> nums;
    string res = LongestPaliString(nums);
    cout << res;
    return 0;
}