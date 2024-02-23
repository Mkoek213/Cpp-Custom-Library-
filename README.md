# C++ Custom Library

This is a custom C++ library that provides implementations for various data structures including Vector, Set, Queue, Red-Black Tree(only for Map implementation), Map, List, and Binary Search Tree (BST). Each data structure comes with a set of member functions for manipulation and access. In the main.cpp file you will find sample implementations of all available functions. 

## Usage Guidelines

### Handling Pointers to Nodes
For functions that return pointers to nodes, it's recommended to use the `auto` keyword for variable declarations. This helps in writing cleaner and more concise code. Here's an example:

```cpp

// Create a BST object with some initial values
Collections::BST<int> bst = {50, 30, 70, 20, 40, 60, 80};

// Use auto when storing pointers to nodes returned by functions
auto smallest_node = bst.get_smallest();
```

### How to compile your code

To use the custom library uncomment the selected part of the code from main.cpp file and follow these steps:

1. Compile your main source code:
    ```bash
    g++ -std=c++17 -o main main.cpp
    ```

2. Execute the main source code:
    ```bash
    ./main
    ```

Feel free to replace main.cpp with your own code.

# Available functions for each data structure:

## Vector:
```cpp
      //Access to vector:
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
```

## Set:
```cpp
      //Access to set:
      T* find(const T& value); //returns the iterator to the element specified if found, else return nullptr
      int count(const T& value); //returns 1 if the specified element is found, else 0

      //Capacity getters:
      size_t get_size()const; //returns size
      bool empty()const; //returns true if empty

      //Modifiers:
      void insert(const T& value); //insert the specified element in the set
      void erase(const T& element_to_delete); //deletion of an element with a set value, if not found return nullptr
      void clear(); //deletes/clears all the elements from the set.
      void swap(Collections::Set<T>& set_to_swap); //swaps the elements of the two sets
      void display(); //function to display set

      //Iterators:
      T* begin(); //returns pointer to the first element
      T* end(); //returns pointer to the last element
```

## Queue:
```cpp
      //Access to queue:
      T& get_front(); //get first element
      T& get_back(); //get last element

      //Capacity getters:
      size_t get_size()const; //returns the size of the queue.
      bool empty()const; //returns whether the queue is empty. It return true if the queue is empty otherwise returns false.

      //Modifiers:
      void enqueue(const T& value); //insert the specified element in the queue, at the end
      void dequeue(); //function to dequeue the front element, delete at the beginning
      void clear(); //deletes/clears all the elements from the set.
      void swap(Collections::Queue<T>& que_to_swap); //exchange the contents of two queues but the queues must be of the same value type, although sizes may differ.
      static void swap(Collections::Queue<T>& que1_to_swap, Collections::Queue<T>& que2_to_swap); //same as above
      void display()const; //display the queue
      static void display(Collections::Queue<T>& que_to_display); //same as above

      //Iterators:
      T* begin(); //returns pointer to the first element
      T* end(); //returns pointer to the last element
```

## Map:
```cpp
      //Access to map:
      NodePtr<K, V> operator[](const K& key); //this operator is used to reference the element present at the position given inside the operator
      NodePtr<K, V> find(const K& key); //returns the iterator to the element specified if found, else return nullptr
      bool is_in(NodePtr<K, V> node); //returns the iterator to the element specified if found, else return nullptr
      int count(const K& key); //returns the number of matches to element with key-value ‘g’ in the map

      //Modifiers:
      void operator=(const Collections::Map<K, V>& other); //assigns contents of a container to a different container, replacing its current content
      void insert(const K& key, const V& value); //insert the specified element in the map
      void erase(NodePtr<K, V> position); // removes the element at the position pointed by the iterator.
      void erase(const K& key); //removes the key-value from the map.
      void clear(); //removes all the elements from the map

      //Capacity getters:
      size_t get_size()const; //returns the number of elements in the map.
      bool empty()const; //returns true if empty

      //Iterators:
      NodePtr<K, V> begin(); //returns pointer to the first element
      NodePtr<K, V> end(); //returns pointer to the last element
```

