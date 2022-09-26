#include<iostream>
#include<vector>

using namespace std;

vector<int> even_sum_after_queries(vector<int>& nums, vector<vector<int>>& queries){

    vector<int> ans;
    int sum = 0;

    for(auto i : nums){
        if(i % 2 == 0){
            sum += i;
        }
    }

    for(auto q : queries){
        int val = q[0], id = q[1];
        if(nums[id] % 2 == 0)
            sum -= nums[id];
        nums[id] += val;
        if(nums[id] % 2 == 0)
            sum += nums[id];
        ans.push_back(sum);
    }
    

    return ans;
}

int main(){

    vector<int> nums;
    vector<vector<int>> queries;

    int s,m,temp;
    cin >> s >> m;

    for(int i=0;i<s;++i){
        cin >> temp;
        nums.push_back(temp);
    }

    for(int i=0;i<m;++i){
        vector<int> t_vec;
        for(int j=0;j<2;++j){
            cin >> temp;
            t_vec.push_back(temp);
        }
        queries.push_back(t_vec);

    }

    vector<int> res = even_sum_after_queries(nums,queries);

    for(auto i : res){
        cout << i << " ";
    }

    return 0;
}