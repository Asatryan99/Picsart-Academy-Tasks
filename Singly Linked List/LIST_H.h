#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {

    int data;
    Node* next;

} Node;

Node* constructor (int data);
void destructor(Node* ptr); 
void push_back (Node* ptr, int data);
void push_front (Node* ptr, int data);
void pop_back (Node* ptr);
Node* find (Node* ptr, int kay);
void insertAfter (Node* ptr, int kay, int newData);
void deleteNode (Node* ptr, int kay);
bool isEmpty(Node* ptr);
int getSize(Node* ptr);

#endif // LIST_H