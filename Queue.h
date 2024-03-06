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
            Queue(): size(), front(nullptr), rear(nullptr) {} //default constructor
            Queue(std::initializer_list<T> values): size(), front(nullptr), rear(nullptr){ //constructor with values: Collections::set<int> set = {1,2,3,4,5}
                for (const T& value : values){
                    enqueue(value);
                }
            }
            ~Queue(){ //default destructor
                clear();
            }
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
            size_t size;
            Node* front;
            Node* rear;

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
    if (front == nullptr){ //queue was empty
        throw std::runtime_error("Queue is empty, can not get first element");
    }
    return front->value;
}

template <typename T>
T& Collections::Queue<T>::get_back(){
    if (rear == nullptr){ //queue was empty
        throw std::runtime_error("Queue is empty, can not get last element");
    }
    return rear->value;
}

template <typename T>
size_t Collections::Queue<T>::get_size()const{
    return size;
}

template <typename T>
bool Collections::Queue<T>::empty()const{
    return (size == 0)? true : false;
}

template <typename T>
void Collections::Queue<T>::enqueue(const T& value){
    Node* node = newNode(value);
    if (front == nullptr){ //queue was empty
        // initialize both front and rear
        front = node; 
        rear = node;
    }else{
        // update rear
        rear->next = node; 
        rear = node;
    }
    size++;
}

template <typename T>
void Collections::Queue<T>::dequeue(){
    if (front == nullptr){ //queue was empty
        throw std::runtime_error("Can not remove from empty Queue");
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr){
        rear = nullptr;
    }
    delete temp;
    size --;
}

template <typename T>
void Collections::Queue<T>::clear(){
    while (front != nullptr){
        dequeue();
    }
}

template <typename T>
void Collections::Queue<T>::swap(Collections::Queue<T>& que_to_swap){
    Node* temp_front = this->front;
    this->front = que_to_swap.front;
    que_to_swap.front = temp_front;

    Node* temp_rear = this->rear;
    this->rear = que_to_swap.rear;
    que_to_swap.rear = temp_rear;

    size_t temp_size = this->size;
    this->size = que_to_swap.size;
    que_to_swap.size = temp_size;
}

template <typename T>
void Collections::Queue<T>::swap(Collections::Queue<T>& que1_to_swap, Collections::Queue<T>& que2_to_swap){
    Node* temp_front = que1_to_swap.front;
    que1_to_swap.front = que2_to_swap.front;
    que2_to_swap.front = temp_front;

    Node* temp_rear = que1_to_swap.rear;
    que1_to_swap.rear = que2_to_swap.rear;
    que2_to_swap.rear = temp_rear;

    size_t temp_size = que1_to_swap.size;
    que1_to_swap.size = que2_to_swap.size;
    que2_to_swap.size = temp_size;
}

template <typename T>
void Collections::Queue<T>::display()const{
    Node* current = this->front;
    while (current != nullptr){
        std::cout << current->value << " ";
        current = current->next;
    }
}

template <typename T>
void Collections::Queue<T>::display(const Collections::Queue<T>& que_to_display){
    Node* current = que_to_display.front;
    while (current != nullptr){
        std::cout << current->value << " ";
        current = current->next;
    }
}

template <typename T>
T* Collections::Queue<T>::begin(){
    if (this->front == nullptr){
        return nullptr;
    }
    return &front->value;
}

template <typename T>
T* Collections::Queue<T>::end(){
    if (this->rear == nullptr){
        return nullptr;
    }
    return &rear->value;
}