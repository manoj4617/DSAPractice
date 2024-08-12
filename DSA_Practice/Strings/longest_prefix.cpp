#include<iostream>
#include<vector>

using namespace std;

/**
 * This function takes a vector of strings as input and returns the longest
 * common prefix of all the strings.
 *
 * @param str - A vector of strings
 * @return The longest common prefix of all the strings, or an empty string if
 *         there is no common prefix
 *
 */
string longest_prefix(vector<string> str){

    // Initialize the prefix with the first string in the vector
    string pre = str[0];

    // Iterate through the rest of the strings
    for(int i=1;i<str.size();++i){

        // If the prefix is not empty
        if(pre.size()){
            
            // Iterate through each character in the prefix
            for(int k=0;k<pre.size();++k){

                // If the character at the current position is not the same
                // as the corresponding character in the current string
                if(pre[k] != str[i][k]){

                    // Set the prefix to be the substring of the original prefix
                    // up to the current position
                    pre = pre.substr(0,k);

                    // Break out of the inner loop
                    break;
                }
            }
        }
        // If the prefix is empty (i.e., there is no common prefix)
        else{

            // Return an empty string
            return "";
        }
    }

    // Return the final prefix
    return pre;
}

int main(){

    vector<string> s;
    int n;
    cin >> n;
    string temp;

    for(int i=0;i<n;++i){
        cin >> temp;
        s.push_back(temp);
    }

    cout << longest_prefix(s) << endl;
    return 0;
}