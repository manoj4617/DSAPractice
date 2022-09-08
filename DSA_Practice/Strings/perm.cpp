#include<iostream>

using namespace std;

void permutate(string str, int k){
    static int flag[10] = {0};
    static char Res[10];

    if(str[k] == '\0'){
        Res[k] = '\0';
        for(int j=0;Res[j] != '\0';++j){
            cout<<Res[j];
        }
        cout<<endl;
    }
    else{
        for(int i=0;i<str.length();i++){
            if(flag[i] == 0){
                Res[k] = str[i];
                flag[i] = 1;
                permutate(str,k+1);
                flag[i] = 0;
            }
        }
    }
}

int main(){
    
    string str;
    cin >> str;

    permutate(str,0);

    return 0;
}