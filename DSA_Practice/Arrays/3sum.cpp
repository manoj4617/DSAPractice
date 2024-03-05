#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> three_sum(vector<int>& nums){
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for(int i=0;i<nums.size()-2;++i){
        int low = i + 1;
        int high = nums.size() - 1;

        while(low < high){
            int triplet = nums[i] + nums[low] + nums[high];
            if(triplet == 0){
                vector<int> new_triplet = {nums[i], nums[low], nums[high]};
                sort(new_triplet.begin(), new_triplet.end());

                bool exists = false;
                for(const auto& t : res){
                    if(t == new_triplet){
                        exists = true;
                        break;
                    }
                }

                if(!exists){
                    res.push_back(new_triplet);
                }
            }

            if(triplet < 0)
                low += 1;
            else
                high -= 1;
        }        
    }

    return res;
}

int main(){
    int n;
    cin >> n;

    vector<int> nums;

    for(int i=0;i<n;++i){
        int t;
        cin >> t;
        nums.push_back(t);
    }

    vector<vector<int>> res = three_sum(nums);

    for(const auto& triplet : res){
        for(auto& t : triplet){
            cout  << t << " ";
        }
        cout << "\n";
    }

    return 0;
}

