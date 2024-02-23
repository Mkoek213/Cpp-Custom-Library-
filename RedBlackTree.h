//RedBlackTree implementation so i can implement Map then
#ifndef R_B_TREE_H
#define R_B_TREE_H  
#include <iostream>
#include <vector>
using namespace std;

template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node* parent;
    Node* left;
    Node*right;
    int color;
};

template <typename K, typename V>
using NodePtr = Node<K, V>*;

template <typename K, typename V>
class RedBlackTree{
    private:
        NodePtr<K, V> root;
        NodePtr<K, V> TNULL;

        void initializeNULLNode(NodePtr<K, V> node, NodePtr<K, V> parent){
            node->key = K();
            node->value = V();
            node->parent = parent;
            node->left = nullptr;
            node->right = nullptr;
            node->color = 0; //1 is red, 0 is black
        }

        // Preorder
        void preOrderHelper(NodePtr<K, V> node){
            if (node != TNULL){
                cout << node->value << " ";
                preOrderHelper(node->left);
                preOrderHelper(node->right);
            }
        }

        //Inorder
        void inOrderHelper(NodePtr<K, V> node){
            if (node != TNULL){
                inOrderHelper(node->left);
                cout << node->value << " ";
                inOrderHelper(node->right);
            }
        }

        // Post order
        void postOrderHelper(NodePtr<K, V> node){
            if (node != TNULL){
                postOrderHelper(node->left);
                postOrderHelper(node->right);
                cout << node->value << " ";
            }
        }

        NodePtr<K, V>searchTreeHelper(NodePtr<K, V> node, K search_key){
            if (node == TNULL || search_key == node->key){
                return node;
            }

            if (search_key < node->key){
                return searchTreeHelper(node->left, search_key);
            }else{
                return searchTreeHelper(node->right, search_key);
            }
        }

        // For balancing the tree after deletion
        void deleteFix(NodePtr<K, V> node_to_delete){
            NodePtr<K, V> sibling_node;
            while (node_to_delete != root && node_to_delete->color == 0){
                if (node_to_delete == node_to_delete->parent->left){
                    sibling_node = node_to_delete->parent->right;
                    if (sibling_node->color == 1){
                        sibling_node->color = 0;
                        node_to_delete->parent->color = 1;
                        leftRotate(node_to_delete->parent);
                        sibling_node = node_to_delete->parent->right;
                    }

                    if (sibling_node->left->color == 0 && sibling_node->right->color == 0){
                        sibling_node->color = 1;
                        node_to_delete = node_to_delete->parent;
                    }else{
                        if (sibling_node->right->color == 0){
                            sibling_node->left->color = 0;
                            sibling_node->color = 1;
                            rightRotate(sibling_node);
                            sibling_node = node_to_delete->parent->right;
                        }

                        sibling_node->color = node_to_delete->parent->color;
                        node_to_delete->parent->color = 0;
                        sibling_node->right->color = 0;
                        leftRotate(node_to_delete->parent);
                        node_to_delete = root;
                    }
                }else{
                    sibling_node = node_to_delete->parent->left;
                    if (sibling_node->color == 1){
                        sibling_node->color = 0;
                        node_to_delete->parent->color = 1;
                        rightRotate(node_to_delete->parent);
                        sibling_node = node_to_delete->parent->left;
                    }

                    if (sibling_node->left->color == 0 && sibling_node->right->color == 0){
                        sibling_node->color = 1;
                        node_to_delete = node_to_delete->parent;
                    }else{
                        if (sibling_node->left->color == 0){
                            sibling_node->right->color = 0;
                            sibling_node->color = 1;
                            leftRotate(sibling_node);
                            sibling_node = node_to_delete->parent->left;
                        }
                        
                        sibling_node->color = node_to_delete->parent->color;
                        node_to_delete->parent->color = 0;
                        sibling_node->left->color = 0;
                        rightRotate(node_to_delete->parent);
                        node_to_delete = root;
                    }
                }
            }
            node_to_delete->color = 0;
        }

        void transplant(NodePtr<K, V> u, NodePtr<K, V> v){
            if (u->parent == nullptr){
                root = v;
            }else if (u == u->parent->left){
                u->parent->left = v;
            }else{
                u->parent->right = v;
            }
            v->parent = u->parent;
        }