## List:
```cpp
      //Access to list:
      Node* get_front(); //returns the value of the first element in the list.
      Node* get_back(); //returns the value of the last element in the list.
      void display_list(); //function to display list.

      //Capacity getters:
      size_t get_size()const; //returns the number of elements in the list.
      bool empty()const; //returns whether the list is empty(1) or not(0).

      //Modifiers:
      void operator=(Collections::List<T>& list_to_replace); //this operator is used to assign new contents to the container by replacing the existing contents.
      void swap(Collections::List<T>& list_to_replace); //this function is used to swap the contents of one list with another list of the same type.
      void merge(Collections::List<T>& list_to_merge); //merges two sorted lists into one.
      static Collections::List<T> merge(Collections::List<T>& first_to_merge, Collections::List<T>& second_to_merge); //merges two sorted lists into one.
      void push_front(const T& new_elem); //adds a new element ‘new_elem’ at the beginning of the list.
      void push_back(const T& new_elem); //adds a new element ‘new_elem’ at the end of the list.
      void pop_front(); //removes the first element of the list, and reduces the size of the list by 1.
      void pop_back(); //removes the last element of the list, and reduces the size of the list by 1.
      void insert(const T& new_elem, size_t index); //inserts new elements in the list before the element at a specified position.
      void erase(size_t index); //removes a single element from the list by index.
      void reverse(); //reverses the list.
      void sort(); //sorts the list in increasing order.
      void unique(); //removes all duplicate consecutive elements from the list.
      void clear(); //function is used to remove all the elements of the list container, thus making it size 0.

      //Iterators:
      Node* begin(); //function returns an iterator pointing to the first element of the list.
      Node* end(); //function returns an iterator pointing to the theoretical last element which follows the last element.
```

## Binary Search Tree(BST):
```cpp
      //Access to BST:
      void inorder_traversal(); //function to display bst in non-decrasing order
      static void inorder_traversal(Node* root); //function to display bst in non-decrasing order
      void preorder_traversal(); //function to display bst. Preorder traversal first visits the root node and then traverses the left and the right subtree. It is used to create a copy of the tree.
      static void preorder_traversal(Node* root); //function to display bst. Preorder traversal first visits the root node and then traverses the left and the right subtree. It is used to create a copy of the tree.
      void postorder_traversal(); //function to display bst. Postorder traversal first traverses the left and the right subtree and then visits the root node. It is used to delete the tree.
      static void postorder_traversal(Node* root); //function to display bst. Postorder traversal first traverses the left and the right subtree and then visits the root node. It is used to delete the tree.
      void print_level(size_t level); //it prints all the nodes at a particular level of the BST.
      static void print_level(Node* root, size_t level); //it prints all the nodes at a particular level of the BST.
      void print_leafs(); //it prints all leafs.
      static void print_leafs(Node* root); //it prints all leafs.
      Node* get_smallest(); //it is used to return the node with the smallest value in the BST.
      static Node* get_smallest(Node* root); //it is used to return the node with the smallest value in the BST.
      Node* get_largest(); //it is used to return the node with the largest value in the BST.
      static Node* get_largest(Node* root); //it is used to return the node with the largest value in the BST.
      Node* search(const T& key); //it is used to search for specific key in BST.
      static Node* search(Node* root, const T& key); //it is used to search for specific key in BST.

      // Capacity getters:
      size_t get_size()const; //returns the number of nodes in the bst.
      bool empty()const; //returns whether the bst is empty(1) or not(0).
      size_t get_height()const; //returns height of BST.
      static size_t get_height(Node* root); //returns height of BST.

      //Modifiers:
      void swap(Collections::BST<T>& bst); //this function is used to swap the contents of one list with another list of the same type.
      void insert(const T& key); //inserts new elements in the bst at the leaf.
      void delete_node(const T& key); //it is used to delete a node with specific key from the BST.

      //Iterators:
      Node* begin(); //function returns an iterator pointing to the root of the list.
```
