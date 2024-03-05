#include<iostream>
#include<string>

using namespace std;

string min_sub_seq(string str1, string str2){
    int i = 0, j = 0,start,end;
    int min_len = INT_MAX;
    string subStr= "";
    while(i < str1.length()){
        //check if str1[i] == str2[j]
        if(str1[i] == str2[j]){
            j++;

            //this means we have found the min subsequence when j has over shot its str2 length
            if(j == str2.length()){
                start = i;
                end = start + 1;
                j--;

                while(j >= 0){
                    if(str1[start] == str2[j]){
                        j--;
                    }
                    start--;
                }
                start++;
                if(end - start < min_len){
                    min_len = end - start;
                    subStr = str1.substr(start,min_len);
                }
                i = start;
                j = 0;
            }
        }
        i++;
    }

    return subStr;
}

int main(){

    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    cout << min_sub_seq(str1, str2) << endl;
    return 0;
}