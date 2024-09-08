#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of strings as input and returns a vector of integers.
 * For each string in the input vector, it counts the number of duplicate characters
 * in the string and adds that count to the result vector.
 * The count is done by iterating over the string and comparing each character with
 * the previous one. If they are the same, the count is incremented.
 * The count is then added to the result vector.
 */
vector<int> NumberOfDuplicatesToRemove(const vector<string> &list){
    vector<int> res;
    for(const string &s : list){
        int n = s.length();
        int count = 0;
        for(int i=1;i<n;++i){
            if(s[i] == s[i-1]){
                count++;
            }
        }
        res.push_back(count);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<string> list(n);

    for(int i=0;i<n;++i){
        string str;
        cin >> str;
        list.push_back(str);
    }
    vector<int> res = NumberOfDuplicatesToRemove(list);
    for(const int &r : res){
        cout << r << " ";
    }
}