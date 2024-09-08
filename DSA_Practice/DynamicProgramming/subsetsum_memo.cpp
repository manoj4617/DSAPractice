#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int t[2000][2000];
/**
 * This function checks if there exists a subset of the given set of integers
 * which sums up to the given target number. It uses memoization to store the
 * results of subproblems and avoid redundant calculations.
 *
 * @param set The given set of integers.
 * @param sum The target number that we want to reach.
 * @param i The current index in the given set of integers.
 * @return 1 if a subset with sum equal to the target number exists, 0 otherwise.
 */
int subset_sum(vector<int>& set, int sum, int i){
    // If the target number is 0, we have found a valid subset, so we return 1.
    if(sum == 0){
        return 1;
    }

    // If we have reached the end of the given set of integers, we have
    // explored all the possible subsets that start with the current subset,
    // so we return 0 because we have not found a valid subset.
    if(i <= 0){
        return 0;
    }

    // If the subproblem has already been solved, we return the stored result to
    // avoid redundant calculations.
    if(t[i - 1][sum] != -1){
        return t[i - 1][sum];
    }

    // If the current integer is greater than the target number, we can't add it
    // to the current subset, so we recurse with the previous index.
    if(set[i - 1] > sum){
        return t[i - 1][sum] = subset_sum(set, sum, i - 1);
    }

    // If the current integer is less than or equal to the target number, we can
    // add it to the current subset and recurse with the updated sum and the
    // previous index. We also recurse with the current index to explore all the
    // possible subsets that don't include the current integer.
    else{
        return t[i - 1][sum] = subset_sum(set, sum - set[i - 1], i - 1) || subset_sum(set, sum , i - 1);
    }
}


int main()
{
    // Storing the value -1 to the matrix
    memset(t, -1, sizeof(t));
    int n = 5;
    vector<int> a = {1, 5, 3, 7, 4};
    int sum = 12;

    if (subset_sum(a, sum, a.size()))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

}