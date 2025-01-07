#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr){}
};

class LRUCache{
    private:
        int cap;
        unordered_map<int, Node*> cache;
        Node* right;
        Node* left;

        void remove(Node* node){
            Node* prv = node->prev;
            Node* nxt = node->next;
            prv->next = nxt;
            nxt->prev = prv; 
        }

        void insert(Node* node){
            Node* prv = right->prev;
            prv->next = node;
            node->prev = prv;
            node->next = right;
            right->prev = node;
        }

    public:
      LRUCache(const LRUCache &) = default;
      LRUCache(LRUCache &&) = default;
      LRUCache &operator=(const LRUCache &) = default;
      LRUCache &operator=(LRUCache &&) = default;
      LRUCache(int capacity)
          : cap(capacity), right(new Node(0, 0)), left(new Node(0, 0)) {
        cache.clear();
        right->prev = left;
        left->next = right;
      }

        /**
         * Retrieves the value associated with the given key from the cache.
         * If the key is not present in the cache, returns -1.
         *
         * @param key the key to retrieve from the cache
         *
         * @return the value associated with the given key, or -1 if the key is not present
         */
        int get(int key){
            // if the key is present in the cache, retrieve the associated node
            if(cache.find(key) != cache.end()){
                Node* node = cache[key];

                // remove the node from the doubly linked list so that we can move it to the front
                remove(node);

                // insert the node at the front of the list to mark it as most recently used
                insert(node);

                // return the value associated with the given key
                return node->val;
            }
            // if the key is not present in the cache, return -1
            return -1;
        }

        void put(int key, int value){
            // Check if the key already exists in the cache
            if(cache.find(key) != cache.end()){
                // If the key exists, remove the existing node from the doubly linked list
                remove(cache[key]);
            }

            // Create a new node with the given key and value
            Node* newNode = new Node(key, value);
            // Add the new node to the cache map
            cache[key] = newNode;
            // Insert the new node at the front of the doubly linked list
            insert(newNode);

            // If the cache size exceeds the capacity, remove the least recently used node
            if(cache.size() > cap){
                // The least recently used node is located right after the left dummy node
                Node* lru = left->next;
                // Remove the least recently used node from the doubly linked list
                remove(lru);
                // Erase the least recently used node's key from the cache map
                cache.erase(lru->key);
                // Free the memory allocated for the least recently used node
                delete lru;
            }
        }

};

int main(){
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << "Value for key: 1 " << cache->get(1) << endl; // Output: 1
    cache->put(3, 3);
    cout << "Value for key: 2 "<< cache->get(2) << endl; // Output: -1
    cache->put(4, 4);
    cout << "Value for key: 1 "<<cache->get(1) << endl; // Output: -1
    cout << "Value for key: 3 "<<cache->get(3) << endl; // Output: 3
    cout << "Value for key: 4 "<<cache->get(4) << endl; // Output: 4
}