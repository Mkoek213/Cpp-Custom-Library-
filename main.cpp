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
    vec6.push_front("aaa");
    vec6.popAtIndex(0);
    vec6.clear();
        vec6.push_front("aaa");
    for (int i = 0 ; i < vec6.getSize(); i++){
        std::cout << vec6[i]<<" ";
    }
    std::cout<<"AA";
    return 0;
}