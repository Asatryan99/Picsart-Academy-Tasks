# LIST_H Library

## Overview

The `LIST_H` library provides a linked list implementation in C. It offers various functionalities to manage and manipulate linked lists, including insertion, deletion, traversal, and search operations.

## Features

- Linked list node management
- Insertion at both ends and after specific nodes
- Deletion of nodes
- List traversal and printing
- Check if the list is empty
- Get the size of the list

## Installation

To use the `LIST_H` library in your project, include the header file `LIST_H.h`:

```c
#include "LIST_H.h"
```

## Function Descriptions

### Node Construction and Destruction

- **`Node* constructor(int data)`**
  - Creates and returns a new node with the given `data`.
  
- **`void destructor(Node* ptr)`**
  - Frees the memory allocated for the list starting from the node `ptr`.

### Element Insertion

- **`void push_back(Node* ptr, int data)`**
  - Adds a new node with `data` to the end of the list.
  
- **`void push_front(Node* ptr, int data)`**
  - Adds a new node with `data` to the front of the list.

### Element Deletion

- **`void pop_back(Node* ptr)`**
  - Removes the last node of the list.
  
- **`void deleteNode(Node** ptr, int key)`**
  - Deletes the node with the given `key` from the list.

### Search and Insertion After a Node

- **`Node* find(Node* ptr, int key)`**
  - Finds and returns the node with the given `key`. Returns `NULL` if the node is not found.
  
- **`void insertAfter(Node* ptr, int key, int newData)`**
  - Inserts a new node with `newData` after the node with the given `key`.

### Utility Functions

- **`bool isEmpty(Node* ptr)`**
  - Checks if the list is empty. Returns `true` if empty, otherwise `false`.
  
- **`int getSize(Node* ptr)`**
  - Returns the size (number of nodes) of the list.
  
- **`void printList(Node* ptr)`**
  - Prints the data of each node in the list.

## Example Usage

```c
#include "LIST_H.h"

int main() {
    Node* myList = constructor(5);
    
    push_back(myList, 10);
    push_front(myList, 3);
    
    printList(myList);
    
    Node* foundNode = find(myList, 10);
    if (foundNode) {
        printf("\nNode with data 10 found.");
    }
    
    deleteNode(&myList, 5);
    
    printList(myList);
    
    destructor(myList);
    return 0;
}
```

## License

This library is licensed under the MIT License. See the LICENSE file for more details.

## Contributions

Contributions are welcome! Please submit a pull request or open an issue to discuss potential improvements.
