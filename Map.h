// Map.h
#pragma once
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
    RedBlackTree<K, V>* tree_; 
    size_t size_;
public:
    // Constructors and destructors:
    Map() : size_(0), tree_(new RedBlackTree<K, V>()) {} // Default constructor
    Map(std::initializer_list<std::pair<K, V>> keyValuePairs) : size_(0), tree_(new RedBlackTree<K, V>()) {// Constructor with values: Collections::Map<int> Map = {{1, "One"}, {2, "Two"}, {3, "Three"}}
        for (const auto& pair : keyValuePairs) {
            tree_->insert(pair.first, pair.second);
            size_++;
        }
    }
    ~Map() {} // Default destructor

    //Access to non-const sets:
    NodePtr<K, V> operator[](const K& key); //This operator is used to reference the element present at the position given inside the operator
    NodePtr<K, V> find(const K& key); //returns the iterator to the element specified if found, else return nullptr
    bool is_in(const NodePtr<K, V> node)const; //returns the iterator to the element specified if found, else return nullptr
    int count(const K& key); //Returns the number of matches to element with key-value ‘g’ in the map
    //Modifiers:
    void operator=(const Collections::Map<K, V>& other); //Assigns contents of a container to a different container, replacing its current content
    void insert(const K& key, const V& value); //insert the specified element in the map
    void erase(NodePtr<K, V> position); // Removes the element at the position pointed by the iterator.
    void erase(const K& key); //Removes the key-value from the map.
    void clear(); //Removes all the elements from the map
    //Capacity getters:
    size_t get_size()const; //Returns the number of elements in the map.
    bool empty()const; //returns true if empty
    //Iterators:
    NodePtr<K, V> begin(); //returns pointer to the first element
    NodePtr<K, V> end(); //returns pointer to the last element
};
}

template <typename K, typename V>
NodePtr<K, V> Collections::Map<K, V>::operator[](const K& key){
    NodePtr<K, V> search_node = tree_->searchTree(key);
    if (search_node != tree_->getTNULL()){
        return search_node;
    }else{
        return nullptr;
    }
}

template <typename K, typename V>
NodePtr<K, V> Collections::Map<K, V>::find(const K& key){
    NodePtr<K, V> search_node = tree_->searchTree(key);
    if (search_node != tree_->getTNULL()){
        return search_node;
    }else{
        return nullptr;
    }
}

template <typename K, typename V>
bool Collections::Map<K, V>::is_in(NodePtr<K, V> node)const{
    return this->tree_->isNodeInTree(node);
}

template <typename K, typename V>
int Collections::Map<K, V>::count(const K& key){
    return tree_->countOccurence(key);
}

template <typename K, typename V>
void Collections::Map<K, V>::operator=(const Collections::Map<K, V>& map_to_swap) {
    if (map_to_swap.tree_) {
        delete this->tree_;
        this->tree_ = new RedBlackTree<K, V>(*map_to_swap.tree_);
    } else {
        this->tree_ = nullptr;  
    }
    this->size_ = map_to_swap.size_;
}

template <typename K, typename V>
void Collections::Map<K, V>::insert(const K& key, const V& value){
    this->tree_->insert(key, value);
    this->size_++;
}

template <typename K, typename V>
void Collections::Map<K, V>::erase(NodePtr<K, V> node_to_remove){
    this->tree_->deleteNodeByPointer(node_to_remove, this->size_);
}

template <typename K, typename V>
void Collections::Map<K, V>::erase(const K& key){
    this->tree_->deleteNodeByKey(key, this->size_);
}

template <typename K, typename V>
void Collections::Map<K, V>::clear(){
    this->tree_->clear();
    this->size_ = 0;
}

template <typename K, typename V>
size_t Collections::Map<K, V>::get_size()const{
    return this->size_;
}

template <typename K, typename V>
bool Collections::Map<K, V>::empty()const{
    return (this->size_ == 0);
}

template <typename K, typename V>
NodePtr<K, V> Collections::Map<K, V>::begin(){
    return tree_->minimum(tree_->getRoot());
}

template <typename K, typename V>
NodePtr<K, V> Collections::Map<K, V>::end(){
    return tree_->maximum(tree_->getRoot());
}

