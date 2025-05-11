#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    // vector<int> left2right(n,1);
    // vector<int> right2left(n,1);
    // for(int i=1;i<n;++i){
    //     if(ratings[i] > ratings[i-1]){
    //         left2right[i] = left2right[i-1] + 1;
    //     }
    // }
    // for(int i=n-2;i>=0;--i){
    //     if(ratings[i] > ratings[i+1]){
    //         right2left[i] = right2left[i+1] + 1;
    //     }
    // }
    // int total_candies = 0;
    // for(int i=0;i<n;++i){
    //     total_candies += max(left2right[i], right2left[i]);
    // }
    // return total_candies;
    vector<int> candies(n,1);
    for(int i=1;i<n;++i){
         if(ratings[i] > ratings[i-1]){
            candies[i] = candies[i-1] + 1;
        }
    }
    int total_candies = candies.back();
    for(int i=n-2;i >= 0; --i){
        if(ratings[i] > ratings[i+1]){
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        total_candies += candies[i];
    }
    return total_candies;
}

int main(){
    int n = 3;
    vector<int> ratings = {1,2,2};
    cout << "Max candies: " << candy(ratings);
    return 0;
}