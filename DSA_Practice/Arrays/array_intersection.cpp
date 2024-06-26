#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * This function takes two vectors of integers, num1 and num2, and returns a vector
 * containing the intersection of the two vectors. The intersection is defined
 * as the elements that are common to both vectors. The function uses an
 * unordered_map to keep track of the elements that have already been added to the
 * result vector. The function uses two indexes, i and j, to iterate over the two
 * input vectors. The function uses do-while loop to iterate over both vectors
 * until one of the indexes reaches the end of its respective vector or an element
 * in num2 has already been encountered and added to the result vector.
 *
 * Parameter(s):
 * num1: The first vector of integers.
 * num2: The second vector of integers.
 *
 * Return:
 * A vector of integers containing the intersection of num1 and num2.
 */
vector<int> arrayIntersection(vector<int> &num1, vector<int> &num2){
    // Initialize two indexes, i and j, to 0.
    int i = 0, j = 0;

    // Initialize an empty vector to store the result.
    vector<int> result;

    // Initialize an unordered_map to keep track of the encountered elements.
    unordered_map<int, int> m;

    // Do the following while one of the indexes has not reached the end of its
    // respective vector and an element in num2 has not been encountered and
    // added to the result vector.
    do{
        // Check if the element at index i in num1 is equal to the element at
        // index j in num2.
        if(num1[i] == num2[j]){
            // Check if the element at index i in num1 has not already been added
            // to the result vector.
            if(m[num1[i]] == 0){
                // If the element has not been added, add it to the result vector
                // and mark it as encountered in the unordered_map.
                result.push_back(num1[i]);
                m[num1[i]] = 1;
            }
            else{
                // If the element has already been added, exit the loop.
                break;
            }
        }

        // Update the indexes to move to the next elements in the vectors.
        i = (i+1) % num1.size();
        j = (j+1) % num2.size();
    
    // Continue the loop until one of the indexes has reached the end of its
    // respective vector or an element in num2 has been encountered and added
    // to the result vector.
    }while(m[num1[i]]!= 1 || m[num2[j]] != 1 && i < num1.size());
    
    // Return the result vector.
    return result;
}


int main(){
    vector<int> num1, num2;
    int n1, n2;
    cin >> n1 >> n2;

    for(int i = 0; i < n1; i++){
        int x;
        cin >> x;
        num1.push_back(x);
    }
    for(int i = 0; i < n2; i++){
        int x;
        cin >> x;
        num2.push_back(x);
    }
    vector<int> result = arrayIntersection(num1, num2);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}