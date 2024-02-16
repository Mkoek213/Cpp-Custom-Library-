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
            Node* get_front(); //Returns the value of the first element in the list.
            Node* get_back(); //Returns the value of the last element in the list.
            void display_list(); //Function to display list.
            //Capacity getters:
            size_t get_size()const; //Returns the number of elements in the list.
            bool empty()const; //Returns whether the list is empty(1) or not(0).
            //Modifiers:
            void operator=(Collections::List<T>& list_to_replace); //This operator is used to assign new contents to the container by replacing the existing contents.
            void swap(Collections::List<T>& list_to_replace); //This function is used to swap the contents of one list with another list of the same type.
            void merge(Collections::List<T>& list_to_merge); //Merges two sorted lists into one.
            static Collections::List<T> merge(Collections::List<T>& first_to_merge, Collections::List<T>& second_to_merge); //Merges two sorted lists into one.
            void push_front(const T& new_elem); //Adds a new element ‘new_elem’ at the beginning of the list.
            void push_back(const T& new_elem); //Adds a new element ‘new_elem’ at the end of the list.
            void pop_front(); //Removes the first element of the list, and reduces the size of the list by 1.
            void pop_back(); //Removes the last element of the list, and reduces the size of the list by 1.
            void insert(const T& new_elem, size_t index); //Inserts new elements in the list before the element at a specified position.
            void erase(size_t index); //Removes a single element from the list by index.
            void reverse(); //Reverses the list.
            void sort(bool ascending = true); //Sorts the list in increasing order by default, can change ascending to false
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

            Node* merge(Node* list1, Node* list2){ //list1 and list2 are head pointers
                if (list1 == nullptr){
                    return list2;
                }
                if (list2 == nullptr){
                    return list1;
                }
                if (list1->value < list2->value){
                    list1->next = merge(list1->next, list2);
                    list1->next->prev = list1;
                    list1->prev = nullptr;
                    return list1;
                }else{
                    list2->next = merge(list1, list2->next);
                    list2->next->prev = list2;
                    list2->prev = nullptr;
                    return list2;
                }
            }

            Node* mergeSort(Node* temp_head){
                if (temp_head == nullptr || temp_head->next == nullptr){
                    return temp_head;
                }

                Node* second = split(temp_head);

                temp_head = mergeSort(temp_head);
                second = mergeSort(second);
                return merge(temp_head, second);
            }

            Node* split(Node* temp_head){
                Node* fast = temp_head;
                Node* slow = temp_head;
                while (fast->next != nullptr && fast->next->next != nullptr){
                    fast = fast->next->next;
                    slow = slow->next;
                }
                Node* temp = slow->next;
                slow->next = nullptr;
                return temp;
            }
    };
}

template <typename T>
typename Collections::List<T>::Node* Collections::List<T>::get_front(){
    return this->head;
}

template <typename T>
typename Collections::List<T>::Node* Collections::List<T>::get_back(){
    if (this->head == nullptr){
        return this->head;
    }
    Node* curr_node = this->head;
    while (curr_node->next != nullptr){
        curr_node = curr_node->next;
    }
    return curr_node;
}

template <typename T>
void Collections::List<T>::display_list(){
    if (this->head == nullptr){
        return;
    }
    Node* curr_node = this->head;
    while (curr_node->next != nullptr){
        std::cout<<curr_node->value<<" ";
        curr_node = curr_node->next;
    }
    std::cout<<curr_node->value<<" ";
}

template <typename T>
size_t Collections::List<T>::get_size()const{
    return this->size;
}

template <typename T>
bool Collections::List<T>::empty()const{
    return this->size == 0;
}

template <typename T>
void Collections::List<T>::operator=(Collections::List<T>& list_to_replace){
    if (this == &list_to_replace){
        return;
    }
    this->clear();
    Node* curr_node = list_to_replace.head;
    while (curr_node != nullptr){
        push_back(curr_node->value);
        curr_node = curr_node->next;
    }
}

template <typename T>
void Collections::List<T>::swap(Collections::List<T>& list_to_swap){
    if (this == &list_to_swap) {
        return;
    }
    Node* temp_head = this->head;
    this->head = list_to_swap.head;
    list_to_swap.head = temp_head;
    size_t temp_size = this->size;
    this->size = list_to_swap.size;
    list_to_swap.size = temp_size;
}

