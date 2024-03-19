#include<iostream>
#include<algorithm>

using namespace std;

// bool isalnum(char *c){
//     if( (*c >= 'a' && *c <= 'z') || 
//         (*c >= 'A' && *c <= 'Z') ||
//         (*c >= '0' || *c == '9')){
//             return true;
//          }
//     else
//         return false;
// }

char toLower(char *c){
    if(*c >= 65 && *c <= 90)
        *c = *c + 32;
    return *c;
}
bool isPalindrome(string s) {
    int i=0, j = s.length() - 1;
    while(i <= j){
        if(!isalnum(s[i])){
            i++;
            continue;
        }
        if(!isalnum(s[j])){
            j--;
            continue;
        }
        if(tolower(s[i]) != tolower(s[j]))
            return false;
        else{
            i++;
            j--;
        }
    }
    return true;
}


int main(){
    string s;
    getline(cin,s);
    if(isPalindrome(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}