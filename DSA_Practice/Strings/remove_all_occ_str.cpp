#include <iostream>
#include <string>

using namespace std;

/**
 * This function takes a string and a substring, and removes all occurrences of
 * the substring from the string.
 *
 * The function iterates over each character in the string, and for each
 * character, it adds the character to the result string. If the result string
 * is at least as long as the substring, and the last part of the result string
 * is equal to the substring, then the last part of the result string is
 * removed.
 *
 * This is done by using the substr() function to check if the last part of the
 * result string is equal to the substring. If it is, then the erase() function
 * is used to remove the last part of the result string.
 *
 * @param s The string to remove occurrences from.
 * @param part The substring to remove.
 * @return The string with all occurrences of the substring removed.
 */
string removeOccurrences(string s, string part) {
    string result = "";
    for(char& c : s){
        result.push_back(c);
        if(result.size() >= part.size() && result.substr(result.size() - part.size()) == part){
            result.erase(result.size() - part.size());
        }
    }      
    return result;
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeOccurrences(s, part) << endl;
    return 0;
}