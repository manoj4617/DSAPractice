#include <iostream>

using namespace std;

/**
 * This function takes two strings x and y and returns the length of the longest
 * common subsequence between the two strings.
 *
 * The function uses a recursive approach to solve the problem. The base case is
 * when either string is empty (i.e. m == 0 or n == 0). In this case, the longest
 * common subsequence is 0.
 *
 * Otherwise, the function checks if the last characters of the two strings are
 * equal. If they are, the function adds 1 to the longest common subsequence
 * between the strings excluding the last characters (i.e. LongestCommonSubSeq(x,
 * y, m - 1, n - 1)).
 *
 * If the last characters are not equal, the function returns the maximum of the
 * longest common subsequence between the strings excluding the last character of
 * x (i.e. LongestCommonSubSeq(x, y, m - 1, n)) and the longest common subsequence
 * between the strings excluding the last character of y (i.e. LongestCommonSubSeq(x,
 * y, m, n - 1)).
 */
int LongestCommonSubSeq(string &x, string &y, int m, int n){
    if(n == 0 || m == 0){
        return 0;
    }

    if(x[m - 1] == y[n-1]){
        int lcs = 1 + LongestCommonSubSeq(x, y, m - 1, n - 1);
        return lcs;
    }
    else{
        int lcs1 = LongestCommonSubSeq(x, y, m - 1, n);
        int lcs2 = LongestCommonSubSeq(x, y, m, n - 1);
        return max(lcs1, lcs2);
    }
}


int main(){
    string x , y;
    cin >> x >> y;
    cout << LongestCommonSubSeq(x,y,x.length(), y.length());
    return 0;
}