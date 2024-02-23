//Main.cpp
#include <iostream>
#include "Vector.h"
#include "Set.h"  
#include "Queue.h"  
#include "RedBlackTree.h"
#include "Map.h"
#include "List.h"
#include "BST.h"

/* Binary Serch Tree(BST) test code

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

    if (bst.empty())
        std::cout << "Binary Search Tree is empty" << std::endl;
    else
        std::cout << "Binary Search Tree is not empty" << std::endl;

    std::cout << "Height of BST (static): " << Collections::BST<int>::get_height(bst.begin()) << std::endl;

    return 0;
}

*/





/* List test code

int main() {
    // Create a List object with some initial values
    Collections::List<int> list = {1, 3, 5, 7, 9};

    // Access non-const members
    auto front = list.get_front();
    auto back = list.get_back();
    std::cout << "Front: " << front->value << std::endl; // Assuming Node has a value member
    std::cout << "Back: " << back->value << std::endl;

    // Display list
    std::cout << "List: ";
    list.display_list();
    std::cout << std::endl;

    // Capacity getters
    std::cout << "Size of list: " << list.get_size() << std::endl;
    std::cout << "Is list empty: " << (list.empty() ? "Yes" : "No") << std::endl;

    // Modifiers
    Collections::List<int> list_to_replace = {2, 4, 6, 8};
    list = list_to_replace;
    std::cout << "List after replacement: ";
    list.display_list();
    std::cout << std::endl;

    list.swap(list_to_replace);
    std::cout << "List after swapping: ";
    list.display_list();
    std::cout << std::endl;

    list.merge(list_to_replace);
    std::cout << "List after merging: ";
    list.display_list();
    std::cout << std::endl;

    Collections::List<int> first_to_merge = {1, 3, 5};
    Collections::List<int> second_to_merge = {2, 4, 6};
    Collections::List<int> merged_list = Collections::List<int>::merge(first_to_merge, second_to_merge);
    std::cout << "Merged list: ";
    merged_list.display_list();
    std::cout << std::endl;

    list.push_front(0);
    std::cout << "List after pushing front: ";
    list.display_list();
    std::cout << std::endl;

    list.push_back(10);
    std::cout << "List after pushing back: ";
    list.display_list();
    std::cout << std::endl;

    list.pop_front();
    std::cout << "List after popping front: ";
    list.display_list();
    std::cout << std::endl;

    list.pop_back();
    std::cout << "List after popping back: ";
    list.display_list();
    std::cout << std::endl;

    list.insert(5, 2);
    std::cout << "List after inserting at index 2: ";
    list.display_list();
    std::cout << std::endl;

    list.erase(2);
    std::cout << "List after erasing at index 2: ";
    list.display_list();
    std::cout << std::endl;

    list.reverse();
    std::cout << "Reversed list: ";
    list.display_list();
    std::cout << std::endl;

    list.sort();
    std::cout << "Sorted list (ascending): ";
    list.display_list();
    std::cout << std::endl;

    list.unique();
    std::cout << "List after removing consecutive duplicates: ";
    list.display_list();
    std::cout << std::endl;

    list.clear();
    std::cout << "List after clearing: ";
    list.display_list();
    std::cout << std::endl;

    return 0;
}
*/





/* Map test code

int main() {
    // Create a Map object with some initial key-value pairs
    Collections::Map<int, std::string> map = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"}
    };

    // Access non-const members
    auto node = map.find(2);
    if (node) {
        std::cout << "Found key 2, value: " << node->value << std::endl;
    } else {
        std::cout << "Key 2 not found." << std::endl;
    }

    // Check if a key is in the map
    int key_to_check = 4;
    if (map.count(key_to_check) > 0) {
        std::cout << "Key " << key_to_check << " is in the map." << std::endl;
    } else {
        std::cout << "Key " << key_to_check << " is not in the map." << std::endl;
    }

    // Modifiers
    map.insert(4, "Four");
    std::cout << "Inserted key 4, value: " << map[4]->value << std::endl;

    map.erase(map.find(3));

    // Use operator[] to access elements
    std::cout << "Value of key 1: " << map[1]->value << std::endl;
    std::cout << "Value of key 2: " << map[2]->value << std::endl;

    // Modify value using operator[]
    map[2]->value = "New Two";
    std::cout << "Modified value of key 2: " << map[2]->value << std::endl;

    // Testing operator=
    Collections::Map<int, std::string> another_map = {
        {5, "Five"}
    };
    map = another_map;
    std::cout << "Another map size after assignment: " << map.get_size() << std::endl;

    // Testing is_in function
    auto node_to_check = map.find(5);
    if (map.is_in(node_to_check)) {
        std::cout << "Node with key 5 is in the map." << std::endl;
    } else {
        std::cout << "Node with key 5 is not in the map." << std::endl;
    }

    // Testing empty function
    std::cout << "Is map empty? " << (map.empty() ? "Yes" : "No") << std::endl;

    map.clear();
    std::cout << "Map size after clearing: " << map.get_size() << std::endl;

    return 0;
}

*/





