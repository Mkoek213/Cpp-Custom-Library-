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
                delete_BST(this->root);
            }
            //Access to non-const list:
            void inorder_traversal(); //Function to display bst in non-decrasing order
            static void inorder_traversal(Node* root); //Function to display bst in non-decrasing order
            void preorder_traversal(); //Function to display bst. Preorder traversal first visits the root node and then traverses the left and the right subtree. It is used to create a copy of the tree.
            static void preorder_traversal(Node* root); //Function to display bst. Preorder traversal first visits the root node and then traverses the left and the right subtree. It is used to create a copy of the tree.
            void postorder_traversal(); //Function to display bst. Postorder traversal first traverses the left and the right subtree and then visits the root node. It is used to delete the tree.
            static void postorder_traversal(Node* root); //Function to display bst. Postorder traversal first traverses the left and the right subtree and then visits the root node. It is used to delete the tree.
            void print_level(size_t level); //It prints all the nodes at a particular level of the BST.
            static void print_level(Node* root, size_t level); //It prints all the nodes at a particular level of the BST.
            void print_leafs(); //It prints all leafs.
            static void print_leafs(Node* root); //It prints all leafs.
            Node* get_smallest(); //It is used to return the node with the smallest value in the BST.
            static Node* get_smallest(Node* root); //It is used to return the node with the smallest value in the BST.
            Node* get_largest(); //It is used to return the node with the largest value in the BST.
            static Node* get_largest(Node* root); //It is used to return the node with the largest value in the BST.
            Node* search(const T& key); //It is used to search for specific key in BST.
            static Node* search(Node* root, const T& key); //It is used to search for specific key in BST.
            // Capacity getters:
            size_t get_size()const; //Returns the number of nodes in the bst.
            bool empty()const; //Returns whether the bst is empty(1) or not(0).
            size_t get_height()const; //Returns height of BST.
            static size_t get_height(Node* root); //Returns height of BST.
            //Modifiers:
            void swap(Collections::BST<T>& bst); //This function is used to swap the contents of one list with another list of the same type.
            void insert(const T& key); //Inserts new elements in the bst at the leaf.
            void delete_node(const T& key); // It is used to delete a node with specific key from the BST.
            //Iterators:
            Node* begin(); //begin() function returns an iterator pointing to the root of the list.
        private:

            Node* root;
            size_t size;

            Node* newNode(const T& key){
                try{
                    Node* node = new Node(key);
                    return node;
                }catch (const std::bad_alloc& e){
                    std::cerr << "Heap Overflow: " << e.what() << std::endl;
                    exit(EXIT_FAILURE);
                }
            }

            Node* insert(Node* root, const T& key){
                if (root == nullptr){
                    root = newNode(key);
                }
                if (key > root->key){
                    root->right = insert(root->right, key);
                }else if (key < root->key){
                    root->left = insert(root->left, key);
                }
                return root;
            }

            Node* search_own(Node* root, const T& key){
                if (root == nullptr || root->key == key){
                    return root;
                }
                if (key > root->key){
                    return search_own(root->right, key);
                }
                return search_own(root->left, key);
            }

            void inorder_traversal_own(Node* current){
                if (current == nullptr){
                    return;
                }
                inorder_traversal_own(current->left);
                std::cout << current->key << " ";
                inorder_traversal_own(current->right);
            }

            void preorder_traversal_own(Node* current){
                if (current == nullptr){
                    return;
                }
                std::cout << current->key << " ";
                preorder_traversal_own(current->left);
                preorder_traversal_own(current->right);
            }

            void postorder_traversal_own(Node* current){
                if (current == nullptr){
                    return;
                }
                postorder_traversal_own(current->left);
                postorder_traversal_own(current->right);
                std::cout << current->key << " ";
            }

            void print_level_own(Node* root, size_t level){
                if (root == nullptr){
                    return;
                }
                if (level == 1){
                    std::cout << root->key << " ";
                }
                print_level_own(root->left, level - 1);
                print_level_own(root->right, level - 1);
            }

            void print_leafs_own(Node* current){
                if (current == nullptr){
                    return;
                }
                if (current->left == nullptr && current->right == nullptr){
                    std::cout << current->key << " ";
                    return;
                }
                if (current->left != nullptr){
                    print_leafs_own(current->left);
                }
                if (current->right != nullptr){
                    print_leafs_own(current->right);
                }
            }

            Node* get_smallest_own(Node* current){
                if (current == nullptr){
                    return current;
                }
                while (current->left != nullptr){
                    current = current->left;
                }
                return current;
            }

            Node* get_largest_own(Node* current){
                if (current == nullptr){
                    return current;
                }
                while (current->right != nullptr){
                    current = current->right;
                }
                return current;
            }

            size_t get_height_own(Node* current)const{
                if (current == nullptr){
                    return 0;
                }
                size_t l_depth = get_height_own(current->left);
                size_t r_depth = get_height_own(current->right);
                if (l_depth > r_depth){
                    return (l_depth + 1);
                }else{
                    return (r_depth + 1);
                }
            }

            Node* delete_node(Node* root, const T& key){
                if (root == nullptr){
                    return root;
                }
                if (key > root->key){
                    root->right = delete_node(root->right, key);
                }else if (key < root->key){
                    root->left = delete_node(root->left, key);
                }else{
                    if (root->left == nullptr){
                        Node* temp = root->right;
                        free(root);
                        return temp;
                    }else if (root->right == nullptr){
                        Node* temp = root->left;
                        free(root);
                        return temp;
                    }
                    Node* temp = get_smallest(root->right);
                    root->key = temp->key;
                    root->right = delete_node(root->right, temp->key);
                }
                return root;
            }

            void delete_BST(Node* root) {
                if (root != nullptr) {
                    delete_BST(root->left);
                    delete_BST(root->right);
                    delete root;
                }
            }

    };
}