        int countOccurenceHelper(NodePtr<K, V> node, K search_key){
            std::vector <NodePtr<K, V>> tab;
            NodePtr<K, V> curr = node;
            int count = 0;
            while (curr != TNULL or tab.size() != 0){
                while (curr != TNULL){
                    tab.push_back(curr);
                    curr = curr->left;
                }
                curr = tab[tab.size() - 1];
                tab.pop_back();
                if (curr->key == search_key){
                    count++;
                }
                curr = curr->right;
            }
            return count;
        }

        //function to check if node appears in tree by its adress
        bool isNodeInTreeHelper(NodePtr<K, V> root, NodePtr<K, V> target_node){
            if (root == TNULL || target_node == TNULL){
                return false;
            }
            if (root == target_node){
                return true;
            }

            bool leftSearch = isNodeInTreeHelper(root->left, target_node);
            bool rightSearch = isNodeInTreeHelper(root->right, target_node);
            return leftSearch || rightSearch;
        }

        void deleteNodeHelper(NodePtr<K, V> node, K search_key, size_t &map_size){
            NodePtr<K, V> z = TNULL; //The node to be deleted from the Red-Black Tree.
            NodePtr<K, V> x; //The node that will be spliced out or removed from the Red-Black Tree. It is typically the minimum node in the right subtree of z or the maximum node in the left subtree of z.
            NodePtr<K, V> y; //A temporary node used during the deletion process. It may represent the node that replaces z in the Red-Black Tree.
            while (node != TNULL){
                if (node->key == search_key){
                    z = node;
                    map_size--;
                    break;
                }
                if (node->key <= search_key){
                    node = node->right;
                }else{
                    node = node->left;
                }
            }

            if (z == TNULL){
                throw std::runtime_error("Key not found in the map");
            }

            y = z;
            int y_original_color = y->color;
            if (z->left == TNULL){
                x = z->right;
                transplant(z, z->right);
            }else if (z->right == TNULL){
                x = z->left;
                transplant(z, z->left);
            }else{
                y = minimum(z->right);
                y_original_color = y->color;
                x = y->right;
                if (y->parent == z){
                    x->parent = y;
                }else{
                    transplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }

                transplant(z, y);
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
            }
            delete z;
            if (y_original_color == 0){
                deleteFix(x);
            }
        }

        // For balancing the tree after insertion
        void insertFix(NodePtr<K, V> new_node){
            NodePtr<K, V> uncle;
            while (new_node->parent->color == 1){
                if (new_node->parent == new_node->parent->parent->right){
                    uncle = new_node->parent->parent->left;
                    if (uncle->color == 1){
                        uncle->color = 0;
                        new_node->parent->color = 0;
                        new_node->parent->parent->color = 1;
                        new_node = new_node->parent->parent;
                    }else{
                        if (new_node == new_node->parent->left){
                            new_node = new_node->parent;
                            rightRotate(new_node);
                        }
                        new_node->parent->color = 0;
                        new_node->parent->parent->color = 1;
                        leftRotate(new_node->parent->parent);
                    }
                }else{
                    uncle = new_node->parent->parent->right;

                    if (uncle->color == 1){
                        uncle->color = 0;
                        new_node->parent->color = 0;
                        new_node->parent->parent->color = 1;
                        new_node = new_node->parent->parent;
                    }else{
                        if (new_node == new_node->parent->right){
                            new_node = new_node->parent;
                            leftRotate(new_node);
                        }
                        new_node->parent->color = 0;
                        new_node->parent->parent->color = 1;
                        rightRotate(new_node->parent->parent);
                    }
                }
                if (new_node == root){
                    break;
                }
            }
            root->color = 0;
        }

        void printHelper(NodePtr<K, V> root, string indent, bool last){
            if (root != TNULL){
                cout << indent;
                if (last){
                    cout << "R----";
                    indent += "   ";
                }else{
                    cout << "L----";
                    indent += "|  ";
                }
                string sColor = root->color ? "RED" : "BLACK";
                cout << root->value << "(" << sColor << ")" << endl;
                printHelper(root->left, indent, false);
                printHelper(root->right, indent, true);
            }
        }

