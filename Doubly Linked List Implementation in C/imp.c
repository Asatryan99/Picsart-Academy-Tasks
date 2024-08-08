#include "DOUBLY_LINKED_LIST_H.h"

Node* create_node (int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void DoublyLinkedList_init(DoublyLinkedList* list) {
    if (list == NULL) return;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void DoublyLinkedList_destroy(DoublyLinkedList* list) {
    if (list == NULL) return;
    while (list->tail != list->head) {
        list->tail = list->tail->prev;
        free(list->tail->next);
    }
    free(list->head);
    list->size = 0;    
}

void DoublyLinkedList_insertFront(DoublyLinkedList* list, int value) {
    if (list == NULL) return;
    Node* new_node = create_node(value);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->size++;
}

void DoublyLinkedList_insertBack(DoublyLinkedList* list, int value) {
    if (list == NULL) return;
    Node* new_node = create_node(value);
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
    list->size++;
}

void DoublyLinkedList_insertAfter(DoublyLinkedList* list, Node* node, int value) {
    if (list == NULL) return;
    Node* new_node = create_node(value);
    new_node->prev = node;
    new_node->next = node->next;
    if (node->next != NULL) {
        node->next->prev = new_node;
    }
    node->next = new_node;
    list->size++;
    if (list->tail == node) {
        list->tail = new_node;
    }
}

void DoublyLinkedList_insertBefore(DoublyLinkedList* list, Node* node, int value) {
    if (list == NULL) return;
    if (list->head == node) {
        DoublyLinkedList_insertFront(list, value);
        return;
    }
    Node* new_node = create_node(value);
    if (node->prev != NULL) {
        node->prev->next = new_node;
    }
    new_node->next = node; 
    new_node->prev = node->prev;
    node->prev = new_node;
    list->size++;
}

void DoublyLinkedList_removeFront(DoublyLinkedList* list) {
    if (list == NULL) return;
    Node* tmp = list->head->next;
    free(list->head);
    list->head = tmp;
    list->size--;
}

void DoublyLinkedList_removeBack(DoublyLinkedList* list) {
    if (list == NULL) return;
    Node* tmp = list->tail->prev;
    free(list->tail);
    list->tail = tmp;
    list->tail->next = NULL;
    list->size--;
}

Node* DoublyLinkedList_search(DoublyLinkedList* list, int value) {
    if (list == NULL) return NULL;
    Node* tmp = list->head;
    while (tmp->next != NULL) {
        if (tmp->value == value) {
            return tmp;
        }
        tmp = tmp->next;
    }
    if (tmp->value == value) {
        return tmp;
    }
    return NULL;
}

int DoublyLinkedList_getSize(const DoublyLinkedList* list) {
    if (list == NULL) return -1;
    return list->size;
}

bool DoublyLinkedList_isEmpty(const DoublyLinkedList* list) {
    if (list == NULL) return -1;
    return list->size ? true : false;
}

void DoublyLinkedList_printForward(const DoublyLinkedList* list) {
    if (list == NULL) return;
    Node* tmp = list->head;
    while (tmp->next != NULL) {
        printf("%d, ", tmp->value);
        tmp = tmp->next;
    }
    printf("%d!\n", tmp->value);
}

void DoublyLinkedList_printBackward(const DoublyLinkedList* list) {
    if (list == NULL) return;
    Node* tmp = list->tail;
    while (tmp->prev != NULL) {
        printf("%d, ", tmp->value);
        tmp = tmp->prev;
    }
    printf("%d!\n", tmp->value);
}

void DoublyLinkedList_clear(DoublyLinkedList* list) {
    if (list == NULL) return;
    Node* tmp = list->head;
    while (tmp->next != NULL) {
        tmp->value = 0;
        tmp = tmp->next;
    }
    tmp->value = 0;
}

void DoublyLinkedList_reverse(DoublyLinkedList* list) {
    if (list == NULL || list->head == NULL) return;
    Node* current = list->head;
    Node* tmp = NULL;
    while (current != NULL) {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }
    if (tmp != NULL) {
        list->tail = list->head;
        list->head = tmp->prev;
    }
}

void DoublyLinkedList_copy(DoublyLinkedList* dest, const DoublyLinkedList* src) {
    if (dest == NULL || src == NULL) return;
    Node* current = src->head;
    while (current != NULL) {
        DoublyLinkedList_insertBack(dest, current->value);
        current = current->next;
    }
    dest->size += src->size;

}

void DoublyLinkedList_insert(DoublyLinkedList* list, int position, int value) {
    if (list == NULL || position < 0) return;
    if (position == 0) {
        DoublyLinkedList_insertFront(list, value);
    } else if (position >= list->size) {
        DoublyLinkedList_insertBack(list, value);
    } else {
        Node* current = list->head;
        while (position - 1) {
            current = current->next;
            position--;
        }
        DoublyLinkedList_insertBefore(list, current, value);
    }
    list->size++;
}

void DoublyLinkedList_removeNode(DoublyLinkedList* list, Node* node) {
    if (list == NULL || node == NULL) return;
    Node* current = list->head;
    while (current != NULL) {
        if (current == node) {
            if (node->next == NULL) {
                DoublyLinkedList_removeBack(list);
            } else if (node->prev == NULL) {
                DoublyLinkedList_removeFront(list);
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                free(node);
            }
        }
        current= current->next;
    }
    list->size--;
}

