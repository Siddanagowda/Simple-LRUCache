# LRU Cache Implementation

This repository contains a C++ implementation of an LRU (Least Recently Used) Cache. The LRU Cache is a data structure that stores a limited number of key-value pairs and evicts the least recently used items when the cache reaches its capacity.

## Code Explanation

## Class
### Private Members
```text
int capacity: The maximum number of key-value pairs the cache can hold.

list<pair<int, int>> cache: A doubly linked list to store the key-value pairs. The most recently used item is at the front, and the least recently used item is at the back.

unordered_map<int, list<pair<int, int>>::iterator> map: A hashmap to store the key and the corresponding iterator to the list.
```
### Public Members
```text
LRUCache(int capacity): Constructor to initialize the cache with a given capacity.

int get(int key): Method to retrieve the value associated with a key. If the key is found, it moves the key-value pair to the front of the list and returns the value. If the key is not found, it returns -1.

void put(int key, int value): Method to insert or update a key-value pair. If the key already exists, it updates the value and moves the key-value pair to the front of the list. If the key does not exist and the cache is at capacity, it evicts the least recently used item before inserting the new key-value pair at the front of the list.
```

### Example Usage
Example Usage
The main function demonstrates how to use the LRUCache class:

Create an LRUCache object with a capacity of 2.
Insert key-value pairs into the cache using the put method.
Retrieve values using the get method and observe how the cache evicts the least recently used items when it reaches capacity.

```cpp
// Example Usage
int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // return -1 (not found)
    cout << lRUCache.get(3) << endl;    // return 3
    cout << lRUCache.get(4) << endl;    // return 4
    return 0;
}
```
# Run
```bash
g++ -o lru_cache main.cpp
./lru_cache
```
This will compile the main.cpp file and create an executable named lru_cache, which you can then run to see the output.

# License
This project is licensed under the MIT License.
```text

This `README.md` file provides a detailed explanation of the code, including the class structure, methods, and example usage.
This `README.md` file provides a detailed explanation of the code, including the class structure, methods, and example usage.
```
