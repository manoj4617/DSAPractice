class HashMap {
public:
    HashMap(size_t size, std::unique_ptr<CollissionResolutionStrategy<K, V>> strategy)
        : table(size), resolutionStrategy(std::move(strategy)) {}

    void insert(const K& key, const V& value) {
        int index = hash(key) % table.size();
        Entry<K, V> entry{key, value};
        resolutionStrategy->insert(index, entry, table);
    }

    V* find(const K& key) {
        int index = hash(key) % table.size();
        return resolutionStrategy->find(index, key, table);
    }

private:
    std::vector<std::list<Entry<K, V>>> table;
    std::unique_ptr<CollissionResolutionStrategy<K, V>> resolutionStrategy;

    int hash(const K& key) {
        // Implement a hash function for the key type K
    }
};