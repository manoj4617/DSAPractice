#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

string LongestPaliString(string nums){
    if(nums.length() == 0){
        return "";
    }

    unordered_map<char, int> mp;

    for(auto& n : nums){
        mp[n]++;
    }
    vector<string> firstHalf;
    string middle;

    for(char digit = '9' ; digit >= '0' ; --digit){
        if(mp.find(digit) != mp.end()){
            int digitNum = mp[digit];
            int numPair = digitNum / 2;
             if(numPair){
                if(firstHalf.empty() && digit == '0'){
                    mp['0'] = 1;
                }
                else{
                    firstHalf.push_back(string(numPair,digit));
                }
             }
             if(digitNum % 2 == 1 && middle.empty()){
                middle = digit;
             }
        }
    }

    string res;
    for(const auto& p : firstHalf){
        res += p;
    }
    string secondHalf = res;
    reverse(secondHalf.begin(), secondHalf.end());
    res += middle + secondHalf;

    return res;
}

int main(){
    string nums;
    cin >> nums;
    string res = LongestPaliString(nums);
    cout << res;
    return 0;
}