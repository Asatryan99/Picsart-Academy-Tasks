#include "VECTOR_H.h"


size_t getSize (const Vector* vector) {
    return vector -> size;
}

size_t getCapacity (const Vector* vector) {
    return vector -> cap;
}

size_t setSize (Vector* vector, size_t new_size) {
    vector -> size = new_size;
}

size_t setCapacity (Vector* vector, size_t new_cap) {
    vector -> cap = new_cap;
}

int getat (const Vector* vector, unsigned int pos) {
    if (pos <= getCapacity(vector)) {
        return vector -> vec[pos];
    }
    perror("Invalid position\n");
    return -1;
}

bool empty (const Vector* vector) {
    return getSize(vector);
}

void push_back (Vector* vector, int value) {
    if (getSize(vector) == getCapacity(vector)) {
        vector -> cap *= 2;
        vector = (int*)ralloc(sizeof(Vector), vector -> cap);
    }
    vector -> vec[getSize(vector)] = value;
    vector -> size++;
}

void pop_back (Vector* vector) {
    if (getSize(vector) > 0) {
        vector -> vec[getSize(vector)] = 0;
        vector -> size--; 
    }
    return -1;
}


void insert (Vector* vector, unsigned int pos, int value) {
    if (getSize(vector) == getCapacity(vector)) {
        vector -> cap *= 2;
        vector = (int*)ralloc(sizeof(Vector), vector -> cap); 
    }
    if (pos <= getCapacity(vector)) {
        vector -> vec[pos] = value;
        vector -> size ++;
    }
    return -1;
}

void initializeVector(Vector* vector, int initialCapacity) {
    setSize(vector, 0);
    setCapacity(vector, initialCapacity);
    vector -> vec = (int*)calloc(sizeof(int), vector -> cap);
}





