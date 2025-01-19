class CollissionResolutionStrategy {
    public:
    virtual ~CollissionResolutionStrategy() = default;
    virtual void insert(int index, const Entry<K,V>& entry, vector<list<Entry<K,V>>>& table) = 0;
    virtual V* find(int index, const K& key, vector<list<Entry<K,V>>>& table) = 0;
};