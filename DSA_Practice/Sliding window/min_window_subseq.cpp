#include<iostream>
#include<string>

using namespace std;

/*
This function takes two strings as input and returns the minimum substring of the first string
that contains all the characters of the second string. If there is no substring that contains
all the characters of the second string, it returns an empty string.

The function uses a sliding window technique to find the minimum substring. It keeps two pointers,
start and end, which point to the first and last characters of the substring respectively. The
function checks if the substring contains all the characters of the second string by looping through
the characters of the second string and checking if the corresponding character is present in the
substring. If it is not, it moves the start pointer forward until it finds the character. If all the
characters of the second string are found, the function updates the minimum substring if the length
of the current substring is less than the previous minimum length. The function then moves the start
pointer to the end of the current substring and repeats the process.

The function returns the minimum substring when the start pointer has reached the end of the first
string or when it has found a substring that contains all the characters of the second string.
*/
string min_sub_seq(string str1, string str2){
    int i = 0, j = 0,start,end;
    int min_len = INT_MAX; //minimum length of the substring
    string subStr= ""; //substring to be returned
    while(i < str1.length()){ //loop through all the characters of the first string
        //check if str1[i] == str2[j]
        if(str1[i] == str2[j]){
            j++;

            //this means we have found the min subsequence when j has over shot its str2 length
            if(j == str2.length()){
                /*
                When all the characters of the second string are found, we need to find the start
                and end indices of the minimum substring. We move the start pointer to the left until
                we find the first character of the second string. We then move the end pointer to the
                right until we reach the end of the first string.
                */
                start = i;
                end = start + 1;
                j--;
                while(j >= 0){
                    if(str1[start] == str2[j]){
                        j--;
                    }
                    start--;
                }
                start++;
                //if the length of the current substring is less than the previous minimum length
                if(end - start < min_len){
                    min_len = end - start;
                    //update the minimum substring
                    subStr = str1.substr(start,min_len);
                }
                //move the start pointer to the end of the current substring and repeat the process
                i = end;
                j = 0;
                continue;
            }
        }
        i++;
    }

    return subStr;
}


int main(){

    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    cout << min_sub_seq(str1, str2) << endl;
    return 0;
}