#pragma once
#include <cstddef> 
#include <initializer_list>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>


namespace Collections{
    template <typename T>
    class List{
        private:
            struct Node{
                T value;
                Node* prev;
                Node* next;
                Node(const T& value) : value(value), prev(nullptr), next(nullptr) {}
            };
        public:
            //Constructors and destructors:
            List(): size(), head(nullptr) {} //default constructor
            List(std::initializer_list<T> values): size(), head(nullptr){ //constructor with values: Collections::List<int> list = {1,2,3,4,5}
                for (const T& value : values){
                    push_back(value);
                }
            }
            ~List(){ //default destructor
                clear();
            }
            //Access to non-const list:
            T& get_front(); //Returns the value of the first element in the list.
            T& get_back(); //Returns the value of the last element in the list.
            void display_list(); //Function to display list.
            //Capacity getters:
            size_t get_size()const; //Returns the number of elements in the list.
            bool empty()const; //Returns whether the list is empty(1) or not(0).
            //Modifiers:
            void operator=(Collections::List<T>& list_to_replace); //This operator is used to assign new contents to the container by replacing the existing contents.
            void swap(Collections::List<T>& list_to_replace); //This function is used to swap the contents of one list with another list of the same type.
            void merge(Collections::List<T>& list_to_merge); //Merges two sorted lists into one.
            static void merge(Collections::List<T>& first_to_merge, Collections::List<T>& second_to_merge); //Merges two sorted lists into one.
            void push_front(const T& new_elem); //Adds a new element ‘new_elem’ at the beginning of the list.
            void push_back(const T& new_elem); //Adds a new element ‘new_elem’ at the end of the list.
            void pop_front(); //Removes the first element of the list, and reduces the size of the list by 1.
            void pop_back(); //Removes the last element of the list, and reduces the size of the list by 1.
            void insert(const T& new_elem, size_t index); //Inserts new elements in the list before the element at a specified position.
            void erase(Node* node_to_erase); //Removes a single element from the list.
            void reverse(); //Reverses the list.
            void sort(); //Sorts the list in increasing order.
            void unique(); //Removes all duplicate consecutive elements from the list.
            void clear(); //clear() function is used to remove all the elements of the list container, thus making it size 0.
            //Iterators:
            T* begin(); //begin() function returns an iterator pointing to the first element of the list.
            T* end(); //end() function returns an iterator pointing to the theoretical last element which follows the last element.

            Node* head;
            size_t size;

            Node* newNode(const T& value){
                try{
                    Node* node = new Node(value);
                    return node;
                }catch (const std::bad_alloc& e){
                    std::cerr << "Heap Overflow: " << e.what() << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
    };
}

template <typename T>
void Collections::List<T>::push_back(const T& new_elem){
    Node* new_node = newNode(new_elem);
    if (this->head == nullptr){
        this->head = new_node;
    }else{
        Node* curr = this->head;
        while (curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->prev = curr;
    }
    this->size++;
}

template <typename T>
void Collections::List<T>::clear(){
    while (this->head != nullptr){
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    this->size = 0;
}
