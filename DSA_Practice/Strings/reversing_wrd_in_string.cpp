#include<iostream>
#include<string>

using namespace std;

string reverse_word_string(string s){
    int i=0;
    int j=0;
    while(i < s.length()){
        j = i;
        int temp_i = i;

        while(j < s.length()){
            if(s.at(j) == ' '){
                break;
            }else{
                j++;
            }
        }
        int temp_j = j-1;
        int x = (temp_j - temp_i)/2 + 1;
        while(x--){
            swap(s[temp_i], s[temp_j]);
            temp_i++;
            temp_j--;
        }
        i = j+1;
    }

    return s;
}

int main(){

    string s;
    getline(cin, s);
    cout << reverse_word_string(s) << endl;
    return 0;
}