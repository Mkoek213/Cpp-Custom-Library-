// Map.h
#ifndef MAP_H
#define MAP_H

#include "RedBlackTree.h"
namespace Collections{
template <typename Key, typename Value>
class Map {
private:
    RedBlackTree<Key, Value> tree;

public:
    Map();
    ~Map();

    void insert(const Key& key, const Value& value);
    Value* find(const Key& key);
    // ... other member functions ...
};
}

template <typename Key, typename Value>
Collections::Map<Key, Value>::Map() {
    // Constructor implementation, if needed
}

template <typename Key, typename Value>
Collections::Map<Key, Value>::~Map() {
    // Destructor implementation, if needed
}
template <typename Key, typename Value>
void Collections::Map<Key, Value>::insert(const Key& key, const Value& value) {
    tree.insert(key, value);
}

template <typename Key, typename Value>
Value* Collections::Map<Key, Value>::find(const Key& key) {
    return &tree.searchTree(key)->value;
}
#endif