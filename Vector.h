#pragma once
#include <cstddef> 
#include <initializer_list>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>


namespace Collections{
    template <typename T>
    class Vector{
        public:
            //Constructors and destructors:
            Vector(): size(), capacity(), vec(nullptr) {} //default constructor
            Vector(std::initializer_list<T> values): //constructor with values: Collections::vector<int> vec = {1,2,3,4,5}
            size(values.size()), 
            capacity(values.size() * 2), 
            vec((T*)malloc(capacity * sizeof(T))){
                size_t i = 0;
                for (const T& value : values){
                    vec[i++] = value;
                }
            }
            ~Vector(){ //default destructor
                free(vec);
            }
            //Access to non-const vectors:
            T& operator[](size_t index); //access element using [index]
            T& at(size_t index); //access element by index
            T& get_front(); //get first element
            T& get_back(); //get last element
            //Capacity getters:
            size_t getSize()const; //returns size
            size_t getCapacity()const; //returns capacity
            bool empty()const; //returns true if empty
            //Modifiers:
            void shrinkToFit(); //shrinks capacity to size
            void reserveSpace(size_t extra_space); //reserve extra memory
            void push_back(const T& value); //push value at the end
            void push_front(const T& value); //push value in front
            void pop_back(); //pop last value
            void pop_front(); //pop first value
            void pushAtIndex(const T& value, size_t index); //push value at index
            void popAtIndex(size_t index); //pop value from index
            void clear(); //clear all values
            //Iterators:
            T* begin(); //returns pointer to the first element
            T* end(); //returns pointer to the last element
        private:
            void init_vector();
            size_t capacity;
            size_t size;
            T* vec;
    };
}

template <typename T>
void Collections::Vector<T>::init_vector(){
    if (vec == nullptr){
        T* new_vec = (T*)malloc(5 * sizeof(T));
        if (new_vec == nullptr){
            throw std::bad_alloc();
        }else{
            vec = new_vec;
            capacity = 5;
            size = 0;
        }
    }else{
        throw std::runtime_error("Can not initialize new vector");
    }
}

template <typename T>
T& Collections::Vector<T>::operator[](size_t index){
    if (index >= size){
        throw std::out_of_range("Index out of range");
    }
    return vec[index];
}

template <typename T>
T& Collections::Vector<T>::at(size_t index){
    if (index >= size){
        throw std::out_of_range("Index out of range");
    }
    return vec[index];
}

template <typename T>
T& Collections::Vector<T>::get_front(){
    if (size == 0){
        throw std::out_of_range("Vector is empty");
    }
    return vec[0];
}

template <typename T>
T& Collections::Vector<T>::get_back(){
    if (size == 0){
        throw std::out_of_range("Vector is empty");
    }
    return vec[size - 1];
}

template <typename T>
size_t Collections::Vector<T>::getSize()const{
    return size;
}

template <typename T>
size_t Collections::Vector<T>::getCapacity()const{
    return capacity;
}

template <typename T>
bool Collections::Vector<T>::empty()const{
    return size == 0;
}

template <typename T>
void Collections::Vector<T>::shrinkToFit(){
    if (vec == nullptr){
        throw std::bad_alloc();
    }
    T* new_vec = (T*)realloc(vec, size * sizeof(T));
    if (new_vec == nullptr){
        throw std::bad_alloc();
    }
    vec = new_vec;
    capacity = size;
}

template <typename T>
void Collections::Vector<T>::reserveSpace(size_t extra_capacity){
    if (vec == nullptr){
        throw std::bad_alloc();
    }
    T* new_vec = (T*)realloc(vec, (capacity + extra_capacity) * sizeof(T));
    if (new_vec == nullptr){
        throw std::bad_alloc();
    }
    vec = new_vec;
    capacity += extra_capacity;
}

template <typename T>
void Collections::Vector<T>::push_back(const T& value){
    if (vec == nullptr){
        init_vector();
    }
    if (size >= capacity){
        reserveSpace(capacity);
        capacity *= 2;
    }
    vec[size] = value;
    size++;
}

template <typename T>
void Collections::Vector<T>::push_front(const T& value){
    if (vec == nullptr){
        init_vector();
    }
    if (size >= capacity){
        reserveSpace(capacity);
        capacity *= 2;
    }
    T* destination = (T*)((char*)vec);
    T* source = (T*)vec;
    for (size_t i = size; i > 0; i--){
        destination[i] = source[i-1];
    }
    destination[0] = value;
    size++;
}

template <typename T>
void Collections::Vector<T>::pop_back(){
    if (vec == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size == 0){
        throw std::runtime_error("Can not pop from empty vector");
    }
    if constexpr (!std::is_trivially_destructible_v<T>) {
        // Non-trivial type, call the destructor for the last element
        vec[size - 1].~T();
    }
    size--;
}

template <typename T>
void Collections::Vector<T>::pop_front(){
    if (vec == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size == 0){
        throw std::runtime_error("Can not pop from empty vector");
    }
    if constexpr (!std::is_trivially_destructible_v<T>) {
        // Non-trivial type, call the destructor for the last element
        vec[0].~T();
    }
    for (size_t i = 1; i < size; i++){
        vec[i - 1] = std::move(vec[i]);
    }
    size--;
}

template <typename T>
void Collections::Vector<T>::pushAtIndex(const T& value, size_t index){
    if (index > size){
        throw std::out_of_range("Index out of range");
    }
    if (vec == nullptr){
        init_vector();
    }
    if (size >= capacity){
        reserveSpace(capacity);
        capacity *= 2;
    }
    for (size_t i = size; i > index; i--){
        vec[i] = std::move(vec[i - 1]);
    }
    vec[index] = value;
    size++;
}

template <typename T>
void Collections::Vector<T>::popAtIndex(size_t index){
    if (index >= size){
        throw std::out_of_range("Index out of range");
    }
    if (vec == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size == 0){
        throw std::runtime_error("Can not pop from empty vector");
    }
    if constexpr (!std::is_trivially_destructible_v<T>) {
        // Non-trivial type, call the destructor for element at index
        vec[index].~T();
    }
    for (size_t i = index + 1; i < size; i++){
        vec[i - 1] = std::move(vec[i]);
    }
    size --;
}

template <typename T>
void Collections::Vector<T>::clear(){
    if (vec == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size == 0){
        throw std::runtime_error("Can not pop from empty vector");
    }
    size = 0;
}

template <typename T>
T* Collections::Vector<T>::begin(){
    if (vec == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size == 0){
        throw std::runtime_error("Vector is empty");
    }
    return vec;
}

template <typename T>
T* Collections::Vector<T>::end(){
    if (vec == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size == 0){
        throw std::runtime_error("Vector is empty");
    }
    return (T*)(vec + size - 1);
}