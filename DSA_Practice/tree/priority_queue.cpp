#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <stdint.h>

template<typename T>
class PriorityQueue  {
    public:

        PriorityQueue(uint32_t max_size) : max_size(max_size) {
            heap = std::vector<std::pair<T, int>>();
        };
        
        void heapify(int index){
            int _left_child = left_child(index);
            int _right_child = right_child(index);

            int large = index;
            if(_left_child < heap.size() && heap[_left_child].second > heap[large].second){
                large = _left_child;
            }
            if(_right_child < heap.size() && heap[_right_child].second > heap[large].second){
                large = _right_child;
            }

            if(large != index){
                std::swap(heap[index], heap[large]);
                heapify(large);
            }
            else
                return;
        }
        void insert(T value, int priority){
            if(heap.size() >= max_size){
                std::cout << "Overflow" << std::endl;
                return;
            }
            heap.push_back(std::make_pair(value, priority));
            int lastIdx = heap.size() - 1;

            while(lastIdx != 0 && heap[parent(lastIdx)].second < heap[lastIdx].second){
                std::swap(heap[lastIdx],heap[parent(lastIdx)]);
                lastIdx = parent(lastIdx);
            }
        }
        std::pair<T, int> remove_max() {
            // if (heap.size() == 0) {
            //     return std::pair<INT, class T2>;
            // }

            auto max_value = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapify(0);

            return max_value;
        }

        void update_priority(T value, int new_priority){
            if(heap.empty()){
                std::cout << "Empty heap: no priorities to update" << std::endl;
                return;
            }

            auto it = std::find_if(heap.begin(), heap.end(), [&](const std::pair<T, int>& element) -> bool{
                return element.first == value;
            });

            if(it != heap.end()){
                it->second = new_priority;
                auto index = std::distance(heap.begin(), it);
                heapify(0);
            }
        }
        std::pair<T, int> get_max(){
            return heap[0];
        };
        int cur_size(){
            return heap.size();
        }
        void print(){
            std::cout << "Heap: " << std::endl;
            std::cout << "Value" << "\t" << "Priority" << std::endl;
            for(auto i : heap){
                std::cout << i.first << "\t" << i.second << std::endl;
            }
        }
        int parent(int index){
            return (index-1)/2;
        }
        int right_child(int index){
            return 2*index + 2;
        }
        int left_child(int index){
            return 2*index + 1;
        }

    private:
        // Max-heap
        std::vector<std::pair<T, int>> heap;
        uint32_t max_size;
};

int main(){

    PriorityQueue<double> pq(10);
    pq.insert(10.23234, 1);
    pq.insert(15.121, 2);
    pq.insert(20.34322, 3);
    pq.insert(5.0099, 4);
    pq.insert(3.1323, 5);
    pq.insert(4423.323, 10);

    pq.print();
    auto max_val = pq.get_max();
    std::cout << "Max value: " << max_val.first << " with priority: " << max_val.second << std::endl;
    std::cout << "After removing max\n";
    pq.remove_max();
    max_val = pq.get_max();
    std::cout << "Max value: " << max_val.first << " with priority: " << max_val.second << std::endl;
    pq.print();

    std::cout << "Updating priority of 5.0099 to 10" << std::endl;
    pq.update_priority(5.0099, 10);
    pq.print();
    return 0;

}