template <typename T>
void Collections::List<T>::merge(Collections::List<T>& list_to_merge){
    Node* curr_node = list_to_merge.head;
    while (curr_node != nullptr){
        push_back(curr_node->value);
        curr_node = curr_node->next;
    }
}

template <typename T>
Collections::List<T> Collections::List<T>::merge(Collections::List<T>& first_to_merge, Collections::List<T>& second_to_merge){
    Collections::List<int> new_list;
    Node* curr_node = first_to_merge.head;
    while (curr_node != nullptr){
        new_list.push_back(curr_node->value);
        curr_node = curr_node->next;
    }
    curr_node = second_to_merge.head;
    while(curr_node != nullptr){
        new_list.push_back(curr_node->value);
        curr_node = curr_node->next;
    }
    return new_list;
}

template <typename T>
void Collections::List<T>::push_front(const T& value){
    Node* new_node = newNode(value);
    if (this->head == nullptr){
        this->head = new_node;
    }else{
        new_node->next = this->head;
        this->head->prev = new_node;
        this->head = new_node;
    }
    this->size++;
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
void Collections::List<T>::pop_front(){
    if (this->head == nullptr){
        throw std::runtime_error("Can not pop from empty list");
    }else{
        this->head = this->head->next;
    }
    this->size--;
}

template <typename T>
void Collections::List<T>::pop_back(){
    if (this->head == nullptr){
        throw std::runtime_error("Can not pop from empty list");
    }else if (this->head->next == nullptr){
        this->head = nullptr;
    }else{
        Node* curr_node = this->head;
        while (curr_node->next != nullptr){
            curr_node = curr_node->next;
        }
        curr_node->prev->next = nullptr;
    }
    this->size--;
}

template <typename T>
void Collections::List<T>::insert(const T& new_elem, size_t index){
    if (index >= this->size){
        throw std::out_of_range("Index out of range");
    }
    if (index == 0){
        this->push_front(new_elem);
    }else{
        Node* new_node = newNode(new_elem);
        Node* curr_node = this->head;
        for (size_t i = 0; i < index - 1; i++){
            curr_node = curr_node->next;
        }
        curr_node->next->prev = new_node;
        new_node->next = curr_node->next;
        new_node->prev = curr_node;
        curr_node->next = new_node;
        this->size++;
    }
}

template <typename T>
void Collections::List<T>::erase(size_t index){
    if (index >= this->size){
        throw std::out_of_range("Index out of range");
    }
    if (index == 0){
        this->head = this->head->next;
    }else{
    Node* before_to_delete = this->head;
    for (size_t i = 0; i < index - 1; i++){
        before_to_delete = before_to_delete->next;
    }
    Node* temp = before_to_delete->next;
    before_to_delete->next = temp->next;
    delete temp;
    }
    this->size--;
}

template <typename T>
void Collections::List<T>::reverse(){
    if (this->size == 0 || this->size == 1){
        return;
    }
    Node* prev_node = this->head;
    Node* temp_node = this->head;
    Node* curr_node = this->head->next;
    prev_node->next = nullptr;

    while (curr_node != nullptr){
        temp_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node->prev = curr_node;
        prev_node = curr_node;
        curr_node = temp_node;
    }
    this->head = prev_node;
}

template <typename T>
void Collections::List<T>::sort(bool ascending){
    if (this->size == 0 || this->size == 1){
        return;
    }
    if (ascending){
        Node* new_head = mergeSort(this->head);
        this->head = new_head;
    }
}

template <typename T>
void Collections::List<T>::unique(){
    if (this->size == 0 || this->size == 1){
        return;
    }
    std::set<T> set;
    Node* curr_node = this->head;
    while (curr_node != nullptr){
        if (set.count(curr_node->value) == 1){
            Node* temp = curr_node;
            curr_node = curr_node->next;
            if (temp->prev != nullptr){
                temp->prev->next = temp->next;
            }
            if (temp->next != nullptr){
                temp->next->prev = temp->prev;
            }
            delete temp;
            this->size--;
        }else{
            set.insert(curr_node->value);
            curr_node = curr_node->next;
        }
    }
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

template <typename T>
T* Collections::List<T>::begin(){
    return &this->head->value;
}

template <typename T>
T* Collections::List<T>::end(){
    Node* temp = this->head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    return &temp->value;
}