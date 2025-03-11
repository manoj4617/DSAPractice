#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
Problem: Find minimum moves to position rooks so they don't attack each other
- Rooks attack along same row or column
- Need to ensure no two rooks share same row or column
- Each move can shift a rook one square horizontally or vertically

Key Insight:
1. Optimal solution places rooks in a diagonal pattern (0,0), (1,1), (2,2), etc.
2. Can solve independently for rows and columns
3. Sort by row coordinates to handle row conflicts
4. Sort by column coordinates to handle column conflicts
*/

static bool compare(vector<int>& a, vector<int>& b){
    // Custom comparator to sort by column coordinate (second element)
    return b[1] - a[1] > 0;
}

int minMoves(vector<vector<int>>& rooks){
    int n = rooks.size(), res = 0;

    // Step 1: Handle row conflicts
    sort(rooks.begin(), rooks.end());  // Sort by row coordinate (first element)
    for(int i=0;i<n;++i){
        // Count moves needed to position rook at row i
        res += abs(i - rooks[i][0]);
    }

    // Step 2: Handle column conflicts
    sort(rooks.begin(), rooks.end(), compare);  // Sort by column coordinate
    for(int i=0;i<n;++i){
        // Count moves needed to position rook at column i
        res += abs(i - rooks[i][1]);
    }

    return res;
}

/*
Example:
rooks = {{0,1}, {1,0}, {1,1}}

1. Sort by rows: {{0,1}, {1,0}, {1,1}}
   - Move rooks to rows 0,1,2
   - Moves needed: |0-0| + |1-1| + |2-1| = 1

2. Sort by columns: {{1,0}, {0,1}, {1,1}}
   - Move rooks to columns 0,1,2
   - Moves needed: |0-0| + |1-1| + |2-1| = 1

Total moves = 2
*/

int main(){
    vector<vector<int>> rooks ={
        {0,1},
        {1,0},
        {1,1}
    };

    cout << "Min moves to make board peaceful: " << minMoves(rooks) << endl;
    return 0;
}