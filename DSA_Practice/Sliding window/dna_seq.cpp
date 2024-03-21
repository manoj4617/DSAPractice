#include<iostream>
#include<unordered_map>
#include<set>
#include<string>

using namespace std;

// This function finds all the substrings of length 'n' in a given
// string 'str' and returns a set of all the unique substrings that
// occur more than once in the given string.
//
// Time complexity: O(n)
// Space complexity: O(n)
set<string> find_dna_seq(string str, int n){

    // hash map to keep track of the number of occurrences of each 
    // substring of length n in the given string str
    unordered_map<string,int> hash;

    // set to store all the unique substrings of length n that occur
    // more than once in the given string str
    set<string> res_set;

    // substring of length n that we are currently considering
    string sub_str = "";

    // indices of the start and end of the substring of length n 
    // that we are currently considering
    int start = 0, end = n-1;

    // loop through all substrings of length n in the given string str
    while(end < str.length()){

        // extract the next substring of length n from the given string str
        sub_str = str.substr(start, n);

        // if the current substring is already present in the hash map
        if(hash.find(sub_str) != hash.end()){

            // increment the count of the current substring in the hash map
            hash[sub_str]++;

            // if the count of the current substring in the hash map is >= 2
            if(hash[sub_str] >= 2){

                // insert the current substring into the set of unique substrings
                res_set.insert(sub_str);
            }
        }
        // if the current substring is not already present in the hash map
        else{

            // insert the current substring with count 1 into the hash map
            hash[sub_str] = 1;
        }

        // increment the end index of the substring of length n that we are considering
        end++;

        // increment the start index of the substring of length n that we are considering
        start++;
    }

    // return the set of all the unique substrings of length n that occur more than once in the given string str
    return res_set;
}

int main(){

    string str;
    getline(cin, str);
    int n;
    cin >> n;

    set<string> res = find_dna_seq(str,n);

    for(set<string>::iterator it = res.begin(); it != res.end();++it){
        cout << *it << endl;
    }

    return 0;
}