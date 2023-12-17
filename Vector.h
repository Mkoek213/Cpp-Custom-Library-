#pragma once
#include <cstddef> 
#include <initializer_list>
#include <stdio.h>
#include <stdlib.h>

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
            T& front(); //get first element
            T& back(); //get last element
            //Capacity getters:
            size_t getSize()const; //returns size
            size_t getCapacity()const; //returns capacity
            bool empty()const; //returns true if empty
            //Modifiers:
            void shrinkToFit(); //shrinks capacity to size
            void reserveSpace(size_t extra_capacity); //reserve extra memory
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
            size_t capacity;
            size_t size;
            T* vec;
    };
}
