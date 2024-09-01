#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Coordinates {
    int x;
    int y;
};
int next_row[] = {-1,1,0,0};    // Up, Down, No move, No move
int next_col[] = {0, 0, -1, 1}; // No move, No move, Left, Right

queue<Coordinates> q;
vector<vector<int>> visited;
vector<vector<Coordinates>> parent;
vector<vector<char>> grid;
void explore_next(int x , int y, int max_row, int max_col, string& str, int idx){
    int new_row;
    int new_col;

    for(int i=0;i<4;++i){
        new_row = x + next_row[i];
        new_col = y + next_col[i];

        if(new_row < 0 || new_col < 0 || new_col >= max_col || new_row >= max_row){
            continue;
        }
        if(visited[new_row][new_col] == 1 && grid[new_row][new_col] != str[idx]){
            continue;
        }
        q.push({new_row, new_col});
        visited[new_row][new_col] = 1;
        parent[new_row][new_col] = {x, y};
    }
}

bool WordSearch(vector<vector<char>>& grid, string& str){
    int row = grid.size();
    int col = grid[0].size();
    visited = vector<vector<int>>(row, vector<int>(col,0));
    parent  = vector<vector<Coordinates>>(row, vector<Coordinates>(col, {-1,-1}));

    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(grid[i][j] == str[0]){
                visited[i][j] = 1;
                q.push({i,j});
                int i = 1;

                while(!q.empty()){
                    Coordinates next = q.front();
                    q.pop();
                    if(grid[next.x][next.y] == str.back()){
                        return true;
                    }
                    explore_next(next.x, next.y, row, col, str,i++);
                }
                if(i == str.size()){
                    return true;
                }
            }
        }
    }


    return false;
}

int main(){
    string str;
    cin >> str;
    vector<vector<char>> grid = {
        {'N','W','L','I','M'},
        {'V','I','L','Q','O'},
        {'O','L','A','T','O'},
        {'R','T','A','I','N'},
        {'O','I','T','N','C'},
    };

    int res = WordSearch(grid,str);
    cout << res;
    return 0;
}