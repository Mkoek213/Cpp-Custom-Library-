#pragma once
#include <cstddef> 
#include <initializer_list>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>


namespace Collections{
    template <typename T>
    class Set{
        public:
            //Constructors and destructors:
            Set(): size(), capacity(), set(nullptr) {} //default constructor
            Set(std::initializer_list<T> values): //constructor with values: Collections::set<int> vec = {1,2,3,4,5}
            size(values.size()), 
            capacity(values.size() * 2), 
            set((T*)malloc(capacity * sizeof(T))){ //dodać usuwanie powtarzających sie
                size_t i = 0;
                for (const T& value : values){
                    set[i++] = value;
                }
            }
            ~Set(){ //default destructor
                free(set);
            }
            //Access to non-const sets:
            T& operator[](size_t index); //access element using [index]
            T& at(size_t index); //access element by index
            T& getFront(); //get first element
            T& getBack(); //get last element
            //Capacity getters:
           / size_t getSize()const; //returns size
           / size_t getCapacity()const; //returns capacity
           / bool empty()const; //returns true if empty
            //Modifiers:
           / void shrinkToFit(); //shrinks capacity to size
           / void reserveSpace(size_t extra_space); //reserve extra memory
           / void clear(); //clear all values
            //Iterators:
           / T* begin(); //returns pointer to the first element
           / T* end(); //returns pointer to the last element
        private:
            void init_set();
            void sort();
            bool isUnique();
            size_t capacity;
            size_t size;
            T* vec;
    };
}