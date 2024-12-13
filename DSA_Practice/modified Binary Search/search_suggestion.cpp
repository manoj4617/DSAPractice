#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * This function takes a vector of strings, products, and a searchWord, and returns a vector of
 * vectors of strings, where each inner vector contains up to 3 strings that are suggested products
 * based on the searchWord.
 *
 * The function works by first sorting the products vector in-place.
 *
 * The function then iterates over the characters in the searchWord, and for each character,
 * it finds the index of the first product that starts with the current prefix of the searchWord
 * (i.e. the characters that have been processed so far). This index is stored in the start variable.
 *
 * The function then iterates over the products vector, starting at the index stored in start,
 * and adds up to 3 products to the current inner vector that start with the current prefix.
 *
 * The function then updates the start index to the index of the last product that was added to
 * the current inner vector, so that the next iteration of the loop will start at the correct
 * index.
 *
 * The function returns the vector of vectors of strings once all the characters in the searchWord
 * have been processed.
 */
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end());
    vector<vector<string>> res;
    int start, k = 0, n = products.size();
    string prefix;
    for(char& c : searchWord){
        prefix += c;
        start = lower_bound(products.begin() + k, products.end(), prefix) - products.begin();
        res.push_back({});
        for(int i=start;i<min(start+3, n) && !products[i].compare(0,prefix.length(), prefix); ++i){
            res.back().push_back(products[i]);
        }
        k = start;
    }
    return res;
}

int main(){
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";

    vector<vector<string>> res = suggestedProducts(products, searchWord);

    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[i].size();++j){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}