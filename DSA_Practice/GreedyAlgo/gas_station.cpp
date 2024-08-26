#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This function takes two arrays of integers, gas and cost, and returns
 *        the starting index of the only valid journey that can be completed
 *        in one pass. A valid journey is one where the total gas collected
 *        is greater than or equal to the total cost of the journey.
 *
 * The algorithm works by iterating through the gas and cost arrays and
 * keeping a running total of the gas collected and the cost incurred. If at
 * any point the total gas collected is less than the total cost incurred, we
 * know that the journey is not valid and we reset the running totals and start
 * the journey from the next index.
 *
 * The key insight here is that if the total gas collected is greater than or
 * equal to the total cost incurred at any point, we know that the journey will
 * be valid from that point onwards. This is because the gas collected will
 * always be greater than or equal to the cost incurred, and so we will always
 * have enough gas to complete the journey.
 *
 * The greedy technique is used here because we are always trying to find the
 * longest valid journey. We start from the first index and keep moving forward
 * until we find a valid journey. If we find a valid journey, we keep going. If
 * we don't find a valid journey, we reset and start from the next index.
 *
 * The intuition behind this problem is that we want to find the longest valid
 * journey that can be completed in one pass. We can do this by keeping a
 * running total of the gas collected and the cost incurred, and resetting the
 * running totals and starting the journey from the next index if the total
 * gas collected is less than the total cost incurred at any point.
 *
 * The time complexity of this algorithm is O(n), where n is the size of the
 * gas and cost arrays. This is because we only need to iterate through the
 * arrays once to find the longest valid journey.
 *
 * The space complexity of this algorithm is O(1), because we only need a
 * constant amount of space to store the running totals and the starting index
 * of the journey.
 */
int GasStationJourney(vector<int>& gas, vector<int>& cost){
    int total_gas = 0, total_cost = 0, n = gas.size();
    for(auto& g : gas){
        total_gas += g;
    }
    for(auto& c : cost){
        total_cost += c;
    }

    if(total_gas < total_cost){
        return -1;
    }

    int current_gas = 0, start = 0;
    for(int i=0;i<n;++i){
        current_gas += (gas[i] - cost[i]);
        if(current_gas < 0){
            current_gas = 0;
            start = i + 1;
        }
    }

    return start;

}


int main(){
    int n;
    cin >> n;
    vector<int> gas(n);
    vector<int> cost(n);

    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        gas.push_back(t);
    }

    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        cost.push_back(t);
    }

    cout << GasStationJourney(gas,cost);
    return 0;
}