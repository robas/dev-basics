#include "linkedList.h"

LinkedList* createLinkedList() {
    LinkedList* newList = malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->length = 0;
    return newList;
}

Node *createNode(dataType data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;    
}

int printList(LinkedList* list) {
    if (!list->head) {
        printf("The list is empty\n");
    } else {
        Node* iterator = list->head;
        for (Node* iterator = list->head; iterator; iterator = iterator->next) {
            printf("%c", iterator->data);
        }
        printf("\n");
    }
    return 0;
}

int listLength(LinkedList* list) {
    int i = 0;
    for (Node *iterator = list->head; iterator; iterator = iterator->next) {
        i++;
    }
    return i;
}

// Returns the data at the specified index, considering an 1 based array
dataType getAtIndex(LinkedList *list, int index) {
    if (index > list->length || index < 1)
        return '\0';

    Node *iterator = list->head;
    for (int i = 1; i < index && iterator->next; i++) {
        iterator = iterator->next;
    }
    
    return iterator->data;
}

int insertAtStart(LinkedList* list, dataType data) {
    Node *newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
    list->length++;
    return 0;
}

int insertAtEnd(LinkedList* list, dataType data) {
    Node *newNode = createNode(data);

    if (!list->head) {
        list->head = newNode;
    } else {

        Node *iterator = list->head;
        while (iterator->next) {
            iterator = iterator->next;
        }
        iterator->next = newNode;
    }
    list->length++;
    return 0;
}

// Inserts data at the specified index, considering an 1 based array
int insertAtIndex(LinkedList* list, dataType data, int index) {
    if (index > list->length+1 || index < 1)
        return -1;

    Node *newNode = createNode(data);
    if (index == 1) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node *iterator = list->head;
    
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
int removeKey(LinkedList *list, dataType key) {
    if (list->head->data == key) {
        Node *temp = list->head;
        list->head = temp->next;
        free(temp);
    } else {
        Node *iterator = NULL;
        for (iterator = list->head; iterator->next->data != key && iterator->next; iterator = iterator->next);
        Node *temp = iterator->next;
        iterator->next = iterator->next->next;
        free(temp);
    }
    list->length--;
    return 0;
}

// Deletes the node at the specified index, considering an 1 based array
int removeAtIndex(LinkedList *list, int index) {
    if (index < 1 || index > list->length)
        return -1;
    if (index == 1) {
        Node *temp = list->head;
        list->head = temp->next;
        free(temp);
    } else {
        Node *iterator = list->head;
    
        for (int i = 1; i < index-1 && iterator->next; i++) {
            iterator = iterator->next;
        }
        Node *temp = iterator->next;
        iterator->next = iterator->next->next;
        free(temp);
    }
    list->length--;
    return 0;
}

// Returns true if the specified key exists in the list
int searchKey(LinkedList *list, dataType key) {
    for (Node *iterator = list->head; iterator; iterator = iterator->next) {
        if (iterator->data == key)
            return TRUE;
    }
    return FALSE;
}

int reverseList(LinkedList *list) {
    if (list->length == 1)
        return 0;

    Node *p1 = list->head;
    Node *p2 = p1->next;
    Node *p3 = p2->next;
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