        public:
            RedBlackTree(){
                TNULL = new Node<K, V>;
                TNULL->color = 0;
                TNULL->left = nullptr;
                TNULL->right = nullptr;
                root = TNULL;
            }

            void preorder(){
                preOrderHelper(this->root);
            }

            void inorder(){
                inOrderHelper(this->root);
            }

            void postorder(){
                postOrderHelper(this->root);
            }

            NodePtr<K, V> getTNULL(){
                return this->TNULL;
            }

            NodePtr<K, V> searchTree(K search_key){
                return searchTreeHelper(this->root, search_key);
            }

            NodePtr<K, V> minimum(NodePtr<K, V> node){
                while(node->left != TNULL){
                    node = node->left;
                }
                return node;
            }

            NodePtr<K, V> maximum(NodePtr<K, V> node){
                while (node->right != TNULL){
                    node = node->right;
                }
                return node;
            }

            NodePtr<K, V> successor(NodePtr<K, V> node){
                if (node->right != TNULL){
                    return minimum(node->right);
                }
                NodePtr<K, V> y = node->parent;
                  
                while (y != TNULL && node == y->right){
                    node = y;
                    y = y->parent;
                }
                return y;
            }

            NodePtr<K, V> predecessor(NodePtr<K, V> node){
                if (node->left != TNULL){
                    return maximum(node->left);
                }

                NodePtr<K, V> y = node->parent;
                while (y != TNULL && node == y->left){
                    node = y;
                    y = y->parent;
                }
                return y;
            }

            void leftRotate(NodePtr<K, V> node){
                NodePtr<K, V> y = node->right;
                node->right = y->left;
                if (y->left != TNULL){
                    y->left->parent = node;
                }
                y->parent = node->parent;
                if (node->parent == nullptr){
                    this->root = y;
                }else if (node == node->parent->left){
                    node->parent->left = y;
                }else{
                    node->parent->right = y;
                }
                y->left = node;
                node->parent = y;
            }

            void rightRotate(NodePtr<K, V> node){
                NodePtr<K, V> y = node->left;
                node->left = y->right;
                if (y->right != TNULL){
                    y->right->parent = node;
                }
                y->parent = node->parent;
                if (node->parent == nullptr){
                    this->root = y;
                }else if (node == node->parent->right){
                    node->parent->right = y;
                }else{
                    node->parent->left = y;
                }
                y->right = node;
                node->parent = y;
            }

            void insert(K key, V value){
                NodePtr<K, V> node = new Node<K, V>;
                node->parent = nullptr;
                node->key = key;
                node->value = value;
                node->left = TNULL;
                node->right = TNULL;
                node->color = 1;

                NodePtr<K, V> y = nullptr;
                NodePtr<K, V> x = this->root;

                while (x != TNULL){
                    y = x;
                    if (node->key < x->key){
                        x = x->left;
                    }else{
                        x = x->right;
                    }
                }
                node->parent = y;
                if (y == nullptr){
                    root = node;
                }else if (node->key < y->key){
                    y->left = node;
                }else{
                    y->right = node;
                }

                if (node->parent == nullptr){
                    node->color = 0;
                    return;
                }
                if (node->parent->parent == nullptr){
                    return;
                }
                insertFix(node);
            }

            NodePtr<K, V> getRoot(){
                return this->root;
            }

            int countOccurence(K search_key){
                return countOccurenceHelper(this->root, search_key);
            }

            void deleteNodeByPointer(NodePtr<K, V> node_to_remove, size_t &map_size){
                if (isNodeInTreeHelper(this->root, node_to_remove)){
                    K key = node_to_remove->key;
                    deleteNodeHelper(this->root, key, map_size);
                }else{
                    throw std::runtime_error("Element not found in map");
                }
            }

            bool isNodeInTree(NodePtr<K, V> target_node){
                return isNodeInTreeHelper(this->root, target_node);
            }

            void deleteNodeByKey(K key, size_t &map_size){
                while (countOccurenceHelper(this->root, key) != 0){
                    deleteNodeHelper(this->root, key, map_size);
                }
            }

            void clear(){
                this->root = nullptr;
            }

            void printTree(){
                if (root){
                    printHelper(this->root, "", true);
                }
            }
};
#endif