template <typename T>
void Collections::BST<T>::inorder_traversal(){
    inorder_traversal_own(this->root);
}

template <typename T>
void Collections::BST<T>::inorder_traversal(Node* bst){
    if (bst == nullptr){
        return;
    }
    inorder_traversal(bst->left);
    std::cout << bst->key << " ";
    inorder_traversal(bst->right);
}

template <typename T>
void Collections::BST<T>::preorder_traversal(){
    preorder_traversal_own(this->root);
}

template <typename T>
void Collections::BST<T>::preorder_traversal(Node* bst){
    if (bst == nullptr){
        return;
    }
    std::cout << bst->key << " ";
    preorder_traversal(bst->left);
    preorder_traversal(bst->right);
}

template <typename T>
void Collections::BST<T>::postorder_traversal(){
    postorder_traversal_own(this->root);
}

template <typename T>
void Collections::BST<T>::postorder_traversal(Node* bst){
    if (bst == nullptr){
        return;
    }
    postorder_traversal(bst->left);
    postorder_traversal(bst->right);
    std::cout << bst->key << " ";
}

template <typename T>
void Collections::BST<T>::print_level(size_t level){
    print_level_own(this->root, level);
}

template <typename T>
void Collections::BST<T>::print_level(Node* bst, size_t level){
    if (bst == nullptr){
        return;
    }
    if (level == 1){
        std::cout << bst->key << " ";
    }
    print_level(bst->left, level - 1);
    print_level(bst->right, level - 1);
}

template <typename T>
void Collections::BST<T>::print_leafs(){
    print_leafs_own(this->root);
}

template <typename T>
void Collections::BST<T>::print_leafs(Node* bst){
    if (bst == nullptr){
        return;
    }
    if (bst->left == nullptr && bst->right == nullptr){
        std::cout << bst->key << " ";
        return;
    }
    if (bst->left != nullptr){
        print_leafs(bst->left);
    }
    if (bst->right != nullptr){
        print_leafs(bst->right);
    }
}

template <typename T>
typename Collections::BST<T>::Node* Collections::BST<T>::get_smallest(){
    return get_smallest_own(this->root);
}

template <typename T>
typename Collections::BST<T>::Node* Collections::BST<T>::get_smallest(Node* bst){
    if (bst == nullptr){
        return bst;
    }
    while (bst->left != nullptr){
        bst = bst->left;
    }
    return bst;
}

template <typename T>
typename Collections::BST<T>::Node* Collections::BST<T>::get_largest(){
    return get_largest_own(this->root);
}

template <typename T>
typename Collections::BST<T>::Node* Collections::BST<T>::get_largest(Node* bst){
    if (bst == nullptr){
        return bst;
    }
    while (bst->right != nullptr){
        bst = bst->right;
    }
    return bst;
}

template <typename T>
typename Collections::BST<T>::Node* Collections::BST<T>::search(const T& key){
    return search_own(this->root, key);
}

template <typename T>
typename Collections::BST<T>::Node* Collections::BST<T>::search(Node* bst, const T& key){
    if (bst == nullptr || bst->key == key){
        return bst;
    }
    if (key > bst->key){
        return search(bst->right, key);
    }
    return search(bst->left, key);
}

template <typename T>
size_t Collections::BST<T>::get_size()const{
    return this->size;
}

template <typename T>
bool Collections::BST<T>::empty()const{
    return (this->size == 0);
}

template <typename T>
size_t Collections::BST<T>::get_height()const{
    return get_height_own(this->root);
}

template <typename T>
size_t Collections::BST<T>::get_height(Node* bst){
    if (bst == nullptr){
        return 0;
    }
    size_t l_depth = get_height(bst->left);
    size_t r_depth = get_height(bst->right);
    if (l_depth > r_depth){
        return (l_depth + 1);
    }else{
        return (r_depth + 1);
    }
}

template <typename T>
void Collections::BST<T>::swap(Collections::BST<T>& bst){
    Node* temp = this->root;
    this->root = bst.root;
    bst.root = temp;
    size_t temp_size = this->size;
    this->size = bst.size;
    bst.size = temp_size;
}

template <typename T>
void Collections::BST<T>::insert(const T& key){
    Node* search_node = search(root, key);
    if (search_node != nullptr){
        return;
    }
    Node* new_root = insert(this->root, key);
    this->root = new_root;
    this->size++;
}

template <typename T>
void Collections::BST<T>::delete_node(const T& key){
    Node* search_node = search(this->root, key);
    if (search_node == nullptr){
        return;
    }
    Node* new_root = delete_node(this->root, key);
    this->root = new_root;
    this->size--;
}

template <typename T>
typename Collections::BST<T>::Node* Collections::BST<T>::begin(){
    return this->root;
}

