#include <iostream>
#include <vector>

using namespace std;
/**
 * A helper function to perform a depth first search to check if a word can be
 * formed from a given grid of characters.
 *
 * @param row The row index of the current cell being explored.
 * @param col The column index of the current cell being explored.
 * @param word The word to be searched for in the grid.
 * @param idx The current index of the word being searched for.
 * @param grid A 2D vector of characters representing the grid.
 * @return True if the word can be formed from the characters in the grid,
 *         false otherwise.
 */
bool DFS(int row, int col, string word, int idx, vector<vector<char>>& grid){
    /**
     * Base case: if we have explored the entire word, return true.
     */
    if(word.length() == idx){
        return true;
    }

    /**
     * Check if the current cell is a valid cell to explore. If it is out of
     * bounds, or its character does not match the current character of the word,
     * return false.
     */
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
       grid[row][col] != word[idx]){
        return false;
    }

    /**
     * Mark the current cell as visited by setting its character to '*'. This
     * is done to avoid revisiting the same cell multiple times.
     */
    grid[row][col] = '*';

    /**
     * Explore all four directions from the current cell. For each direction, if
     * the word can be formed from the characters in that direction, return true.
     */
    vector<vector<int>> offsets{{0,1},{1,0},{0,-1},{-1,0}};
    for(auto offset : offsets){
        int new_row = row + offset[0];
        int new_col = col + offset[1];

        if(DFS(new_row, new_col, word,idx + 1,grid)){
            return true;
        }
    }

    /**
     * If no valid direction is found, unmark the current cell as visited and
     * return false.
     */
    grid[row][col] = word[idx];
    return false;
}

bool WordSearch(vector<vector<char>> grid, string word){
    for(int i=0;i<grid.size();++i){
        for(int j=0;j<grid[0].size();++j){
            if(DFS(i,j,word,0,grid)){
                return true;
            }
        }
    }
    return false;
}



int main(){
    string str;
    cin >> str;
    vector<vector<char>> grid = {{'A','B','C','D'},{'S','A','A','T'},{'A','C','A','E'}};

    bool res = WordSearch(grid,str);
    cout << res;
    return 0;
}