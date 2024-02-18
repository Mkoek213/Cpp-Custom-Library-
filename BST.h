#pragma once
#include <cstddef> 
#include <initializer_list>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <set>


namespace Collections{
    template <typename T>
    class BST{
        private:
            struct Node{
                T key;
                Node* left;
                Node* right;
                Node(const T& key) : key(key), left(nullptr), right(nullptr) {}
            };
        public:
            //Constructors and destructors:
            BST(): size(), root(nullptr) {} //default constructor
            BST(std::initializer_list<T> keys): size(), root(nullptr){ //constructor with values: Collections::BST<int> bst = {1,2,3,4,5}
                for (const T& key : keys){
                    insert(key);
                }
            }
            ~BST(){ //default destructor
                clear();
            }
            //Access to non-const list:
            Node* get_front(); //Returns the value of the first element in the list.
            Node* get_back(); //Returns the value of the last element in the list.
            void inorder_traversal(); //Function to display bst in non-decrasing order
            static void inorder_traversal(Collections::BST<T> bst); //Function to display bst in non-decrasing order
            void preorder_traversal(); //Function to display bst. Preorder traversal first visits the root node and then traverses the left and the right subtree. It is used to create a copy of the tree.
            static void preorder_traversal(Collections::BST<T> bst); //Function to display bst. Preorder traversal first visits the root node and then traverses the left and the right subtree. It is used to create a copy of the tree.
            void postorder_traversal(); //Function to display bst. Postorder traversal first traverses the left and the right subtree and then visits the root node. It is used to delete the tree.
            static void postorder_traversal(Collections::BST<T> bst); //Function to display bst. Postorder traversal first traverses the left and the right subtree and then visits the root node. It is used to delete the tree.
            void print_level(); //It prints all the nodes at a particular level of the BST.
            static void print_level(Collections::BST<T> bst); //It prints all the nodes at a particular level of the BST.
            void print_leafs(); //It prints all leafs.
            static void print_leafs(Collections::BST<T> bst); //It prints all leafs.
            Node* get_smallest(); //It is used to return the node with the smallest value in the BST.
            static Node* get_smallest(Collections::BST<T> bst); //It is used to return the node with the smallest value in the BST.
            Node* get_largest(); //It is used to return the node with the largest value in the BST.
            static Node* get_largest(Collections::BST<T> bst); //It is used to return the node with the largest value in the BST.
            // Capacity getters:
            size_t get_size()const; //Returns the number of nodes in the bst.
            bool empty()const; //Returns whether the bst is empty(1) or not(0).
            size_t get_height()const; //Returns height of BST.
            static size_t get_height(Collections::BST<T> bst)const; //Returns height of BST.
            //Modifiers:
            void swap(Collections::List<T>& list_to_replace); //This function is used to swap the contents of one list with another list of the same type.
            void insert(const T& key); //Inserts new elements in the bst at the leaf.
            void delete_node(T key); // It is used to delete a node with specific key from the BST.
            //Iterators:
            Node* begin(); //begin() function returns an iterator pointing to the root of the list.

            Node* root;
            size_t size;
    };
}