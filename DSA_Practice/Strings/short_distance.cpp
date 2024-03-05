#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min_index(vector<int>& arr, int index){
    int minNum = 9999999;

    for(int i=0;i<arr.size();i++){
        minNum = min(minNum, abs(arr[i] - index));
    }

    return minNum;
}

vector<int> short_to_char(string s, char k){
    vector<int> ind;
    vector<int> distance;


    for(int i=0;i<s.length(); i++){
        if(s[i] == k)
            ind.push_back(i);
    }

    for(int i = 0; i < s.length() ; i++){
        distance.push_back(min_index(ind, i));
    }

    return distance;
}


/*
    Two pass solution:
*/
vector<int> short_to_char_two_pass(string s, char k){
    int n = s.length();
    vector<int> ind;
    vector<int> distance(n, INT_MAX);
    int lastSeen = -1;


    //1st pass from left to right
    for(int i=0;i<n ; ++i){
        if(s[i] == k){
            lastSeen = i;
        }
        if(lastSeen != -1){
            distance[i] = min(distance[i], abs(i - lastSeen));
        }
    }

    lastSeen = n;

    //2nd pass from right to left
    for(int i = n - 1; i >= 0; --i){
        if(s[i] == k){
            lastSeen = i;
        }

        if(lastSeen != n){
            distance[i] =  min(distance[i], abs(i - lastSeen));
        }
    }

   
    return distance;
}

int main(){
    string str;
    cin >> str;
    char k;
    cin >> k;
    // vector<int> res = short_to_char(str, k);
    vector<int> res = short_to_char_two_pass(str, k);
    for(auto& ele : res){
        cout << ele << " ";
    }
    return 0;
}