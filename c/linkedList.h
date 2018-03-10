#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdlib.h>
#include <stdio.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int length;
    int (*print) (struct LinkedList *list);
    int (*equals) (void *key, void *value2);
} LinkedList;

LinkedList* createLinkedList(int (*equals)(void *key, void *value2));

Node* createNode(void *data);

// int printList(LinkedList* list);

int defaultEquals (void *key, void *data);

int listLength(LinkedList* list);

void * getAtIndex(LinkedList* list, int index);

int insertAtStart(LinkedList* list, void *data);

int insertAtEnd(LinkedList* list, void *data);

int insertAtIndex(LinkedList* list, void *data, int index);

int removeKey(LinkedList* list, void *key);

int removeAtIndex(LinkedList* list, int index);

int searchKey(LinkedList* list, void *key);

int reverseList(LinkedList* list);

// int sortList(LinkedList* list);

#endif