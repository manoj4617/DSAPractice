   #include <iostream>
   #include <vector>
   
   using namespace std;
   
bool isPalindrome(string s, int i, int j){
     while(i < j){
         if(s[i] != s[j]){
             return false;
         }
         i++;
         j--;
     }
     return true;
 }
 /**
  * This function takes a string, a result vector, the current index, and a
  * helper vector as arguments. It is a recursive function that generates all
  * possible palindromic partitions of the string.
  *
  * @param s The string to partition.
  * @param res The result vector to store the palindromic partitions.
  * @param i The current index of the string being processed.
  * @param helper A vector to store the current partition being generated.
  */
 void Backtrack(string& s,vector<vector<string>>& res, int i , vector<string>& helper){
     /**
      * Base case: if the current index is greater than or equal to the
      * size of the string, we have reached the end of the string and have
      * generated a valid partition. Add the current partition to the result
      * vector.
      */
     if(i >= s.size()){
         res.push_back(helper);
         return;
     }

     /**
      * Iterate from the current index to the end of the string.
      */
     for(int k=i;k<s.size();k++){
         /**
          * Check if the substring from the current index to the current
          * value of k is a palindrome.
          */
         if(isPalindrome(s,i,k)){
             /**
              * If it is a palindrome, add it to the helper vector and
              * recursively call this function with the next index.
              */
             helper.push_back(s.substr(i,k-i+1));
             Backtrack(s,res,k+1,helper);
             /**
              * After the recursive call, remove the last element from the
              * helper vector to backtrack.
              */
             helper.pop_back();
         }
     }
 }
 vector<vector<string>> partition(string s) {
     vector<vector<string>> res;
     vector<string> helper;
     Backtrack(s,res,0, helper);
     return res;
 }

int main(){
    string s;
    cin >> s;
    vector<vector<string>> res = partition(s);
    for(auto& v : res){
        for(auto& ele : v){
            cout << ele << " ";
        }
        cout << endl;
    }
}