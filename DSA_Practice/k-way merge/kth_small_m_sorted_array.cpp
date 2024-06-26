#include <iostream>
#include <vector>
#include <functional>
#include <queue>

/*
 * This function takes in a 2D vector of integers and an integer kSmall.
 * It returns the kSmallth smallest element in the merged sorted array.
 * The function uses a priority queue to keep track of the smallest elements
 * from each subarray. The priority queue is sorted in descending order based
 * on the first element of each vector in the queue.
 *
 * Parameter(s):
 * arrays: A 2D vector of integers representing subarrays.
 * kSmall: An integer representing the kth smallest element.
 *
 * Return:
 * An integer representing the kth smallest smallest element in the merged
 * sorted array.
 */
int kth_smallest_element(std::vector<std::vector<int>> &arrays, int kSmall){
    int smallestNum; // variable to store the kth smallest element
    int count = 0; // variable to keep track of the count of elements popped from the priority queue
    std::priority_queue<
        std::vector<int>, // the priority queue will store vectors of integers
        std::vector<std::vector<int>>, // the priority queue will be sorted based on the first element of each vector
        std::greater<std::vector<int>>> pq; // the priority queue will be sorted in descending order

    // loop through each subarray in the input vector
    for(int i=0; i<arrays.size(); i++){
        // if the subarray is empty, skip it
        if(arrays[i].size() == 0){
            continue;
        }
        // otherwise, add the first element of the subarray to the priority queue
        else{
            pq.push({arrays[i][0],i,0});
        }
    }

    // loop until the count of elements popped from the priority queue is equal to kSmall
    while(!pq.empty()){
        // pop the smallest element from the priority queue
        std::vector<int> small = pq.top();
        pq.pop();
        // store the smallest element in a variable
        smallestNum = small[0];
        // store the index of the subarray where the smallest element comes from
        int listIdx = small[1];
        // store the index of the smallest element in its subarray
        int numIdx  = small[2];
        // increment the count
        count++;
        // if the count is equal to kSmall, break the loop
        if(count == kSmall){
            break;
        }
        // if there are more elements in the subarray, add the next element to the priority queue
        if(numIdx + 1 < arrays[listIdx].size()){
            pq.push({arrays[listIdx][numIdx+1], listIdx, numIdx+1});
        }
    }
    // return the kth smallest element
    return smallestNum;
}


int main(){
    std::vector<std::vector<std::vector<int>>> lists ={
            {{2, 6, 8}, 
            {3, 6, 10}, 
            {5, 8, 11}}, 
               
            {{1, 2, 3}, 
            {4, 5}, 
            {6, 7, 8, 15},
            {10, 11, 12, 13},
            {5, 10}},

            {{},{},{}},
            
            {{1, 1, 3, 8}, 
            {5, 5, 7, 9}, 
            {3, 5, 8, 12}},

            {{5, 8, 9, 17}, 
            {}, 
            {8, 17, 23, 24}}
            };

    std::vector<int> k = {5, 50, 7, 4, 8};
    for (int i=0; i< k.size(); i++){
            std::cout<<"\tK = "<<k[i]<<std::endl;
            std::cout<<"\t"<<k[i]<<"th smallest number from the given lists is: "<<kth_smallest_element(lists[i], k[i])<<std::endl;
        std::cout<< std::string(100, '-') << "\n";
    }
    return 0;
}
