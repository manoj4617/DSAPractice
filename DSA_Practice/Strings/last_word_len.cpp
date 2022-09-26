#include<iostream>
#include<string>

using namespace std;

int lengthOfLastWord(string s) {
        int count = 0;
        for(int i=s.length()-1;i>=0;--i){
            if(s[i] == ' ')
                count++;
            else
                break;
        }
        string str;
        int j=0;
        for(int i=s.length()-1-count;i>=0;--i){
            if(s[i] != ' '){
                str.push_back(s[i]);
            }
            else
                break;
        }
        
        return str.length();
    }

int main(){
    string s;
    getline(cin,s);
    cout << lengthOfLastWord(s) << endl;
    return 0;
}