#include <iostream>
#include <string>
using namespace std;

void reverse(string& str, int s, int e){
    while(s < e){
        swap(str[s], str[e]);
        s++;
        e--;
    }
}

string reverseStr(string str, int k){
    int n = str.length();
    for(int i=0; i < n ; i += 2 * k){
        int s = i;
        int e = min(i + k -1 , n - 1);

        reverse(str, s, e);
    }

    return str;
}

int main(){

    string str;
    int k;
    cin >> str;
    cin >> k;
    string res = reverseStr(str, k);
    cout << res << endl;

    return 0;
}