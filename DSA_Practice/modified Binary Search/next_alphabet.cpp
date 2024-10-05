#include <iostream>

using namespace std;

/**
 * This function takes a string of characters and a target character, and returns the next larger
 * character in the string that is greater than the target character. If the target character is
 * the last character in the string, then the function returns '#', indicating there is no next
 * larger character.
 *
 * The function works by using a modified binary search algorithm to find the next larger
 * character. It starts by setting low to 0 and high to the size of the string minus 1. It then
 * enters a while loop that continues until low is greater than high.
 *
 * In each iteration of the loop, the function calculates the midpoint of the current search
 * window and checks if the character at the midpoint is equal to the target character. If it is,
 * then the function moves the low pointer to the midpoint + 1, since the target character is not
 * the next larger character.
 *
 * If the character at the midpoint is less than the target character, then the function moves the
 * low pointer to the midpoint + 1, since the target character is greater than the character at
 * the midpoint.
 *
 * If the character at the midpoint is greater than the target character, then the function sets
 * res to the character at the midpoint and moves the high pointer to the midpoint - 1. This is
 * done so that the function does not skip over the next larger character.
 *
 * The function then repeats the loop until the search window is empty, at which point it returns
 * the last value of res as the next larger character.
 */
char NextGreaterAlphabet(string str, char k){
    int low = 0;
    int high = str.length() - 1;
    char res = '#';
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(str[mid] == k){
            low = mid + 1;
        }
        if(str[mid] < k){
            low = mid + 1;
        }
        else if(str[mid] > k){
            res = str[mid];
            high = mid - 1;
        }
    }
    return res;
}

int main(){
    string str;
    cin >> str;
    char k;
    cin >> k;
    cout << NextGreaterAlphabet(str,k);
    return 0;
}