#include<iostream>
#include<vector>

using namespace std;

 bool isIsomorphic(string s, string t) {
      vector<int> arr(256, -1);
      vector<bool> visited(256, 0);
      vector<bool> visited1(256, 0);
      for (int i = 0; i < s.length(); i++) {
         if (visited[s[i]] == 1 || visited1[t[i]] == 1) {
            if (arr[s[i]] != t[i] - 'a') {
               return false;
            }
         }
         else {
            visited[s[i]] = 1;
            visited1[t[i]] = 1;
            arr[s[i]] = t[i] - 'a';
         }
      }
      return true;
   }

int main(){

    string s ,t;
    cin >> s >> t;
    cout << (bool)isIsomorphic(s,t) << endl;

    return 0;
}