#include "linkedList.h"

linkedList* createLinkedList() {
    linkedList* newList = malloc(sizeof(linkedList));
    newList->head = NULL;
    newList->length = 0;
    return newList;
}

node *createNode(dataType data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;    
}

int printList(linkedList* list) {
    if (!list->head) {
        printf("The list is empty\n");
    } else {
        node* iterator = list->head;
        for (node* iterator = list->head; iterator; iterator = iterator->next) {
            printf("%c", iterator->data);
        }
        printf("\n");
    }
    return 0;
}

int listLength(linkedList* list) {
    int i = 0;
    for (node *iterator = list->head; iterator; iterator = iterator->next) {
        i++;
    }
    return i;
}

// Returns the data at the specified index, considering an 1 based array
dataType getAtIndex(linkedList *list, int index) {
    if (index > list->length || index < 1)
        return '\0';

    node *iterator = list->head;
    for (int i = 1; i < index && iterator->next; i++) {
        iterator = iterator->next;
    }
    
    return iterator->data;
}

int insertAtStart(linkedList* list, dataType data) {
    node *newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
    list->length++;
    return 0;
}

int insertAtEnd(linkedList* list, dataType data) {
    node *newNode = createNode(data);

    if (!list->head) {
        list->head = newNode;
    } else {

        node *iterator = list->head;
        while (iterator->next) {
            iterator = iterator->next;
        }
        iterator->next = newNode;
    }
    list->length++;
    return 0;
}

// Inserts data at the specified index, considering an 1 based array
int insertAtIndex(linkedList* list, dataType data, int index) {
    if (index > list->length+1 || index < 1)
        return -1;

    node *newNode = createNode(data);
    if (index == 1) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        node *iterator = list->head;
    
        for (int i = 1; i < index-1 && iterator->next; i++) {
            iterator = iterator->next;
        }
        newNode->next = iterator->next;
        iterator->next = newNode;
    }
    list->length++;
    return 0;
}

// Deletes the first node entry which data corresponds to the specified key
int removeKey(linkedList *list, dataType key) {
    if (list->head->data == key) {
        node *temp = list->head;
        list->head = temp->next;
        free(temp);
    } else {
        node *iterator = NULL;
        for (iterator = list->head; iterator->next->data != key && iterator->next; iterator = iterator->next);
        node *temp = iterator->next;
        iterator->next = iterator->next->next;
        free(temp);
    }
    list->length--;
    return 0;
}

// Deletes the node at the specified index, considering an 1 based array
int removeAtIndex(linkedList *list, int index) {
    if (index < 1 || index > list->length)
        return -1;
    if (index == 1) {
        node *temp = list->head;
        list->head = temp->next;
        free(temp);
    } else {
        node *iterator = list->head;
    
        for (int i = 1; i < index-1 && iterator->next; i++) {
            iterator = iterator->next;
        }
        node *temp = iterator->next;
        iterator->next = iterator->next->next;
        free(temp);
    }
    list->length--;
    return 0;
}

// Returns true if the specified key exists in the list
int searchKey(linkedList *list, dataType key) {
    for (node *iterator = list->head; iterator; iterator = iterator->next) {
        if (iterator->data == key)
            return TRUE;
    }
    return FALSE;
}

int reverseList(linkedList *list) {
    if (list->length == 1)
        return 0;

    node *p1 = list->head;
    node *p2 = p1->next;
    node *p3 = p2->next;
    p1->next = NULL;
    while (p2->next) {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    list->head = p2;
    return 0;
}