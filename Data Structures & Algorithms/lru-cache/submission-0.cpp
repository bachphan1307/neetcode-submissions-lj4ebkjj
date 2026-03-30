#include <unordered_map>
#include <list>

class LRUCache {
    int cap;
    // Store: key
    std::list<int> recent; 
    // Store: key -> {value, iterator to position in 'recent'}
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        // Move the accessed key to the front (Most Recently Used)
        recent.erase(cache[key].second);
        recent.push_front(key);
        
        // Update the iterator in the map
        cache[key].second = recent.begin();
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists: update value and move to front
            recent.erase(cache[key].second);
        } else if (cache.size() >= cap) {
            // Cache full: remove Least Recently Used (back of the list)
            int lruKey = recent.back();
            recent.pop_back();
            cache.erase(lruKey);
        }
        
        recent.push_front(key);
        cache[key] = {value, recent.begin()};
    }
};