#include <iostream>
#include "Vector.h"
#include "Set.h"  // Replace with the actual filename of your header


int main() {
    Collections::Set <int> set = {2,3,4,5,6,7,99};
    set.insert(1);
    set.insert(2);
    set.insert(1);
    set.insert(4);
    set.erase(7);
    set.erase(7);
    set.display();
    auto it = set.find(0);
    if (it != nullptr){
        std::cout<<*it;
    }
    int isi = set.count(5);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<set.get_size();
    std::cout<<set.empty();
    return 0;
}