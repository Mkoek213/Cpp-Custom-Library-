#pragma once
#include <cstddef> 
#include <initializer_list>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>


namespace Collections{
    template <typename T>
    class Queue{
        public:
            //Constructors and destructors:
            Queue(): size_(), front_(nullptr), rear_(nullptr) {} //default constructor
            Queue(std::initializer_list<T> values): size_(), front_(nullptr), rear_(nullptr){ //constructor with values: Collections::set<int> set = {1,2,3,4,5}
                for (const T& value : values){
                    enqueue(value);
                }
            }
            ~Queue(){} //default destructor
            
            //Access to non-const queue:
            T& get_front(); //get first element
            T& get_back(); //get last element
            //Capacity getters:
            size_t get_size()const; //returns the size of the queue.
            bool empty()const; //returns whether the queue is empty. It return true if the queue is empty otherwise returns false.
            //Modifiers:
            void enqueue(const T& value); //insert the specified element in the queue, at the end
            void dequeue(); //function to dequeue the front element, delete at the beginning
            void clear(); //deletes/clears all the elements from the set.
            void swap(Collections::Queue<T>& que_to_swap); //exchange the contents of two queues but the queues must be of the same value type, although sizes may differ.
            static void swap(Collections::Queue<T>& que1_to_swap, Collections::Queue<T>& que2_to_swap); //same as above
            void display()const; //display the queue
            static void display(const Collections::Queue<T>& que_to_display);
            //Iterators:
            T* begin(); //returns pointer to the first element
            T* end(); //returns pointer to the last element
        private:
            struct Node{
                T value;
                Node* next;
                Node(const T& value) : value(value), next(nullptr) {}
            };
            size_t size_;
            Node* front_;
            Node* rear_; 

            Node* newNode(T value){
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
T& Collections::Queue<T>::get_front(){
    if (front_ == nullptr){ //queue was empty
        throw std::runtime_error("Queue is empty, can not get first element");
    }
    return front_->value;
}

template <typename T>
T& Collections::Queue<T>::get_back(){
    if (rear_ == nullptr){ //queue was empty
        throw std::runtime_error("Queue is empty, can not get last element");
    }
    return rear_->value;
}

template <typename T>
size_t Collections::Queue<T>::get_size()const{
    return size_;
}

template <typename T>
bool Collections::Queue<T>::empty()const{
    return (size_ == 0)? true : false;
}

template <typename T>
void Collections::Queue<T>::enqueue(const T& value){
    Node* node = newNode(value);
    if (front_ == nullptr){ //queue was empty
        // initialize both front and rear
        front_ = node; 
        rear_ = node;
    }else{
        // update rear
        rear_->next = node; 
        rear_ = node;
    }
    size_++;
}

template <typename T>
void Collections::Queue<T>::dequeue(){
    if (front_ == nullptr){ //queue was empty
        throw std::runtime_error("Can not remove from empty Queue");
    }
    Node* temp = front_;
    front_ = front_->next;
    if (front_ == nullptr){
        rear_ = nullptr;
    }
    delete temp;
    size_ --;
}

template <typename T>
void Collections::Queue<T>::clear(){
    while (front_ != nullptr){
        dequeue();
    }
}

template <typename T>
void Collections::Queue<T>::swap(Collections::Queue<T>& que_to_swap){
    Node* temp_front = this->front_;
    this->front_ = que_to_swap.front_;
    que_to_swap.front_ = temp_front;

    Node* temp_rear = this->rear_;
    this->rear_ = que_to_swap.rear_;
    que_to_swap.rear_ = temp_rear;

    size_t temp_size = this->size_;
    this->size_ = que_to_swap.size_;
    que_to_swap.size_ = temp_size;
}

template <typename T>
void Collections::Queue<T>::swap(Collections::Queue<T>& que1_to_swap, Collections::Queue<T>& que2_to_swap){
    Node* temp_front = que1_to_swap.front_;
    que1_to_swap.front_ = que2_to_swap.front_;
    que2_to_swap.front_ = temp_front;

    Node* temp_rear = que1_to_swap.rear_;
    que1_to_swap.rear_ = que2_to_swap.rear_;
    que2_to_swap.rear_ = temp_rear;

    size_t temp_size = que1_to_swap.size_;
    que1_to_swap.size_ = que2_to_swap.size_;
    que2_to_swap.size_ = temp_size;
}

template <typename T>
void Collections::Queue<T>::display()const{
    Node* current = this->front_;
    while (current != nullptr){
        std::cout << current->value << " ";
        current = current->next;
    }
}

template <typename T>
void Collections::Queue<T>::display(const Collections::Queue<T>& que_to_display){
    Node* current = que_to_display.front_;
    while (current != nullptr){
        std::cout << current->value << " ";
        current = current->next;
    }
}

template <typename T>
T* Collections::Queue<T>::begin(){
    if (this->front_ == nullptr){
        return nullptr;
    }
    return &front_->value;
}

template <typename T>
T* Collections::Queue<T>::end(){
    if (this->rear_ == nullptr){
        return nullptr;
    }
    return &rear_->value;
}