#include<iostream>
#include<string>

using namespace std;

string numbers = "0123456789";
string lower_case = "abcdefghijklmnopqrstuvwxyz";
string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string special_characters = "!@#$%^&*()-+";

int strong_password(int n,string s){

    int count = 0;
    size_t has_number = s.find_first_of(numbers,0);
    size_t has_lowercase = s.find_first_of(lower_case,0);
    size_t has_uppercase = s.find_first_of(upper_case,0);
    size_t has_spl_chars = s.find_first_of(special_characters,0);

    if(has_lowercase > n)
        count++;
    if(has_number > n)
        count++;
    if(has_uppercase > n)
        count++;
    if(has_spl_chars > n)
        count++;
    

    if((count + n) < 6){
        return count + (6 - count - n);
    }
    else{
        return count;
    }
}

int main(){

    int n;
    string s;
    cin >> n;
    cin >> s;
    cout << strong_password(n,s) << endl;
    return 0;
}