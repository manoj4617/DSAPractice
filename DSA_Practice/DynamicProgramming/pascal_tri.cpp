#include<iostream>
#include<vector>

using namespace std;

vector<int> pascal_triangle(int num_rows){
    vector<vector<int>> p_tri;

    for(int i=0;i<=num_rows;++i){
        p_tri.push_back(vector<int>(i+1,1));
        for(int j=1;j<i;++j){
            p_tri[i][j] = p_tri[i-1][j] + p_tri[i-1][j-1];
        }
    }
    vector<int> res;
        for(int i=0;i<p_tri[num_rows].size();++i){
            res.push_back(p_tri[num_rows][i]);
        }
        //return res;
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> res = pascal_triangle(n);
    return 0;
}