#include <iostream>
#include <unordered_map>
#include <list>
#include <thread>
#include <chrono>
#include <memory>
#include <assert.h>

using namespace std;

class LRUCache {
    private:
        int capacity;
        list<int> keys;
        unordered_map<int, pair<int, list<int>::iterator>> cache;
    public:
        LRUCache(int cap) : capacity(cap) {
            cache.clear();
            keys.clear();
        }

        int get(int key){
            if(cache.find(key) == cache.end()){
                return -1;
            }
            keys.erase(cache[key].second);
            keys.push_front(key);
            cache[key].second = keys.begin();
            return cache[key].first;
        }

        void put(int key, int value){
            if(cache.find(key) != cache.end()){
                keys.erase(cache[key].second);
            }
            else if(keys.size() == capacity){
                int lru = keys.back();
                keys.pop_back();
                cache.erase(lru);
            }
            keys.push_front(key);
            cache[key] = {value, keys.begin()};
        }

        void remove(int key){
            keys.erase(cache[key].second);
            cache.erase(key);
        }
};

class MultiTierCache {
    private:
        LRUCache ram;
        LRUCache ssd;
        LRUCache hdd;

    public:

        MultiTierCache(int ramCap, int ssdCap, int hddCap)  
            : ram(ramCap), ssd(ssdCap), hdd(hddCap) {}

        int get(int key){
            int val = ram.get(key);
            if(val != -1){
                return val;
            }

            val = ssd.get(key);
            if(val != -1){
                this_thread::sleep_for(chrono::milliseconds(100));
                // ssd.remove(key);
                ram.put(key, val);
                return val;
            }

            val = hdd.get(key);
            if(val != -1){
                this_thread::sleep_for(chrono::milliseconds(1000));
                // hdd.remove(key);
                ram.put(key, val);
                return val;
            }

            return -1;
        }

        void put(int key, int value){
            ram.put(key,value);
        }
};

void testBasicGetAndPut() {
    MultiTierCache cache(100, 2000, 5000); // RAM: 100MB, SSD: 2TB, HDD: 5TB

    cache.put(1, 100); // Insert into RAM
    assert(cache.get(1) == 100); // Should return 100 from RAM

    cache.put(2, 200); // Insert another key
    assert(cache.get(2) == 200); // Should return 200 from RAM
}

void testPromotionFromSSDToRAM() {
    MultiTierCache cache(1, 1, 10); // RAM: 1MB, SSD: 1MB, HDD: 10MB

    cache.put(1, 100); // Insert into RAM
    cache.put(2, 200); // Evicts key 1 to SSD (due to RAM size limit)

    assert(cache.get(1) == 100); // Access key 1, should promote it back to RAM
    assert(cache.get(2) == 200); // Key 2 should still be accessible
}

void testPromotionFromHDDToRAM() {
    MultiTierCache cache(1, 1, 10); // RAM: 1MB, SSD: 1MB, HDD: 10MB

    cache.put(1, 100); // Insert into RAM
    cache.put(2, 200); // Evicts key 1 to SSD
    cache.put(3, 300); // Evicts key 2 to HDD

    assert(cache.get(2) == 200); // Access key 2, should promote it back to RAM
    assert(cache.get(3) == 300); // Access key 3, should promote it to RAM
}

void testRamEviction() {
    MultiTierCache cache(2, 2, 2); // RAM: 2MB, SSD: 2MB, HDD: 2MB

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300); // Evicts key 1 to SSD

    assert(cache.get(1) == 100); // Access key 1, should promote it back to RAM
    assert(cache.get(2) == -1); // Key 2 should now be evicted to SSD
}

void testMultiTierDataFlow() {
    MultiTierCache cache(1, 1, 1); // RAM: 1MB, SSD: 1MB, HDD: 1MB

    cache.put(1, 100); // Insert into RAM
    cache.put(2, 200); // Evicts key 1 to SSD
    cache.put(3, 300); // Evicts key 2 to HDD

    assert(cache.get(1) == 100); // Access key 1, should promote from SSD to RAM
    assert(cache.get(2) == 200); // Access key 2, should promote from HDD to RAM
    assert(cache.get(3) == 300); // Key 3 should remain in HDD
}

void testAccessLatency() {
    MultiTierCache cache(1, 1, 1); // RAM: 1MB, SSD: 1MB, HDD: 1MB

    cache.put(1, 100); // Insert into RAM
    cache.put(2, 200); // Evicts key 1 to SSD
    cache.put(3, 300); // Evicts key 2 to HDD

    auto start = std::chrono::high_resolution_clock::now();
    cache.get(2); // Access key 2 from HDD
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    assert(duration >= 1000); // HDD access should take at least 1000ms
}

int main(){
    
    testBasicGetAndPut();
    testMultiTierDataFlow();
    testPromotionFromHDDToRAM();
    testPromotionFromSSDToRAM();
    testAccessLatency();
    testRamEviction(); 

    return 0;
}