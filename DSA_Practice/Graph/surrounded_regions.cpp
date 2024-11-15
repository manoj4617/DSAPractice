#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& board, int i , int j){
    int rows = board.size();
    int cols = board[0].size();

    if(i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != 'O'){
        return;
    }

    board[i][j] = 'E';

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    for(auto& d : dirs){
        dfs(board, i + d[0], j + d[1]);
    }
}

/**
 * This function takes a 2D vector of characters representing a board and
 * identifies all the 'O' regions that are surrounded by 'X' regions.
 * It uses a Depth-First Search (DFS) to mark all the 'O' regions that are
 * connected to the border of the board as 'E' (which stands for Escape).
 * Then it iterates through the board and marks all the 'O' regions that are
 * not connected to the border (i.e. the ones that are surrounded by 'X')
 * as 'X'.
 * Finally, it iterates through the board again and marks all the 'E' regions
 * as 'O'.
 */
void solve(vector<vector<char>>& board){
    int rows = board.size();
    int cols = board[0].size();

    // Iterate through the border of the board and mark all the 'O' regions
    // connected to it as 'E'
    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            if((board[i][j] == 'O') && (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)){
                dfs(board, i , j);
            }
        }
    }

    // Iterate through the board and mark all the 'O' regions that are not
    // connected to the border as 'X'
    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }

    // Iterate through the board and mark all the 'E' regions as 'O'
    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            if(board[i][j] == 'E'){
                board[i][j] = 'O';
            }
        }
    }
}


void print(vector<vector<char>> board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    print(board);
    solve(board);
    print(board);
    return 0;
}