#include<iostream>
#include<map>
#include<string>

using namespace std;

int longest_sub_str(string str){

    map<char,int> mp;

    int start = 0, end = 0, len = str.length(), max_len = INT_MIN;

    while(end < len){
        mp[str[end]]++;

        if(mp[str[end]] > 1){
            while(mp[str[end]] > 1){
                mp[str[end]]--;
                start++;
            }
        }

        if(end - start > max_len){
            max_len = end - start;
        }
        end++;
    }
    return max_len+1;

}

int main(){

    string str;
    getline(cin, str);

    cout << longest_sub_str(str) << endl;
    return 0;
}