#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// This function takes a vector of integers and returns a string that represents the largest possible number that can be formed by concatenating the integers in the vector.
// The sorting logic is used to ensure that the largest possible number is constructed.
// The sorting is done by comparing the two strings concatenated together. This is done by overloading the comparison operator '>' for strings. The comparison operator '>' is used to sort the strings in descending order.
// The comparison 'a + b > b + a' checks if the concatenation of 'a' and 'b' is greater than the concatenation of 'b' and 'a'. This is true if the concatenation of 'a' and 'b' would be greater if read from left to right.
// This is useful because the largest possible number can be formed by concatenating the integers in descending order.
// For example, if we have the vector [3, 32, 321], the largest possible number that can be formed by concatenating the integers is 32321.
// If we sort the strings in descending order, the largest possible number can be constructed by concatenating the strings in the same order.

string largestNumber(vector<int>& nums){
    // Initialize a vector of strings 'str' with the same size as the input vector 'nums'.
    vector<string> str;
    // Initialize an empty string 'res'.
    string res;
    // Convert each integer in 'nums' to a string and store it in 'str'.
    for(int i=0;i<nums.size();i++){
        str[i] = to_string(nums[i]);
    }
    // Sort the strings in 'str' in descending order.
    sort(str.begin(), str.end(),[](const string& a, const string& b) -> bool{
        return a + b > b + a;
    });
    // If the first string in 'str' is "0", return "0" as the largest possible number.
    if(str[0] == "0"){
        return "0";
    }
    // Concatenate all the strings in 'str' and store it in 'res'.
    for(string& s: str){
        res += s;
    }
    // Return 'res' as the largest possible number.
    return res;
}

int main(){
    int n;
    cin >>n;
    vector<int> nums;
    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }
    string r = largestNumber(nums);
    cout << r;
    return 0;
}