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

// Data structures
#ifndef _DATATYPE_
#define _DATATYPE_
typedef int dataType;
#endif

typedef struct Node {
    dataType data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int length;
    int (*print)(struct LinkedList *list);
} LinkedList;

// Functions
LinkedList* createLinkedList();

Node* createNode(dataType);

int printList(LinkedList* list);

int listLength(LinkedList* list);

dataType getAtIndex(LinkedList* list, int index);

int insertAtStart(LinkedList* list, dataType data);

int insertAtEnd(LinkedList* list, dataType data);

int insertAtIndex(LinkedList* list, dataType data, int index);

int removeKey(LinkedList* list, dataType key);

int removeAtIndex(LinkedList* list, int index);

int searchKey(LinkedList* list, dataType key);

int reverseList(LinkedList* list);

// int sortList(LinkedList* list);

#endif