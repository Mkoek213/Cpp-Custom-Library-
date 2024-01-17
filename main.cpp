//Main.cpp
#include <iostream>
#include "Vector.h"
#include "Set.h"  
#include "Queue.h"  
#include "RedBlackTree.h"
#include "Map.h"




int main() {
    Collections::Map<int, std::string> myMap = {{1, "One"}, {2, "Two"}, {3, "Three"}};
    auto it = myMap.end();

    // Testing with integers
    Collections::Queue<int> intQueue = {1, 2, 3, 4, 5};

    std::cout << "Integer Queue:" << std::endl;
    intQueue.display();
    std::cout << "Front Element: " << intQueue.get_front() << std::endl;
    std::cout << "Back Element: " << intQueue.get_back() << std::endl;

    // Testing with floats
    Collections::Queue<float> floatQueue;
    floatQueue.enqueue(1.1f);
    floatQueue.enqueue(2.2f);
    floatQueue.enqueue(3.3f);

    std::cout << "\nFloat Queue:" << std::endl;
    floatQueue.display();
    std::cout << "Front Element: " << floatQueue.get_front() << std::endl;
    std::cout << "Back Element: " << floatQueue.get_back() << std::endl;

    // Testing with strings
    Collections::Queue<std::string> stringQueue = {"apple", "banana", "cherry"};

    std::cout << "\nString Queue:" << std::endl;
    stringQueue.display();
    std::cout << "Front Element: " << stringQueue.get_front() << std::endl;
    std::cout << "Back Element: " << stringQueue.get_back() << std::endl;

    // Testing swap function
    Collections::Queue<int> intQueue2 = {6, 7, 8};
    Collections::Queue<int>::swap(intQueue, intQueue2);

    std::cout << "\nAfter Swapping Integer Queues:" << std::endl;
    intQueue.display();
    intQueue2.display();

    return 0;

}






    // // Integer Set
    // Collections::Set<int> intSet = {1, 2, 3, 4, 5};
    // std::cout << "Integer Set:\n";
    // intSet.display();
    // std::cout << "\nSize: " << intSet.get_size() << "\n";

    // // Test find and count for integers
    // int valueToFind = 33;
    // int* foundValue = intSet.find(valueToFind);
    // int countValue = intSet.count(valueToFind);
    // std::cout << "Find " << valueToFind << ": " << (foundValue ? *foundValue : -1) << "\n";
    // std::cout << "Count " << valueToFind << ": " << countValue << "\n\n";

    // // Float Set
    // Collections::Set<float> floatSet = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    // std::cout << "Float Set:\n";
    // floatSet.display();
    // std::cout << "\nSize: " << floatSet.get_size() << "\n";

    // // Test find and count for floats
    // float floatValueToFind = 3.3f;
    // float* foundFloatValue = floatSet.find(floatValueToFind);
    // int countFloatValue = floatSet.count(floatValueToFind);
    // std::cout << "Find " << floatValueToFind << ": " << (foundFloatValue ? *foundFloatValue : -1.0f) << "\n";
    // std::cout << "Count " << floatValueToFind << ": " << countFloatValue << "\n\n";

    // // String Set
    // Collections::Set<std::string> stringSet = {"apple", "banana", "orange", "grape", "kiwi"};
    // std::cout << "String Set:\n";
    // stringSet.display();
    // std::cout << "\nSize: " << stringSet.get_size() << "\n";

    // // Test find and count for strings
    // std::string stringValueToFind = "orange";
    // std::string* foundStringValue = stringSet.find(stringValueToFind);
    // int countStringValue = stringSet.count(stringValueToFind);
    // std::cout << "Find " << stringValueToFind << ": " << (foundStringValue ? *foundStringValue : "Not found") << "\n";
    // std::cout << "Count " << stringValueToFind << ": " << countStringValue << "\n\n";

    // // Test erase for all sets
    // intSet.erase(2);
    // floatSet.erase(2.2f);
    // stringSet.erase("banana");

    // std::cout << "After Erasing:\n";
    // std::cout << "Integer Set:\n";
    // intSet.display();
    // std::cout << "\nFloat Set:\n";
    // floatSet.display();
    // std::cout << "\nString Set:\n";
    // stringSet.display();