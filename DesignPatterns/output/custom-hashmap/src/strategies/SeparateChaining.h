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