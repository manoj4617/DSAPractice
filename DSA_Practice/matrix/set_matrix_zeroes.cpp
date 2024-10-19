#include <iostream>
#include <vector>
using namespace std;

void SetZeroes(vector<vector<int>>& mat){
    int row = mat.size();
    int col = mat[0].size();

    bool fRow = false;
    bool fCol = false;

    //check for zeroes in first row and col
    for(int i=0;i<col;++i){
        if(mat[0][i] == 0){
            fRow = true;
            break;
        }
    }

    for(int i=0;i<row;++i){
        if(mat[i][0] == 0){
            fCol = true;
            break;
        }
    }

    for(int i=1;i<row;++i){
        for(int j=1;j<col;++i){
            if(mat[i][j] == 0){
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }

    for(int i=1;i<row;++i){
        if(mat[i][0] == 0){
            for(int j=1;j<col;++j){
                mat[i][j] = 0;
            }
        }
    }

    for(int i=1;i<col;++i){
        if(mat[0][i] == 0){
            for(int j=1;j<row;++j){
                mat[i][j] = 0;
            }
        }
    }

    if(fCol){
        for(int j=0;j<row;++j){
            mat[0][j] = 0;
        }
    }

    if(fRow){
        for(int i=0;i<row;++i){
            mat[i][0] = 0;
        }
    }
}

void printMatrix(vector<vector<int>>& mat){
    for(auto& m : mat){
        for(int& i : m){
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main(){
    int m , n;
    // cin >> m >> n;
    vector<vector<int>> mat = {{1, 1, 0}, {1, 0, 1}, {1, 1, 1}};
    // for(int i=0;i<m;++i){
    //     for(int j=0;j<n;++j){
    //         cin >> mat[i][j];
    //     }
    // }
    printMatrix(mat);
    SetZeroes(mat);
    printMatrix(mat);
    return 0;
}