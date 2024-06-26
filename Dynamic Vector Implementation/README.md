# Dynamic Vector Implementation

This project provides an implementation of a dynamic array (vector) in C. The vector is designed to automatically resize as elements are added or removed, allowing for efficient management of a collection of integers.

## Features

- **Dynamic Resizing**: Automatically adjusts its capacity as elements are added or removed.
- **Basic Operations**: Supports push, pop, insert, and get operations.
- **Size and Capacity Tracking**: Maintains the current size and capacity of the vector.

## Getting Started

### Prerequisites

- C compiler (e.g., `gcc`)
- Unix-like operating system (Linux, macOS)

### Files

- `VECTOR_H.h`: Header file containing the definition of the `Vector` structure and function prototypes.
- `VECTOR_H.c`: Implementation file containing the function definitions.
- `main.c`: Example usage of the vector.

### Compiling the Program

To compile the program, use the following command:

```bash
gcc -o vector_example main.c VECTOR_H.c
```

### Running the Program

After compiling, you can run the program using:

```bash
./vector_example
```

## Functions Overview

### `initializeVector`

Initializes a vector with a specified initial capacity.

### `push_back`

Adds an element to the end of the vector, resizing if necessary.

### `pop_back`

Removes the last element from the vector.

### `insert`

Inserts an element at a specified position in the vector, resizing if necessary.

### `getat`

Returns the element at a specified position.

### `empty`

Checks if the vector is empty.

### `getSize`

Returns the current size of the vector.

### `getCapacity`

Returns the current capacity of the vector.

## Usage Example

The `main.c` file provides an example of how to use the vector functions. This includes initializing a vector, adding and removing elements, and accessing elements.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

---

This README provides an overview of the project, detailing its features, how to get started, and the functionality of its various components.
