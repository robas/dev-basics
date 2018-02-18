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
typedef char dataType;

typedef struct node {
    dataType data;
    struct node *next;
} node;

typedef struct linkedList {
    node *head;
    int length;
} linkedList;

// Functions
linkedList* createLinkedList();

node* createNode(dataType);

int printList(linkedList* list);

int listLength(linkedList* list);

dataType getAtIndex(linkedList* list, int index);

int insertAtStart(linkedList* list, dataType data);

int insertAtEnd(linkedList* list, dataType data);

int insertAtIndex(linkedList* list, dataType data, int index);

int removeKey(linkedList* list, dataType key);

int removeAtIndex(linkedList* list, int index);

int searchKey(linkedList* list, dataType key);

int reverseList(linkedList *list);

#endif