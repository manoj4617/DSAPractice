#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> arrayIntersection(vector<int> &num1, vector<int> &num2){
    int i = 0, j = 0;

    vector<int> result;
    unordered_map<int, int> m;

    do{
        if(num1[i] == num2[j]){
            if(m[num1[i]] == 0){
                result.push_back(num1[i]);
                m[num1[i]] = 1;
            }
            else{
                break;
            }
        }
        i = (i+1) % num1.size();
        j = (j+1) % num2.size();
        
    }while(m[num1[i]]!= 1 || m[num2[j]] != 1 && i < num1.size());
    
    return result;
}

int main(){
    vector<int> num1, num2;
    int n1, n2;
    cin >> n1 >> n2;

    for(int i = 0; i < n1; i++){
        int x;
        cin >> x;
        num1.push_back(x);
    }
    for(int i = 0; i < n2; i++){
        int x;
        cin >> x;
        num2.push_back(x);
    }
    vector<int> result = arrayIntersection(num1, num2);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}