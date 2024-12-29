#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // Doubly linked list to store key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> map; // Hashmap to store key and corresponding list iterator

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1; // Key not found
        }
        // Move the accessed key-value pair to the front of the list
        auto it = map[key];
        cache.splice(cache.begin(), cache, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // If key exists, update its value and move it to the front
            auto it = map[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
        } else {
            // If key does not exist
            if (cache.size() == capacity) {
                // Evict the least recently used key (last element in the list)
                auto lru = cache.back();
                map.erase(lru.first);
                cache.pop_back();
            }
            // Insert the new key-value pair at the front of the list
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
    }
};
