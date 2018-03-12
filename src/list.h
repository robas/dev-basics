#ifndef LIST_H
#define LIST_H

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

typedef struct List {
    Node *head;
    int length;
    void (*printItem) (void *value2);
    int (*equals) (void *key, void *value2);
} List;

List* createList(int (*equals)(void* key, void* value2), void (*customPrintItem) (void* data));

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