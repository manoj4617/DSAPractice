#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generateTransformation(const string& str){
    vector<string> res;

    for(int i=0;i<str.length();++i){
        char original = str[i];
        for(char c='a';c <= 'z';++c){
            if(original != c){
                string transformed = str;
                transformed[i] = c;
                res.push_back(transformed);
            }
        }
    }
    return res;
}

int main(){
    string str;
    cin >> str;

    vector<string> res = generateTransformation(str);
    for(string& s : res){
        cout << s << endl;
    }
    return 0; 
}