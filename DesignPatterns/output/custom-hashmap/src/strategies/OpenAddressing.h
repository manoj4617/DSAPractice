class OpenAddressing : public CollissionResolutionStrategy<K, V> {
    public:
    void insert(int index, const Entry<K,V>& entry, vector<list<Entry<K,V>>>& table) {
        int originalIndex = index;
        while (table[index].size() > 0) {
            if (table[index].front().key == entry.key) {
                table[index].front().value = entry.value;
                return;
            }
            index = (index + 1) % table.size();
            if (index == originalIndex) {
                throw std::overflow_error("HashMap is full");
            }
        }
        table[index].push_front(entry);
    }

    V* find(int index, const K& key, vector<list<Entry<K,V>>>& table) {
        int originalIndex = index;
        while (table[index].size() > 0) {
            if (table[index].front().key == key) {
                return &table[index].front().value;
            }
            index = (index + 1) % table.size();
            if (index == originalIndex) {
                break;
            }
        }
        return nullptr;
    }
};