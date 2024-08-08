#include "DOUBLY_LINKED_LIST_H.h"

int main () {

    printf("Init and fill list\n");
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    DoublyLinkedList_init(list);
    for (int i = 1; i < 10; i++) {
        DoublyLinkedList_insertBack(list, i);
    }
    DoublyLinkedList_printForward(list);

    printf("Remove front node\n");
    DoublyLinkedList_removeFront(list);
    DoublyLinkedList_printForward(list);

    printf("Remove back node\n");
    DoublyLinkedList_removeBack(list);
    DoublyLinkedList_printForward(list);

    printf("Size of list is %d\n", DoublyLinkedList_getSize(list));
    printf("List is empaty? %d\n", DoublyLinkedList_isEmpty(list));
    printf("Search number is %d\n", DoublyLinkedList_search(list, 8)->value);

    printf("Insert after\n");
    DoublyLinkedList_insertAfter(list, DoublyLinkedList_search(list, 8), 15);
    DoublyLinkedList_printForward(list);

    printf("Insert before\n");
    DoublyLinkedList_insertBefore(list, DoublyLinkedList_search(list, 2), 18);
    DoublyLinkedList_printForward(list);

    printf("Insert reverse\n");
    DoublyLinkedList_reverse(list);
    DoublyLinkedList_printForward(list);

    printf("Copy\n");
    DoublyLinkedList* list2 = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    DoublyLinkedList_init(list2);
    for (int i = 10; i < 20; i++) {
        DoublyLinkedList_insertBack(list2, i);
    }
    DoublyLinkedList_copy(list, list2);
    DoublyLinkedList_printForward(list);

    printf("Insert by possition\n");
    DoublyLinkedList_insert(list, 3, 55);
    DoublyLinkedList_printForward(list);

    printf("Remove Node\n");
    DoublyLinkedList_removeNode(list, DoublyLinkedList_search(list, 2));
    DoublyLinkedList_printForward(list);
    
    printf("Destroy\n");
    DoublyLinkedList_destroy(list);
    free(list);
}