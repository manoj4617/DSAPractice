#include <iostream>
#include <vector>

using namespace std;

class MaxHeap{

    vector<int> heap;
    int max_size;
    
public:
    MaxHeap(int maxSize);
    void MaxHeapify(int);

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

MaxHeap::MaxHeap(int maxsize){
    max_size = maxsize;
    heap = vector<int>(maxsize);
}

void MaxHeap::insert_key(int k){
    if(heap.size() > max_size){
        cout<<"Overflow"<<endl;
        return;
    }

    int i = heap.size();
    heap.push_back(k);

    while(i != 0 && heap[parent(i)] < heap[i]){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}


void MaxHeap::increase_key(int i, int newVal){
    heap[i] = newVal;
    while(i != 0 && heap[parent(i)] < heap[i]){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::remove_max(){
    if(heap.size() == 0){
        return INT_MIN;
    }
    if(heap.size() == 1){
        heap.pop_back();
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[heap.size()-1];
    heap.pop_back();

    MaxHeapify(0);

    return root;
}

void MaxHeap::delete_key(int i){
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
void MaxHeap::MaxHeapify(int i){
    // Find the indices of the left and right children of node i
    int left = left_child(i);
    int right = right_child(i);

    // Determine which of the two children (if any) has the larger value
    int large = i;
    if(left < heap.size() && heap[left] > heap[i]){
        large = left;
    }
    if(right < heap.size() && heap[right] > heap[large]){
        large = right;
    }

    // If the value of the child is larger than the value of node i,
    // then swap the values of the two nodes and recursively call
    // the function on the index of the child that was swapped.
    if(large != i){
        swap(heap[i], heap[large]);
        MaxHeapify(large);
    }
}


int main() 
{ 
    // Assuming the maximum size of the heap to be 15. 
    MaxHeap h(15); 
  
    // Asking the user to input the keys: 
    int k, i, n = 6, arr[10]; 
    cout << "Entered 6 keys:- 3, 10, 12, 8, 2, 14 \n"; 
    h.insert_key(3); 
    h.insert_key(10); 
    h.insert_key(12); 
    h.insert_key(8); 
    h.insert_key(2); 
    h.insert_key(14); 
  
    // Printing the current size 
    // of the heap. 
    cout << "The current size of the heap is "
         << h.cur_size() << "\n";
  
    // Printing the root element which is 
    // actually the maximum element. 
    cout << "The current maximum element is " << h.get_max() 
         << "\n"; 
  
    // Deleting key at index 2. 
    h.delete_key(2); 
  
    // Printing the size of the heap 
    // after deletion. 
    cout << "The current size of the heap is "
         << h.cur_size() << "\n"; 
  
    // Inserting 2 new keys into the heap. 
    h.insert_key(15); 
    h.insert_key(5); 
    cout << "The current size of the heap is "
         << h.cur_size() << "\n"; 
    cout << "The current maximum element is " << h.get_max() 
         << "\n"; 
  
    return 0; 
}