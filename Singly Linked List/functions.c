#include "LIST_H.h"

Node* constructor (int data) {

    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->data = data;
    return head;
}

void destructor(Node* ptr) {
    while (ptr) {
        while(ptr->next) {
            ptr = ptr->next;
        }
        free(ptr);
    }
}

void push_back (Node* ptr, int data) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    while(ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->data = data;
}
void push_front (Node* ptr, int data) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (ptr->next) {
        newNode->next = ptr;
        newNode->data = data;
    } 
}

void pop_back (Node* ptr) {

    Node* tmp;
    while(ptr->next) {
        tmp = ptr;
        ptr = ptr->next;
    }
    tmp->next = NULL;
    free(ptr);
}
Node* find (Node* ptr, int key) {
    while(ptr->next) {
        if (ptr->data == key) { // If head node itself holds the key to be deleted
            return ptr;
        }
    }
    if (ptr->data == key) {
            return ptr;
    } else { 
        return NULL;
    }
} 

void insertAfter (Node* ptr, int key, int newData) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* tmpptr = find(ptr,key)->next;
    newNode->next = tmpptr;
    tmpptr->next = newNode;
    newNode->data = newData;
}

void deleteNode (Node** ptr, int key) {

    Node* tmp;
    if ((*ptr)->data == key) {
        tmp = (*ptr)->next;
        free(ptr);
        ptr = tmp;
    }
    while ((*ptr)->next->next) {
        if ((*ptr)->next->data == key) {
            tmp = (*ptr)->next->next;
            free((*ptr)->next);
            (*ptr)->next = tmp;
        }
    }
}

bool isEmpty(Node* ptr) {

    if (ptr == NULL) {
        return false;
    }
    return ptr->next;
}

int getSize(Node* ptr) {

    int size = 0;
    while(ptr->next) {
        ptr = ptr->next;
        size++;
    }
    return size + 1;
}

void printList(Node* ptr) {
    int pos = 0;
    while(ptr->next) {
        printf("%d: Data = %d", pos++, ptr->data);
        ptr = ptr->next;   
    }
    printf("%d: Data = %d", pos++, ptr->data);
}

