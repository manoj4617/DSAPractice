#include <iostream>
#include <string>

using namespace std;
int strStr(string a, string b) {
    int i=0,j=0;

    while(i < a.length()){
        if(a[i] == b[j]){
            while(j < b.length() && a[i] == b[j]){
                i++;
                j++;
            }
            if(j == b.length()){
                return i - j;
            }
            else{
                i = i - j + 1;
                j = 0;
            }
        }
        else{
            i++;
            j = 0;
        }
    }
    return -1;
}

int main(){
    string hay, needle;
    getline(cin,hay);
    getline(cin,needle);

    cout << strStr(hay, needle);

    return 0;

}