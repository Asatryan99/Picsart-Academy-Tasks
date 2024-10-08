#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {

    size_t size;
    size_t cap; 
    int* vec;

} Vector;

int getat (const Vector* vector,unsigned int pos);
bool empty (const Vector* vector);
void push_back (Vector* vector, int value);
void pop_back (Vector* vector);
size_t getSize (const Vector* vector);
size_t getCapacity (const Vector* vector);
size_t setSize (Vector* vector, size_t new_size);
size_t setCapacity (Vector* vector, size_t new_cap);
void insert (Vector* vector, unsigned int pos, int value);
void initializeVector(Vector* vector, int initialCapacity);
void erase (Vector* vector, int pos);
void clear (Vector* vector);
void shrink_to_fit (Vector* vector);
void reserve (Vector* vector, size_t new_cap);
void copyVector (Vector* dest, const Vector* src);
void destroyVector(Vector* vector);

#endif // VECTOR_H
