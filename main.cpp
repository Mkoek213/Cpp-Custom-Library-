//Main.cpp
#include <iostream>
#include "Vector.h"
#include "Set.h"  
#include "Queue.h"  
#include "RedBlackTree.h"
#include "Map.h"
#include "List.h"
#include "BST.h"



int main() {
    // Create a BST object with some initial values
    Collections::BST<int> bst = {50, 30, 70, 20, 40, 60, 80};

    // Test non-static member functions
    std::cout << "Inorder Traversal: ";
    bst.inorder_traversal();
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    bst.preorder_traversal();
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    bst.postorder_traversal();
    std::cout << std::endl;

    std::cout << "Level 3: ";
    bst.print_level(3);
    std::cout << std::endl;

    std::cout << "Leaf Nodes: ";
    bst.print_leafs();
    std::cout << std::endl;

    std::cout << "Smallest Node: " << bst.get_smallest()->key << std::endl;
    std::cout << "Largest Node: " << bst.get_largest()->key << std::endl;

    auto search_result = bst.search(40);
    if (search_result)
        std::cout << "Search Found: " << search_result->key << std::endl;
    else
        std::cout << "Search Not Found" << std::endl;

    std::cout << "Size of BST: " << bst.get_size() << std::endl;
    std::cout << "Height of BST: " << bst.get_height() << std::endl;

    // Test static member functions
    std::cout << "Inorder Traversal (static): ";
    Collections::BST<int>::inorder_traversal(bst.begin());
    std::cout << std::endl;

    std::cout << "Preorder Traversal (static): ";
    Collections::BST<int>::preorder_traversal(bst.begin());
    std::cout << std::endl;

    std::cout << "Postorder Traversal (static): ";
    Collections::BST<int>::postorder_traversal(bst.begin());
    std::cout << std::endl;

    std::cout << "Level 3 (static): ";
    Collections::BST<int>::print_level(bst.begin(), 3);
    std::cout << std::endl;

    std::cout << "Leaf Nodes (static): ";
    Collections::BST<int>::print_leafs(bst.begin());
    std::cout << std::endl;

    std::cout << "Smallest Node (static): " << Collections::BST<int>::get_smallest(bst.begin())->key << std::endl;
    std::cout << "Largest Node (static): " << Collections::BST<int>::get_largest(bst.begin())->key << std::endl;

    auto static_search_result = Collections::BST<int>::search(bst.begin(), 40);
    if (static_search_result)
        std::cout << "Search Found (static): " << static_search_result->key << std::endl;
    else
        std::cout << "Search Not Found (static)" << std::endl;

    std::cout << "Height of BST (static): " << Collections::BST<int>::get_height(bst.begin()) << std::endl;

    return 0;
}









































// int main() {
//     // Testing default constructor and initializer list constructor
//     Collections::List<int> list = {1, 2, 3, 4, 5};

//     // Testing display_list function
//     std::cout << "Original List:" << std::endl;
//     list.display_list();

//     // Testing get_front and get_back functions
//     std::cout << "Front element: " << list.get_front()->value << std::endl;
//     std::cout << "Back element: " << list.get_back()->value << std::endl;

//     // Testing get_size and empty functions
//     std::cout << "Size of list: " << list.get_size() << std::endl;
//     std::cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << std::endl;

//     // Testing push_front and push_back functions
//     list.push_front(0);
//     list.push_back(6);

//     // Testing pop_front and pop_back functions
//     list.pop_front();
//     list.pop_back();

//     // Testing insert function
//     list.insert(10, 2);

//     // Testing erase function
//     list.erase(1);

//     // Testing reverse function
//     list.reverse();

//     // Testing sort function
//     list.sort();

//     // Testing unique function
//     list.unique();

//     // Displaying the modified list
//     std::cout << "Modified List:" << std::endl;
//     list.display_list();

//     // Testing clear function
//     list.clear();
//     std::cout << "After clear, size of list: " << list.get_size() << std::endl;

//     return 0;
// }










// int main() {
//     // Test the Map class
//     Collections::Map<int, std::string> myMap = {{1, "One"}, {2, "Two"}, {3, "Three"}};

//     // Test insert and get_size
//     std::cout << "Size of the map: " << myMap.get_size() << std::endl;

//     // Test operator[]
//     NodePtr<int, std::string> node = myMap[2];
//     if (node) {
//         std::cout << "Value at key 2: " << node->value << std::endl;
//     } else {
//         std::cout << "Key 2 not found." << std::endl;
//     }

//     // Test find
//     node = myMap.find(3);
//     if (node) {
//         std::cout << "Key 3 found: " << node->value << std::endl;
//     } else {
//         std::cout << "Key 3 not found." << std::endl;
//     }

//     // Test is_in
//     bool isInMap = myMap.is_in(node);
//     std::cout << "Is the found node in the map? " << (isInMap ? "Yes" : "No") << std::endl;

//     // Test count
//     int countForKey2 = myMap.count(2);
//     std::cout << "Count for key 2: " << countForKey2 << std::endl;

//     // Test erase by key
//     myMap.erase(2);
//     std::cout << "Size after erasing key 2: " << myMap.get_size() << std::endl;

//     // Test clear
//     myMap.clear();
//     std::cout << "Size after clearing the map: " << myMap.get_size() << std::endl;

//     // Testing with integers
//     Collections::Queue<int> intQueue = {1, 2, 3, 4, 5};

//     std::cout << "Integer Queue:" << std::endl;
//     intQueue.display();
//     std::cout << "Front Element: " << intQueue.get_front() << std::endl;
//     std::cout << "Back Element: " << intQueue.get_back() << std::endl;

//     // Testing with floats
//     Collections::Queue<float> floatQueue;
//     floatQueue.enqueue(1.1f);
//     floatQueue.enqueue(2.2f);
//     floatQueue.enqueue(3.3f);

//     std::cout << "\nFloat Queue:" << std::endl;
//     floatQueue.display();
//     std::cout << "Front Element: " << floatQueue.get_front() << std::endl;
//     std::cout << "Back Element: " << floatQueue.get_back() << std::endl;

//     // Testing with strings
//     Collections::Queue<std::string> stringQueue = {"apple", "banana", "cherry"};

//     std::cout << "\nString Queue:" << std::endl;
//     stringQueue.display();
//     std::cout << "Front Element: " << stringQueue.get_front() << std::endl;
//     std::cout << "Back Element: " << stringQueue.get_back() << std::endl;

//     // Testing swap function
//     Collections::Queue<int> intQueue2 = {6, 7, 8};
//     Collections::Queue<int>::swap(intQueue, intQueue2);

//     std::cout << "\nAfter Swapping Integer Queues:" << std::endl;
//     intQueue.display();
//     intQueue2.display();

//     return 0;

// }






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