/* Queue test code

int main() {
    // Create a Queue object with some initial values
    Collections::Queue<int> que = {1, 2, 3, 4, 5};

    // Test non-static member functions
    std::cout << "Front element of the queue: " << que.get_front() << std::endl;
    std::cout << "Back element of the queue: " << que.get_back() << std::endl;
    std::cout << "Size of the queue: " << que.get_size() << std::endl;
    std::cout << "Is the queue empty? " << (que.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Queue before enqueue: ";
    que.display();
    std::cout << "\n";
    que.enqueue(6);
    std::cout << "Queue after enqueue: ";
    que.display();
    std::cout << "\n";
    que.dequeue();
    std::cout << "Queue after dequeue: ";
    que.display();
    std::cout << "\n";
    que.clear();
    std::cout << "Queue size after clearing: " << que.get_size() << std::endl;

    // Test static member functions (swap and display)
    Collections::Queue<int> que1 = {1, 2, 3};
    Collections::Queue<int> que2 = {4, 5, 6};
    Collections::Queue<int>::swap(que1, que2);
    std::cout << "Queue 1 after swap: ";
    Collections::Queue<int>::display(que1);
    std::cout << "\n";
    std::cout << "Queue 2 after swap: ";
    Collections::Queue<int>::display(que2);
    std::cout << "\n";
    que1.swap(que2);
    std::cout << "Queue 1 after swap: ";
    Collections::Queue<int>::display(que1);
    std::cout << "\n";
    std::cout << "Queue 2 after swap: ";
    Collections::Queue<int>::display(que2);
    std::cout << "\n";

    // Test iterators (begin and end)
    auto it = que2.begin();
    auto it2 = que2.end();
    std::cout << "Begin:" << *it << std::endl;
    std::cout << "End:" << *it2 << std::endl;

    return 0;
}

*/





/* Set test code

int main() {
    // Create a Set object with some initial values
    Collections::Set<int> set = {1, 2, 3, 4, 5};

    // Test non-static member functions
    std::cout << "Find element 3: " << (*set.find(3)) << std::endl;
    std::cout << "Count of element 3: " << set.count(3) << std::endl;
    std::cout << "Size of the set: " << set.get_size() << std::endl;
    std::cout << "Is the set empty? " << (set.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Set before insert: ";
    set.display();
    std::cout <<"\n";
    set.insert(6);
    std::cout << "Set after insert: ";
    set.display();
    std::cout <<"\n";
    set.erase(3);
    std::cout << "Set after erase: ";
    set.display();
    std::cout <<"\n";
    set.clear();
    std::cout << "Set size after clearing: " << set.get_size() << std::endl;

    // Test static member functions (swap and display)
    Collections::Set<int> set1 = {1, 2, 3};
    Collections::Set<int> set2 = {4, 5, 6};
    set1.swap(set2);
    std::cout << "Set 1 after swap: ";
    set1.display();
    std::cout <<"\n";
    std::cout << "Set 2 after swap: ";
    set2.display();
    std::cout <<"\n";

    // Test iterators (begin and end)
    auto it = set2.begin();
    auto it2 = set2.end();
    std::cout << "Begin:" << *it << std::endl;
    std::cout << "End:" << *it2 << std::endl;

    return 0;
}

*/





/* Vector test code

int main() {
    // Create a Vector object with some initial values
    Collections::Vector<int> vec = {1, 2, 3, 4, 5};

    // Test non-static member functions
    std::cout << "Element at index 2: " << vec[2] << std::endl;
    std::cout << "Element at index 3 using at(): " << vec.at(3) << std::endl;
    std::cout << "Front element: " << vec.get_front() << std::endl;
    std::cout << "Back element: " << vec.get_back() << std::endl;
    std::cout << "Size of the vector: " << vec.get_size() << std::endl;
    std::cout << "Capacity of the vector: " << vec.get_capacity() << std::endl;
    std::cout << "Is the vector empty? " << (vec.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Vector elements before push_back: ";
    for (auto it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    vec.push_back(6);
    std::cout << "Vector elements after push_back: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    vec.pop_back();
    std::cout << "Vector elements after pop_back: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    vec.push_front(0);
    std::cout << "Vector elements after push_front: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    vec.pop_front();
    std::cout << "Vector elements after pop_front: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    vec.push_at_index(10, 2);
    std::cout << "Vector elements after push_at_index: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    vec.pop_at_index(2);
    std::cout << "Vector elements after pop_at_index: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test reserve_space() and shrink_to_fit()
    vec.reserve_space(10);
    std::cout << "Capacity after reserve_space(10): " << vec.get_capacity() << std::endl;

    // Test iterators (begin and end)
    auto it = vec.begin();
    auto it2 = vec.end();
    std::cout << "Begin:" << *it << std::endl;
    std::cout << "End:" << *it2 << std::endl;

    vec.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit(): " << vec.get_capacity() << std::endl;

    vec.clear();
    std::cout << "Vector size after clearing: " << vec.get_size() << std::endl;

    return 0;
}

*/