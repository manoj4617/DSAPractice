#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

set<int> squares;

// Function to calculate the minimum number of perfect square numbers that sum up to 'n'
int minSquareNums(int n) {
    // Check if 'n' itself is a perfect square
    if (squares.count(n)) {
        cout << n << "\n";  // Output the number if it is a perfect square
        return 1;  // Return 1 since 'n' is already a perfect square
    }

    int min_nums = INT_MAX;  // Initialize the minimum count to a large value

    // Iterate over each perfect square number in the set 'squares'
    for (const int& s : squares) {
        // If the current perfect square is greater than 'n', break the loop
        if (n < s) {
            break;
        }
        // Calculate the minimum number of perfect squares needed by recursively
        // calling the function for the remaining value 'n - s' and add 1
        min_nums = min(min_nums, minSquareNums(n - s) + 1);
    }
    return min_nums;  // Return the minimum number of perfect squares
}

/**
 * Function to calculate the minimum number of perfect squares that sum up to 'n'
 *
 * @param n The number to find the minimum number of perfect squares for
 *
 * @return The minimum number of perfect squares that sum up to 'n'
 */
int numSquares(int n) {
    // Create a set to store all perfect squares up to the square root of 'n'
    // The set is used to store all perfect squares since checking if a number
    // is in the set is faster than checking if it is in a vector
    set<int> squares;

    // Iterate up to the square root of 'n' and add each perfect square to the set
    for (int i = 1; i <= sqrt(n); ++i) {
        squares.insert(i * i);
    }

    // Create a vector to store the minimum number of perfect squares needed to
    // sum up to each number from 0 to 'n' (inclusive)
    vector<int> dp(n + 1, INT_MAX);

    // Initialize the first element of the vector to be 0, since 0 can be
    // represented as the sum of 0 perfect squares
    dp[0] = 0;

    // Iterate over each number from 1 to 'n' (inclusive)
    for (int i = 1; i <= n; ++i) {
        // Iterate over each perfect square in the set
        for (const int& s : squares) {
            // If the current perfect square is greater than the current number,
            // break the loop since we don't need to check any more perfect squares
            if (i < s) {
                break;
            }

            // Calculate the minimum number of perfect squares needed to sum up to
            // the current number by taking the minimum of the current value in
            // the vector and the value at the position of the current number
            // minus the perfect square plus 1
            dp[i] = min(dp[i], dp[i - s] + 1);
        }
    }

    // Return the last element of the vector, which represents the minimum number
    // of perfect squares needed to sum up to 'n'
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << numSquares(n);
    return 0;
}