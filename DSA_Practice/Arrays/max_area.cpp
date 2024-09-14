#include <iostream>
#include <vector>

using namespace std;

/**
 * This function takes a vector of heights and returns the maximum possible area
 * that can be formed by two lines in the vector. The area is calculated by taking
 * the minimum of the two heights and multiplying it by the distance between the
 * two lines.
 *
 * The algorithm starts by initializing two pointers, one at the beginning of the
 * vector and one at the end. It then iterates through the vector, calculating the
 * maximum area at each step and updating the maximum area if it is greater than
 * the current maximum. The iteration continues until the two pointers meet, at
 * which point the maximum area has been found.
 *
 * If the height at the left pointer is less than the height at the right pointer,
 * the left pointer is incremented. Otherwise, the right pointer is decremented.
 * This is done to ensure that the maximum area is calculated.
 *
 * @param height A vector of heights
 *
 * @return The maximum possible area that can be formed by two lines in the vector
 */
int maxArea(vector<int>& height){
    int i = 0; // Initialize the left pointer to the beginning of the vector
    int j = height.size() - 1; // Initialize the right pointer to the end of the vector

    int max_area = 0; // Initialize the maximum area to 0

    while(i < j){ // Iterate until the two pointers meet
        // Calculate the area at the current step by taking the minimum of the two
        // heights and multiplying it by the distance between the two lines
        int area = min(height[i], height[j]) * (j - i);

        // Update the maximum area if the current area is greater than the maximum area
        max_area = max(max_area, area);

        // If the height at the left pointer is less than the height at the right
        // pointer, increment the left pointer. Otherwise, decrement the right
        // pointer
        if(height[i] < height[j]){
            i++;
        }   
        else{
            j--;
        }
    }

    // Return the maximum area
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