#pragma once
#include <cstddef> 
#include <initializer_list>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>


namespace Collections{
    template <typename T>
    class Set{ 
        public:
            //Constructors and destructors:
            Set(): size_(), root_(nullptr) {} //default constructor
            Set(std::initializer_list<T> values): size_(), root_(nullptr){ //constructor with values: Collections::set<int> set = {1,2,3,4,5}
                for (const T& value : values){
                    root_ = insert(root_, value);
                }
            }
            ~Set(){} //default destructor
            
            //Access to non-const sets:
            T* find(const T& value); //returns the iterator to the element specified if found, else return nullptr
            int count(const T& value); //returns 1 if the specified element is found, else 0
            //Capacity getters:
            size_t get_size()const; //returns size
            bool empty()const; //returns true if empty
            //Modifiers:
            void insert(const T& value); //insert the specified element in the set
            void erase(const T& element_to_delete); //deletion of an element with a set value, if not found return nullptr
            void clear(); //deletes/clears all the elements from the set.
            void swap(Collections::Set<T>& set_to_swap); //swaps the elements of the two sets
            void display()const;
            //Iterators:
            T* begin(); //returns pointer to the first element
            T* end(); //returns pointer to the last element
        private:
            struct TreeNode{
                T value;
                TreeNode* left;
                TreeNode* right;
                TreeNode(const T& value) : value(value), left(nullptr), right(nullptr) {}
            };
            size_t size_;
            TreeNode* root_;

            TreeNode* insert(TreeNode* node, const T& value){
                if (node == nullptr){
                    size_++;
                    return new TreeNode(value);
                }
                if (value < node->value){
                    node->left = insert(node->left, value);
                }else if (value > node->value){
                    node->right = insert(node->right, value);
                }
                //if value already exists, skip
                return node;
            }

            TreeNode* find(TreeNode* node, const T& value)const{
                if (node == nullptr || node->value == value){
                    return node;
                }else if( value < node->value){
                    return find(node->left, value);
                }else{ //value > node->value
                    return find(node->right, value);
                }
            }

            void display(const TreeNode* node)const{
                if (node != nullptr)
                {
                    display(node->left);
                    std::cout<<node->value<<" ";
                    display(node->right);
                }
            }

            TreeNode* erase(TreeNode* root2, const T& value){
                if (root2 == nullptr){
                    return root2;
                }

                // Recursive calls for ancestors of
                // node to be deleted
                if (value < root2->value){
                    root2->left = erase(root2->left, value);
                    return root2;
                }else if (value > root2->value){
                    root2->right = erase(root2->right, value);
                    return root2;
                }

                // We reach here when root is the node
                // to be deleted.

                // If one of the children is empty
                if (root2->left == nullptr){
                    TreeNode* temp = root2->right;
                    delete root2;
                    size_--;
                    return temp;
                }else if (root2->right == nullptr){
                    TreeNode* temp = root2->left;
                    delete root2;
                    size_--;
                    return temp;
                }

                // If both children exist
                else{
                    TreeNode* successorParent = root2;

                    //Find successor
                    TreeNode* successor = root2->right;
                    while (successor->left != nullptr){
                        successorParent = successor;
                        successor = successor->left;
                    }

                    // Delete successor.  Since successor
                    // is always left child of its parent
                    // we can safely make successor's right
                    // right child as left of its parent.
                    // If there is no succ, then assign
                    // succ->right to succParent->right
                    if (successorParent != root2){
                        successorParent->left = successor->right;
                    }else{
                        successorParent->right = successor->right;
                    }

                    // Copy Successor value to root
                    root2->value = successor->value;

                    delete successor;
                    size_--;
                    return root2;
                }
            }

            void clear(TreeNode* node){
                if (root_ != nullptr){
                    if (node->left != nullptr){
                        clear(node->left);
                    }
                    if (node->right != nullptr){
                        clear(node->right);
                    }
                    delete node;
                }
                root_ = nullptr;
                size_ = 0;
            }

            TreeNode* begin(TreeNode* node){
                if (node != nullptr){
                    if (node->left == nullptr){
                        return node;
                    }else{
                        return begin(node->left);
                    }
                }else{
                    return node;
                }
            }

            TreeNode* end(TreeNode* node)const{
                if (node != nullptr){
                    if (node->right == nullptr){
                        return node;
                    }else{
                        return end(node->right);
                    }
                }else{
                    return node;
                }
            }
    };
}

template <typename T>
T* Collections::Set<T>::find(const T& value){
    TreeNode* node = find(root_, value);
    return &node->value;
}

template <typename T>
int Collections::Set<T>::count(const T& value){
    TreeNode* node = find(root_, value);
    return (node != nullptr)? 1 : 0;
}

template <typename T>
size_t Collections::Set<T>::get_size()const{
    return size_;
}

template <typename T>
bool Collections::Set<T>::empty()const{
    return size_ == 0;
}

template <typename T>
void Collections::Set<T>::insert(const T& value){
    root_ = insert(root_, value);
}

template <typename T>
void Collections::Set<T>::erase(const T& value){
    root_ = erase(root_, value);
}

template <typename T>
void Collections::Set<T>::clear(){
    clear(root_);
}

template <typename T>
void Collections::Set<T>::swap(Collections::Set<T>& set_to_swap){
    TreeNode* temp_root = this->root_;
    this->root_ = set_to_swap.root_;
    set_to_swap.root_ = temp_root;
    size_t temp_size = this->size_;
    this->size_ = set_to_swap.size_;
    set_to_swap.size_ = temp_size;
}

template <typename T>
void Collections::Set<T>::display()const
{
    display(root_);
}

template <typename T>
T* Collections::Set<T>::begin()
{
    TreeNode* node = begin(root_);
    return &node->value;
}

template <typename T>
T* Collections::Set<T>::end()
{
    TreeNode* node = end(root_);
    return &node->value;
}