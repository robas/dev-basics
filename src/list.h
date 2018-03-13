#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    int length;
    void (*printItem) (void *data);
    int (*equals) (void *key, void *data);
} List;

List* createList(int (*customEquals)(void* key, void* data), void (*customPrintItem) (void* data));

Node* createNode(void* data);

void printList(List* list);

int defaultEquals (void* key, void* data);

void defaultPrintItem(void* data);

int listLength(List* list);

void* getAtIndex(List* list, int index);

int insertAtStart(List* list, void* data);

int insertAtEnd(List* list, void* data);

int insertAtIndex(List* list, void* data, int index);

int removeKey(List* list, void* key);

int removeAtIndex(List* list, int index);

int searchKey(List* list, void* key);

int reverseList(List* list);

#endif