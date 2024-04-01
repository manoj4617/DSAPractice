#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int max_substr_with_k_rep(string &str, int k)
{
    int max_len = 0;
    unordered_map<char, int> mp;
    int start = 0, end = 0, countAtLeastK = 0;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        mp[c]++;

        if (mp[c] == k)
        {
            countAtLeastK++;
        }

        if (mp[c] > k)
        {
            mp[str[start]]--;
            start++;
        }

        if (countAtLeastK == k - 1)
        {
            max_len = max(max_len, i - start + 1);
        }
    }

    return max_len;
}


int main(){
    int k;
    cin >> k;
    string s;
    cin >> s;

    cout << max_substr_with_k_rep(s, k); 
    return 0;
}