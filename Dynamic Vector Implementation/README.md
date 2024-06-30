# Dynamic Vector Implementation

# VECTOR_H Library

## Overview

The `VECTOR_H` library provides a dynamic array implementation in C. It offers various functionalities to manage and manipulate vectors, including dynamic resizing, insertion, deletion, and retrieval of elements.

## Features

- Dynamic resizing
- Element insertion and deletion
- Capacity management
- Element access

## Installation

To use the `VECTOR_H` library in your project, include the header file `VECTOR_H.h`:

```c
#include "VECTOR_H.h"
```

## Function Descriptions

### Getters and Setters

- **`size_t getSize(const Vector* vector)`**
  - Returns the current size (number of elements) of the vector.
  
- **`size_t getCapacity(const Vector* vector)`**
  - Returns the current capacity (allocated storage) of the vector.
  
- **`void setSize(Vector* vector, size_t new_size)`**
  - Sets the size of the vector to `new_size`.
  
- **`void setCapacity(Vector* vector, size_t new_cap)`**
  - Sets the capacity of the vector to `new_cap`.

### Element Access

- **`int getat(const Vector* vector, unsigned int pos)`**
  - Returns the element at position `pos`. Returns `-1` and prints an error message if the position is invalid.

### Capacity Management

- **`bool empty(const Vector* vector)`**
  - Checks if the vector is empty. Returns `true` if empty, otherwise `false`.
  
- **`void reserve(Vector* vector, size_t new_cap)`**
  - Reserves storage space for at least `new_cap` elements.
  
- **`void shrink_to_fit(Vector* vector)`**
  - Reduces the capacity to fit the current size.

### Element Manipulation

- **`void push_back(Vector* vector, int value)`**
  - Adds `value` to the end of the vector. If the vector is full, its capacity is doubled.
  
- **`void pop_back(Vector* vector)`**
  - Removes the last element of the vector.
  
- **`void erase(Vector* vector, int pos)`**
  - Removes the element at position `pos`.
  
- **`void clear(Vector* vector)`**
  - Removes all elements from the vector.
  
- **`void insert(Vector* vector, unsigned int pos, int value)`**
  - Inserts `value` at position `pos`.

### Vector Operations

- **`void copyVector(Vector* dest, const Vector* src)`**
  - Copies the contents of `src` into `dest`.
  
- **`void destroyVector(Vector* vector)`**
  - Frees the memory allocated for the vector.
  
- **`void initializeVector(Vector* vector, int initialCapacity)`**
  - Initializes the vector with an initial capacity of `initialCapacity`.

## Example Usage

```c
#include "VECTOR_H.h"

int main() {
    Vector myVector;
    initializeVector(&myVector, 10);
    
    push_back(&myVector, 5);
    push_back(&myVector, 10);
    
    printf("Element at position 1: %d\n", getat(&myVector, 1));
    
    pop_back(&myVector);
    
    destroyVector(&myVector);
    return 0;
}
```

## License

This library is licensed under the MIT License. See the LICENSE file for more details.

## Contributions

Contributions are welcome! Please submit a pull request or open an issue to discuss potential improvements.
