# Doubly Linked List Implementation in C

This project provides a basic implementation of a doubly linked list in C. The doubly linked list allows traversal in both directions (forward and backward), and supports common operations like insertion, deletion, searching, and reversing.

## Features

- **Insertion**: Insert elements at the front, back, or a specific position in the list.
- **Deletion**: Remove elements from the front, back, or a specific node.
- **Search**: Find a node by its value.
- **Traversal**: Print the list forward or backward.
- **Reversal**: Reverse the entire list.
- **Copy**: Create a deep copy of the list.
- **Size Check**: Get the size of the list.
- **Clear**: Clear the list by setting all values to 0.

## Function Descriptions

- `Node* create_node(int value)`: Creates and returns a new node with the given value.
- `void DoublyLinkedList_init(DoublyLinkedList* list)`: Initializes an empty list.
- `void DoublyLinkedList_destroy(DoublyLinkedList* list)`: Destroys the list and frees the allocated memory.
- `void DoublyLinkedList_insertFront(DoublyLinkedList* list, int value)`: Inserts a node at the front of the list.
- `void DoublyLinkedList_insertBack(DoublyLinkedList* list, int value)`: Inserts a node at the back of the list.
- `void DoublyLinkedList_insertAfter(DoublyLinkedList* list, Node* node, int value)`: Inserts a node after the given node.
- `void DoublyLinkedList_insertBefore(DoublyLinkedList* list, Node* node, int value)`: Inserts a node before the given node.
- `void DoublyLinkedList_removeFront(DoublyLinkedList* list)`: Removes the front node from the list.
- `void DoublyLinkedList_removeBack(DoublyLinkedList* list)`: Removes the back node from the list.
- `Node* DoublyLinkedList_search(DoublyLinkedList* list, int value)`: Searches for a node by value and returns it.
- `int DoublyLinkedList_getSize(const DoublyLinkedList* list)`: Returns the size of the list.
- `bool DoublyLinkedList_isEmpty(const DoublyLinkedList* list)`: Checks if the list is empty.
- `void DoublyLinkedList_printForward(const DoublyLinkedList* list)`: Prints the list from front to back.
- `void DoublyLinkedList_printBackward(const DoublyLinkedList* list)`: Prints the list from back to front.
- `void DoublyLinkedList_reverse(DoublyLinkedList* list)`: Reverses the list.
- `void DoublyLinkedList_copy(DoublyLinkedList* dest, const DoublyLinkedList* src)`: Copies the content of one list into another.
- `void DoublyLinkedList_insert(DoublyLinkedList* list, int position, int value)`: Inserts a node at the specified position in the list.
- `void DoublyLinkedList_removeNode(DoublyLinkedList* list, Node* node)`: Removes a specific node from the list.
