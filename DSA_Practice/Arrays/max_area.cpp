#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height){
    int i = 0;
    int j = height.size() - 1;

    int max_area = 0;

    while(i < j){
        max_area = max(max_area, min(height[i], height[j]) * (j - i));
        if(height[i] < height[j]){
            i++;
        }   
        else{
            j--;
        }
    }

    return max_area;
}

int main(){
    int n;
    cin >> n;

    vector<int> height(n);

    for(int i=0; i<n; i++){
        int n;
        cin >> n;
        height.push_back(n);
    }

    cout << maxArea(height);
    return 0;
}