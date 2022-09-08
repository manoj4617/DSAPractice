//  Vectors.cppp

#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<string> strings;
    strings.push_back("cat");
    strings.push_back("dog");
    strings.push_back("duck");
    strings.push_back("mouse");


    for(vector<string>::iterator it = strings.begin(); it != strings.end(); it++){
        cout << *it << endl;
    }

 
    return 0;
}