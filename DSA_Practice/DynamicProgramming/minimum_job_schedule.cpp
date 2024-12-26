#include <iostream>
#include <vector>

using namespace std;

/**
 * This function is a helper function that is used to compute the minimum total
 * difficulty of scheduling the jobs over the given number of days. It takes
 * four parameters: the current index of the jobs vector, the current day, the
 * total number of days, the jobs vector, the maximum difficulty job vector, and
 * the memo vector.
 *
 * The function first checks if the current day is equal to the total number of
 * days. If it is, it returns the maximum difficulty of the job at the current
 * index, since there are no more days left to schedule the jobs.
 *
 * It then checks if the current value in the memo vector is equal to -1. If it
 * is, it means that the solution to the subproblem has not been computed yet, so
 * the function computes it.
 *
 * The function then iterates over the jobs starting from the current index, and
 * for each job, it computes the maximum difficulty of the job and the minimum
 * difficulty of scheduling the remaining jobs. It then takes the minimum of the
 * current value in the memo vector and the maximum difficulty of the job plus
 * the minimum difficulty of scheduling the remaining jobs, and assigns it to
 * the current value in the memo vector.
 *
 * Finally, the function returns the current value in the memo vector.
 */
int dp(int i, int day, int d, vector<int>& jobs, vector<int>& maxDifficultJob, vector<vector<int>>& memo){
    // Base case: if the current day is equal to the total number of days, return
    // the maximum difficulty of the job at the current index, since there are no
    // more days left to schedule the jobs.
    if(day == d){
        return maxDifficultJob[i];
    }

    // Check if the solution to the subproblem has already been computed. If not,
    // compute it.
    if(memo[i][day] == -1){
        int best = INT_MAX;
        int hard = 0;

        // Iterate over the jobs starting from the current index, and for each
        // job, compute the maximum difficulty of the job and the minimum
        // difficulty of scheduling the remaining jobs.
        for(int j = i; j < jobs.size() - (d - day); ++j){
            hard = max(hard, jobs[j]);
            best = min(best, hard + dp(j + 1, day + 1, d, jobs, maxDifficultJob, memo));
        }

        // Store the solution to the subproblem in the memo vector.
        memo[i][day] = best;
    }

    // Return the solution to the subproblem.
    return memo[i][day];
}

/**
 * This function takes a vector of job difficulties and the number of days
 * as input and returns the minimum total difficulty of scheduling the jobs
 * over the given number of days.
 *
 * The function first checks if the number of jobs is less than the number of
 * days. If it is, it returns -1, since it is impossible to schedule the jobs
 * over the given number of days.
 *
 * It then creates a vector of maximum job difficulties, which is used to
 * store the maximum difficulty of any job that has been scheduled so far.
 *
 * The function then iterates over the jobs in reverse order, keeping track
 * of the maximum difficulty of any job that has been scheduled so far. For
 * each job, it sets the maximum difficulty of the job to be the maximum of
 * the current maximum difficulty and the difficulty of the current job.
 *
 * It then creates a memoization table to store the solutions to subproblems
 * of the original problem. The table has n rows, where n is the number of
 * jobs, and d columns, where d is the number of days. Each entry in the table
 * is initialized to -1, indicating that the solution to the subproblem has
 * not yet been computed.
 *
 * Finally, the function calls the dp function, passing in the first job, the
 * first day, the number of days, the jobs vector, the maxDifficultJob vector,
 * and the memoization table as arguments. The dp function returns the minimum
 * total difficulty of scheduling the jobs over the given number of days.
 */
int minJobDifficulty(vector<int>& jobs, int d){
    int n = jobs.size();
    if(n < d){
        return -1;
    }
    vector<int> maxDifficultJob(n);
    int hardest = 0;
    for(int i=n-1;i>=0;--i){
        hardest = max(hardest, jobs[i]);
        maxDifficultJob[i] = hardest;
    }

    vector<vector<int>> memo(n, vector<int>(d, -1));
    return dp(0,1, d,jobs,maxDifficultJob, memo);

}

int main(){
    vector<int> jobs = {6,5,4,3,2,1};
    int d = 2;
    cout << minJobDifficulty(jobs, d);
    return 0;
}