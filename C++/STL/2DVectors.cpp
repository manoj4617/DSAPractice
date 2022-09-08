#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<vector<int>> grid(3, vector<int>(4,0));
    grid[1].push_back(8);
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();++j){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}