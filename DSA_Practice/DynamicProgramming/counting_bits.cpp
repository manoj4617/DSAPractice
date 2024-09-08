#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes an integer n as input and returns a vector of integers.
 * The vector contains the number of 1's in the binary representation of each
 * integer from 0 to n.
 *
 * The function uses dynamic programming to solve this problem. It maintains a
 * vector res of size n + 1, where the i-th element of res is the number of 1's
 * in the binary representation of i.
 *
 * The base cases are res[0] = 0 (since 0 in binary is 0) and res[1] = 1 (since
 * 1 in binary is 1). For all other values of i, the function checks if i is
 * even or odd. If i is even, then the number of 1's in the binary representation
 * of i is the same as the number of 1's in the binary representation of i / 2.
 * If i is odd, then the number of 1's in the binary representation of i is one
 * more than the number of 1's in the binary representation of i / 2.
 *
 * The function finally returns the vector res.
 */
vector<int> count_bits(int &n){
        if(n == 0){
            return {0};
        }
    vector<int> res(n + 1, 0);

    // Base case: 0 in binary is 0
    res[0] = 0;

    // Base case: 1 in binary is 1
    res[1] = 1;

    // Iterate over all values of i from 2 to n
    for(int i = 2;i<=n;++i){
        // If i is even, the number of 1's in the binary representation of i is
        // the same as the number of 1's in the binary representation of i / 2
        if(i % 2 == 0){
            res[i] = res[i / 2];
        }
        // If i is odd, the number of 1's in the binary representation of i is
        // one more than the number of 1's in the binary representation of i / 2
        else{
            res[i] = res[i/2] + 1;
        }
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> res = count_bits(n);
    for(const int &r : res){
        cout << r << " ";
    }
}