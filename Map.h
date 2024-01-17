// Map.h
#ifndef MAP_H
#define MAP_H

#include "RedBlackTree.h"
#include <cstddef> 
#include <initializer_list>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
namespace Collections{
template <typename K, typename V>
class Map {
private:
    RedBlackTree<K, V>* tree;
    size_t size;
public:
    // Constructors and destructors:
    Map() : size(0), tree(new RedBlackTree<K, V>()) {} // Default constructor
    Map(std::initializer_list<std::pair<K, V>> keyValuePairs) : size(0), tree(new RedBlackTree<K, V>()) {// Constructor with values: Collections::Map<int> Map = {{1, "One"}, {2, "Two"}, {3, "Three"}}
        for (const auto& pair : keyValuePairs) {
            tree->insert(pair.first, pair.second);
            size++;
        }
    }
    ~Map() { // Default destructor
        tree->clear();
        delete tree;
    }
    //Access to non-const sets:
    NodePtr<K, V> operator[](const K& key); //This operator is used to reference the element present at the position given inside the operator
    NodePtr<K, V> find(const V& value); //returns the iterator to the element specified if found, else return nullptr
    int count(const V& value); //Returns the number of matches to element with key-value ‘g’ in the map
    //Modifiers:
    Map& operator=(const Map& other); //Assigns contents of a container to a different container, replacing its current content
    void insert(const K& key, const V& value); //insert the specified element in the map
    void erase(NodePtr<K, V> position); // Removes the element at the position pointed by the iterator.
    void erase(const K& key); //Removes the key-value from the map.
    void clear(); //Removes all the elements from the map
    //Capacity getters:
    size_t get_size()const; //Returns the number of elements in the map.
    size_t max_size()const; //Returns the maximum number of elements that the map can hold.
    bool empty()const; //returns true if empty
    //Iterators:
    NodePtr<K, V> begin(); //returns pointer to the first element
    NodePtr<K, V> end(); //returns pointer to the last element
};
}

template <typename K, typename V>
NodePtr<K, V> Collections::Map<K, V>::begin(){
    return tree->minimum(tree->getRoot());
}

template <typename K, typename V>
NodePtr<K, V> Collections::Map<K, V>::end(){
    return tree->maximum(tree->getRoot());
}

#endif