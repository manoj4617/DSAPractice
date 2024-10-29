#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <list>

using namespace std;

template<typename K, typename V>
struct Entry{
    K key;
    V value;
    Entry(K k, V v) : key(k), value(v) {}
};

template<typename K, typename V>
class CollissionResolutionStrategy {
    public:
    virtual ~CollissionResolutionStrategy() = default;
    virtual void insert(int index, const Entry<K,V>& entry, vector<list<Entry<K,V>>>& table) = 0;
    virtual V* find(int index, const K& key, vector<list<Entry<K,V>>>& table) = 0;
};

template<typename K, typename V>
class SeparateChaining : public CollissionResolutionStrategy<K, V> {
    public:
    void insert(int index, const Entry<K,V>& entry, vector<list<Entry<K,V>>>& table){
        for(auto& e : table[index]){
            if(e.key == entry.key){
                e.value = entry.value;
                return;
            }
        }
        table[index].push_back(entry);
    }

    V* find(int index, const K& key, vector<list<Entry<K,V>>>& table){
        for(auto& e : table[index]){
            if(e.key == key){
                return &e.value;
            }
        }
        return nullptr;
    }
};

template<typename K, typename V>
class HashMap {
    private:
    vector<list<Entry<K,V>>> table;
    uint32_t capacity; 
    uint32_t size;
    float loadFactor;
    unique_ptr<CollissionResolutionStrategy<K, V>> strategy;

    /**
     * Computes the hash value of a given key. This is a simple function that
     * uses the std::hash function to compute the hash value of the key and then
     * applies the modulo operator to map the hash value to the valid range of
     * indices in the table.
     *
     * In particular, the hash value is computed as std::hash<K>{}(key), where
     * K is the type of the key. This will compute a hash value that is a
     * std::size_t, which is an unsigned integer type.
     *
     * The hash value is then mapped to the valid range of indices in the table
     * using the modulo operator. The modulo operator will return the remainder
     * of the division of the hash value by the capacity of the table. This will
     * ensure that the computed index is always within the valid range of
     * indices in the table.
     *
     * @param key the key to be hashed
     * @return the index of the key in the table
     */
    int hash(const K& key){
        return std::hash<K>{}(key) % capacity;
    }

    /**
     * Rehashes the table to double its current capacity. This is done when the
     * load factor of the table exceeds the threshold specified in the
     * constructor.
     *
     * The rehashing process works by creating a new table with double the
     * capacity of the old table, and then reinserting all the elements from the
     * old table into the new table. This is done by iterating over the old
     * table, and for each bucket in the old table, iterating over the list of
     * elements in that bucket and inserting them into the new table using the
     * insert method.
     *
     * The reason we need to reinsert all the elements is that the hash value of
     * each element is computed based on the capacity of the table, so when the
     * capacity changes, the hash values of all the elements change. Therefore,
     * we need to recompute the hash values of all the elements and reinsert them
     * into the new table.
     */
    void rehash(){
        // Save the old table so that we can iterate over it later
        vector<list<Entry<K,V>>> oldTable = table;

        // Double the capacity of the table
        capacity *= 2;

        // Create a new table with the new capacity
        table.clear();
        table.resize(capacity);

        // Reset the size of the table to 0
        size = 0;

        // Iterate over the old table and reinsert all the elements into the new table
        for(auto& e : oldTable){
            for(const auto& entry : e){
                // Insert the element into the new table
                insert(entry.key, entry.value);
            }
        }
    }

    public:
    HashMap(float loadFactorThreshold = 0.7)
    :capacity(16), size(0), loadFactor(loadFactorThreshold),
    strategy(make_unique<SeparateChaining<K, V>>())
    {
        table.resize(capacity);
    }

    void setCollissionStrategy(unique_ptr<CollissionResolutionStrategy<K, V>> newStrategy){
        strategy = move(newStrategy);
        rehash();
    }
    
    void insert(const K& key, const V& value){
        if(static_cast<float>(size) / capacity >= loadFactor){
            rehash();
        }
        int index = hash(key);
        strategy->insert(index, Entry<K,V>(key, value), table);
        size++;
    }

    V* find(const K& key){
        int index = hash(key);
        return strategy->find(index, key, table);
    }

    void printHash() const{
        for(int i=0;i<capacity;++i){
            cout << "Bucket " << i << ": ";
            for(const auto& entry : table[i]){
                cout << "{ "<<entry.key << ": " << entry.value << "} ";
            }
            cout << "\n";
        }
    }
};

int main(){
    HashMap<string, int> hashMap;

    hashMap.insert("apple", 1);
    hashMap.insert("orange", 2);
    hashMap.insert("grapes", 2);
    hashMap.insert("orange", 4);
    hashMap.insert("pineapple", 5);
    hashMap.insert("mushroom", 10);
    hashMap.insert("peach", 14);


    cout << "HashMap contents: \n";
    hashMap.printHash();

    if(auto val = hashMap.find("mushroom")){
        cout << "\nFound 'apple' with value: " << *val << "\n";
    }
    else{
        cout << "\n'apple' not found\n";
    }
    return 0;
}