#include <iostream>
#include <vector>

using namespace std;

class MinHeap{

    vector<int> heap;
    int max_size;
    
public:
    MinHeap(int maxSize);
    void MinHeapify(int);

    int parent(int i){
        return (i-1)/2;
    }

    int left_child(int i){
        return (i * 2 + 1);
    }
    
    int right_child(int i){
        return (i * 2 + 2);
    }

    int remove_max();
    void increase_key(int i, int newVal);

    int get_max(){return heap[0];}
    int cur_size(){return heap.size();}

    void delete_key(int i);
    void insert_key(int k);
};

MinHeap::MinHeap(int maxsize){
    max_size = maxsize;
    heap = vector<int>();
}

/**
 * This function inserts a new key into the heap.
 * 
 * @param k The key to be inserted.
 */
void MinHeap::insert_key(int k){
    // Check if the heap is already full.
    if(heap.size() > max_size){
        // If the heap is full, print an overflow message and return.
        cout<<"Overflow"<<endl;
        return;
    }

    // Get the index of the last element in the heap.
    heap.push_back(k);
    int i = heap.size() - 1;
    
    // Add the new key to the end of the heap.

    // Start from the last element and keep swapping the element with its parent
    // until the heap property is satisfied.
    while(i != 0 && heap[parent(i)] > heap[i]){
        // Swap the element at index i with its parent.
        swap(heap[i], heap[parent(i)]);
        
        // Move up one level in the heap.
        i = parent(i);
    }
}


void MinHeap::increase_key(int i, int newVal){
    heap[i] = newVal;
    while(i != 0 && heap[parent(i)] > heap[i]){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

/**
 * This function removes the maximum element from the heap.
 * 
 * @return The maximum element in the heap.
 */
int MinHeap::remove_max(){
    // If the heap is empty, return the minimum possible value.
    if(heap.size() == 0){
        return INT_MIN;
    }
    
    // If the heap has only one element, remove it and return it.
    if(heap.size() == 1){
        heap.pop_back();
        return heap[0];
    }

    // Get the value of the root element.
    int root = heap[0];
    
    // Replace the root element with the last element in the heap.
    heap[0] = heap[heap.size()-1];
    
    // Remove the last element from the heap.
    heap.pop_back();

    // Restore the heap property by calling the MinHeapify function on the root element.
    MinHeapify(0);

    // Return the value of the root element.
    return root;
}

void MinHeap::delete_key(int i){
    increase_key(i, INT_MAX);
    remove_max();
}

/**
 * This function is the core of the heapify operation in a Heap data structure.
 * It takes an index i of a node in the heap, and restores the heap property
 * by recursively swapping the node at index i with one of its children if needed.
 * The heap property is defined as follows:
 *    - If the heap is a max-heap, the value of the parent node is greater than
 *      or equal to the value of its children.
 *    - If the heap is a min-heap, the value of the parent node is less than
 *      or equal to the value of its children.
 *
 * The function works as follows:
 * 1. It finds the indices of the left and right children of node i, if they exist.
 * 2. It determines which of the two children (if any) has the larger value.
 *    If there is no child, then the function does nothing and exits.
 * 3. If the value of the child is larger than the value of node i, then the function
 *    swaps the values of the two nodes and recursively calls itself on the index of
 *    the child that was swapped. This ensures that the subtree rooted at child also
 *    satisfies the heap property.
 * 
 * Time complexity: O(log n) in the worst case, where n is the number of elements in the heap.
 */
void MinHeap::MinHeapify(int i){
    // Find the indices of the left and right children of node i
    int left = left_child(i);
    int right = right_child(i);

    // Determine which of the two children (if any) has the larger value
    int small = i;
    if(left < heap.size() && heap[left] < heap[i]){
        small = left;
    }
    if(right < heap.size() && heap[right] < heap[small]){
        small = right;
    }

    // If the value of the child is larger than the value of node i,
    // then swap the values of the two nodes and recursively call
    // the function on the index of the child that was swapped.
    if(small != i){
        swap(heap[i], heap[small]);
        MinHeapify(small);
    }
    else {
        return;
    }
}


