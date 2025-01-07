#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes an integer n representing the number of fence posts and
 * an integer k representing the number of colors to paint the fence posts with.
 * It returns the number of ways to paint the fence such that no two adjacent
 * fence posts have the same color.
 *
 * The approach is to use dynamic programming to solve the problem. The
 * function initializes a vector ways of size (n+1) to store the number of ways
 * to paint the first i fence posts. The base case is when n is 1, in which case
 * the number of ways to paint the fence is k. The second base case is when n is
 * 2, in which case the number of ways to paint the fence is k * k.
 *
 * Then, the function iterates from i=3 to n, calculating the number of ways to
 * paint the current fence post by adding the number of ways to paint the
 * current fence post with a different color to the number of ways to paint the
 * previous fence post with the same color. The current number of ways is then
 * stored in the ways vector at index i.
 *
 * Finally, the function returns the number of ways to paint the nth fence post,
 * which is stored in the ways vector at index n.
 */
int numWays(int n, int k){
    if(n == 1) return k;
    if(n == 2) return k * k;

    // Initialize a vector ways of size (n+1) to store the number of ways to
    // paint the first i fence posts.
    vector<int> ways(n + 1,0);
    // The number of ways to paint the first fence post is k.
    ways[1] = k;
    // The number of ways to paint the first two fence posts is k * k.
    ways[2] = k * k;

    // Iterate from i=3 to n, calculating the number of ways to paint the current
    // fence post by adding the number of ways to paint the current fence post
    // with a different color to the number of ways to paint the previous fence
    // post with the same color.
    for(int i=3;i<=n;++i){
        // The number of ways to paint the current fence post with a different
        // color is (k - 1) times the number of ways to paint the previous fence
        // post. The number of ways to paint the current fence post with the same
        // color is the number of ways to paint the fence post two positions
        // previously.
        ways[i] = (k - 1) * (ways[i-1] + ways[i-2]);
    }

    // Return the number of ways to paint the nth fence post, which is stored in
    // the ways vector at index n.
    return ways[n];
}

/**
 * This function takes an integer n representing the number of fence posts and
 * an integer k representing the number of colors to paint the fence posts with.
 * It returns the number of ways to paint the fence such that no two adjacent
 * fence posts have the same color.
 *
 * The approach is to use dynamic programming to solve the problem. The
 * function initializes two variables, twoWay and oneWay, to be the number of
 * ways to paint the first two fence posts. Then, it iterates from i=3 to n,
 * calculating the number of ways to paint the current fence post by adding the
 * number of ways to paint the current fence post with a different color to the
 * number of ways to paint the previous fence post with the same color. The
 * current number of ways is then stored in the oneWay variable, and the
 * previous number of ways is stored in the twoWay variable.
 *
 * Finally, the function returns the number of ways to paint the nth fence post,
 * which is stored in the oneWay variable.
 */
int numWaysOptimized(int n, int k){
    if(n == 1) return k;
    if(n == 2) return k * k;

    // Initialize twoWay to be the number of ways to paint the first two fence
    // posts.
    int twoWay = k;
    // Initialize oneWay to be the number of ways to paint the first three fence
    // posts.
    int oneWay = k * k;

    // Iterate from i=3 to n, calculating the number of ways to paint the current
    // fence post by adding the number of ways to paint the current fence post
    // with a different color to the number of ways to paint the previous fence
    // post with the same color.
    for(int i=3;i<=n;++i){
        // Calculate the number of ways to paint the current fence post.
        int cur = (k-1) * (oneWay + twoWay);
        // Update twoWay to be the previous number of ways.
        twoWay = oneWay;
        // Update oneWay to be the current number of ways.
        oneWay = cur;
    }

    // Return the number of ways to paint the nth fence post.
    return oneWay;
}

int main(){
    int n,k;
    cin >> n >> k;
    cout << "Ways: " << numWays(n, k) << endl;
    cout << "Ways: " << numWaysOptimized(n, k);
    return 0;
}