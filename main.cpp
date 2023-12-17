#include <stdlib.h>
#include <iostream>
#include "Vector.h"


int main(){
    Collections::Vector<int> vec1;
    Collections::Vector<double> vec2;
    Collections::Vector<std::string> vec3;
    Collections::Vector<int> vec4 = {1, 2, 3, 4};
    Collections::Vector<double> vec5 = {11.55, 22.3, 6.3123};
    Collections::Vector<std::string> vec6 = {"abba", "essa", "adasda"};
    vec3.push_back("aaa");
    for (int i = 0 ; i < vec3.getSize(); i++){
        std::cout << vec3[i]<<std::endl;
    }
    return 0;
}