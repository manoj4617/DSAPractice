#include<iostream>
#include<string>

using namespace std;

int strStr(const string A, const string B) {
    
    int start, i = 0, j = 0;
    
    if(A.length() < B.length()){
        return -1;
    }

    while(i < A.length()){
        while(A[i] != B[j] && i < A.length()){
            i++;
        }
        
        start = i;
        
        while(j < B.length()){
            if(A[i] == B[j]){
                j++;
                i++;
            }
            else{
                j = 0;
                break;
            }
        }
        
        if(j == B.length())
            return start;
        else
            i = start+1;
    }
    
    return -1;
    
}

int main(){

    string A, B;
    getline(cin, A);
    getline(cin, B);

    cout << strStr(A,B);

    return 0;

}