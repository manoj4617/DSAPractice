#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief This function takes a 2D vector of integers, cost, and returns
 *        the minimum total cost of flying all employees to two cities.
 *
 * The problem is solved using a greedy approach. The idea is to first
 * sort the cost matrix in ascending order of the difference between
 * the cost of flying to city A and city B. This is done by using a
 * lambda function as the third argument to the sort function.
 *
 * The logic behind this sorting is that we want to prioritize flying
 * employees to the city that costs the least. By sorting the matrix
 * in this way, we ensure that the first element of the matrix has the
 * least difference between the cost of flying to city A and city B.
 *
 * Then, we iterate through the sorted matrix and add the cost of flying
 * to city A from the first half of the matrix and the cost of flying to
 * city B from the second half of the matrix. This ensures that we are
 * always flying the employees to the city that costs the least.
 *
 * The greedy approach helps in deriving the intuition and the logic
 * for the algorithm. It allows us to break down the problem into smaller
 * subproblems and solve each one in a way that is optimal for the
 * overall problem. In this case, the subproblem is to find the minimum
 * cost of flying to two cities, and the greedy approach allows us to
 * solve this subproblem by prioritizing the employees who cost the
 * least to fly to the cities.
 *
 * The time complexity of this algorithm is O(n log n), where n is the
 * size of the cost matrix. This is because we need to sort the matrix,
 * which takes O(n log n) time.
 *
 * The space complexity of this algorithm is O(1), because we only need
 * a constant amount of space to store the total cost.
 */
int TwoCityScheduling(vector<vector<int>>& cost){
    sort(cost.begin(), cost.end(),
        [](vector<int>& a, vector<int>& b) ->bool{
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
    int total_cost = 0, n = cost.size();
    for(int i=0; i < n/2; ++i){
        total_cost += cost[i][0] + cost[n - i - 1][1];
    }

    return total_cost;

}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> cost;
    for(int i=0;i<n;++i){
        int a, b;
        cin >> a >> b;
        vector<int> temp;
        cost.push_back({a,b});
    }
    cout << TwoCityScheduling(cost);
    return 0;
}