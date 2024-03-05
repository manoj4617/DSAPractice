#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


void print(string str){
    cout << str << endl;
}

void ReverseWordsInString(string str){
      reverse(str.begin(), str.end());

    size_t start = 0;
    size_t end = 0;
    size_t wordCount = 0;

    while (end < str.length()) {
        while (end < str.length() && str[end] == ' ') {
            end++; // Skip leading spaces
        }

        if (end == str.length()) {
            break;
        }

        if (wordCount != 0) {
            str[wordCount++] = ' '; // Add space between words
        }

        start = wordCount; // Save the start position of the word

        while (end < str.length() && str[end] != ' ') {
            str[wordCount++] = str[end++]; // Copy the word
        }

        reverse(str.begin() + start, str.begin() + wordCount); // Reverse the word
    }

    str.resize(wordCount); // Trim extra characters after the last word
    print(str);
}

int main(){

    string str;
    getline(cin, str);
    print(str);
    ReverseWordsInString(str);


    return 0;
}