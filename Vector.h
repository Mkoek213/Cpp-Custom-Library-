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
            Vector(): size_(), capacity_(), vec_(nullptr) {} //default constructor
            Vector(std::initializer_list<T> values): //constructor with values: Collections::vector<int> vec = {1,2,3,4,5}
            size_(values.size()), 
            capacity_(values.size() * 2), 
            vec_((T*)malloc(capacity_ * sizeof(T))){ 
                size_t i = 0;
                for (const T& value : values){
                    vec_[i++] = value;
                }
            }
            ~Vector(){} //default destructor

            //Access to non-const vectors:
            T& operator[](size_t index); //access element using [index]
            T& at(size_t index); //access element by index
            T& get_front(); //get first element
            T& get_back(); //get last element
            //Capacity getters:
            size_t get_size()const; //returns size
            size_t get_capacity()const; //returns capacity
            bool empty()const; //returns true if empty
            //Modifiers:
            void shrink_to_fit(); //shrinks capacity to size
            void reserve_space(size_t extra_space); //reserve extra memory
            void push_back(const T& value); //push value at the end
            void push_front(const T& value); //push value in front
            void pop_back(); //pop last value
            void pop_front(); //pop first value
            void push_at_index(const T& value, size_t index); //push value at index
            void pop_at_index(size_t index); //pop value from index
            void clear(); //clear all values
            //Iterators:
            T* begin(); //returns pointer to the first element
            T* end(); //returns pointer to the last element
        private:
            void init_vector();
            size_t capacity_;
            size_t size_;
            T* vec_;
    };
}

template <typename T>
void Collections::Vector<T>::init_vector(){
    if (vec_ == nullptr){
        T* new_vec = (T*)malloc(5 * sizeof(T));
        if (new_vec == nullptr){
            throw std::bad_alloc();
        }else{
            vec_ = new_vec;
            capacity_ = 5;
            size_ = 0;
        }
    }else{
        throw std::runtime_error("Can not initialize new vector");
    }
}

template <typename T>
T& Collections::Vector<T>::operator[](size_t index){
    if (index >= size_){
        throw std::out_of_range("Index out of range");
    }
    return *(vec_ + index);
}

template <typename T>
T& Collections::Vector<T>::at(size_t index){
    if (index >= size_){
        throw std::out_of_range("Index out of range");
    }
    return vec_[index];
}

template <typename T>
T& Collections::Vector<T>::get_front(){
    if (size_ == 0){
        throw std::out_of_range("Vector is empty");
    }
    return vec_[0];
}

template <typename T>
T& Collections::Vector<T>::get_back(){
    if (size_ == 0){
        throw std::out_of_range("Vector is empty");
    }
    return vec_[size_ - 1];
}

template <typename T>
size_t Collections::Vector<T>::get_size()const{
    return size_;
}

template <typename T>
size_t Collections::Vector<T>::get_capacity()const{
    return capacity_;
}

template <typename T>
bool Collections::Vector<T>::empty()const{
    return size_ == 0;
}

template <typename T>
void Collections::Vector<T>::shrink_to_fit(){
    if (vec_ == nullptr){
        throw std::bad_alloc();
    }
    T* new_vec = (T*)realloc(vec_, size_ * sizeof(T));
    if (new_vec == nullptr){
        throw std::bad_alloc();
    }
    vec_ = new_vec;
    capacity_ = size_;
}

template <typename T>
void Collections::Vector<T>::reserve_space(size_t extra_capacity){
    if (vec_ == nullptr){
        throw std::bad_alloc();
    }
    T* new_vec = (T*)realloc(vec_, (capacity_ + extra_capacity) * sizeof(T));
    if (new_vec == nullptr){
        throw std::bad_alloc();
    }
    vec_ = new_vec;
    capacity_ += extra_capacity;
}

template <typename T>
void Collections::Vector<T>::push_back(const T& value){
    if (vec_ == nullptr){
        init_vector();
    }
    if (size_ >= capacity_){
        reserve_space(capacity_);
        capacity_ *= 2;
    }
    vec_[size_] = value;
    size_++;
}

template <typename T>
void Collections::Vector<T>::push_front(const T& value){
    if (vec_ == nullptr){
        init_vector();
    }
    if (size_ >= capacity_){
        reserve_space(capacity_);
        capacity_ *= 2;
    }
    T* destination = (T*)((char*)vec_);
    T* source = (T*)vec_;
    for (size_t i = size_; i > 0; i--){
        destination[i] = source[i-1];
    }
    destination[0] = value;
    size_++;
}

template <typename T>
void Collections::Vector<T>::pop_back(){
    if (vec_ == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size_ == 0){
        throw std::runtime_error("Can not pop from empty vector");
    }
    if constexpr (!std::is_trivially_destructible_v<T>) {
        // Non-trivial type, call the destructor for the last element
        vec_[size_ - 1].~T();
    }
    size_--;
}

template <typename T>
void Collections::Vector<T>::pop_front(){
    if (vec_ == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size_ == 0){
        throw std::runtime_error("Can not pop from empty vector");
    }
    if constexpr (!std::is_trivially_destructible_v<T>) {
        // Non-trivial type, call the destructor for the last element
        vec_[0].~T();
    }
    for (size_t i = 1; i < size_; i++){
        vec_[i - 1] = std::move(vec_[i]);
    }
    size_--;
}

template <typename T>
void Collections::Vector<T>::push_at_index(const T& value, size_t index){
    if (index > size_){
        throw std::out_of_range("Index out of range");
    }
    if (vec_ == nullptr){
        init_vector();
    }
    if (size_ >= capacity_){
        reserve_space(capacity_);
        capacity_ *= 2;
    }
    for (size_t i = size_; i > index; i--){
        vec_[i] = std::move(vec_[i - 1]);
    }
    vec_[index] = value;
    size_++;
}

template <typename T>
void Collections::Vector<T>::pop_at_index(size_t index){
    if (index >= size_){
        throw std::out_of_range("Index out of range");
    }
    if (vec_ == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size_ == 0){
        throw std::runtime_error("Can not pop from empty vector");
    }
    if constexpr (!std::is_trivially_destructible_v<T>) {
        // Non-trivial type, call the destructor for element at index
        vec_[index].~T();
    }
    for (size_t i = index + 1; i < size_; i++){
        vec_[i - 1] = std::move(vec_[i]);
    }
    size_--;
}

template <typename T>
void Collections::Vector<T>::clear(){
    if (vec_ == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size_ == 0){
        throw std::runtime_error("Can not pop from empty vector");
    }
    size_ = 0;
}

template <typename T>
T* Collections::Vector<T>::begin(){
    if (vec_ == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size_ == 0){
        throw std::runtime_error("Vector is empty");
    }
    return vec_;
}

template <typename T>
T* Collections::Vector<T>::end(){
    if (vec_ == nullptr){
        throw std::runtime_error("Vector points to NULL");
    }
    if (size_ == 0){
        throw std::runtime_error("Vector is empty");
    }
    return (T*)(vec_ + size_);
}