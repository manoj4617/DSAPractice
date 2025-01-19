class HashMap {
public:
    HashMap(size_t size, std::unique_ptr<CollissionResolutionStrategy<K, V>> strategy);
    void insert(const K& key, const V& value);
    V* find(const K& key);
    
private:
    std::vector<std::list<Entry<K, V>>> table;
    std::unique_ptr<CollissionResolutionStrategy<K, V>> collisionStrategy;
    size_t tableSize;
};