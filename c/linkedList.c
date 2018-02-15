#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef char dataType;

typedef struct node {
    dataType data;
    struct node *next;
} node;

node *initNode(dataType data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;    
}

void printList(node *node) {
    if (!node) {
        printf("The list is empty\n");
        return;
    }

    while (node) {
        printf("%c", node->data);
        node = node->next;
    }
    printf("\n");
}

int listLength(node *head) {
    int i = 0;
    for (node *iterator = head; iterator; iterator = iterator->next) {
        i++;
    }
    return i;
}

void insertAtStart(node **head, dataType data) {
    node *newNode = initNode(data);
    newNode->next = *head;
    *head = newNode;
    return;
}

void insertAtEnd(node **head, dataType data) {
    node *newNode = initNode(data);

    if (!*head) {
        *head = newNode;
        return;
    }

    node *iterator = *head;
    while (iterator->next) {
        iterator = iterator->next;
    }
    iterator->next = newNode;
    return;
}

// Inserts data at the specified index, considering an 1 based array
void insertAtIndex(node **head, dataType data, int index) {
    if (index > listLength(*head)+1 || index <= 0)
        return;

    node *newNode = initNode(data);
    if (index == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    node *iterator = *head;

    for (int i = 1; i < index-1 && iterator->next; i++) {
        iterator = iterator->next;
    }
    newNode->next = iterator->next;
    iterator->next = newNode;
    return;
}

// Deletes the first node entry which data corresponds to the specified key
void deleteKey(node **head, dataType key) {
    if ((*head)->data == key) {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    node *iterator = NULL;
    for (iterator = *head; iterator->next->data != key && iterator->next; iterator = iterator->next);
    node *temp = iterator->next;
    iterator->next = iterator->next->next;
    free(temp);
    return;
}

// Deletes the node at the specified index, considering an 1 based array
void deleteAtIndex(node **head, int index) {
    if (index <= 0 || index > listLength(*head))
        return;
    if (index == 1) {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    node *iterator = *head;

    for (int i = 1; i < index-1 && iterator->next; i++) {
        iterator = iterator->next;
    }
    node *temp = iterator->next;
    iterator->next = iterator->next->next;
    free(temp);
    return;
}

// Returns true if the specified key exists in the list
int searchKey(node *head, dataType key) {
    for (node *iterator = head; iterator; iterator = iterator->next) {
        if (iterator->data == key)
            return TRUE;
    }
    return FALSE;
}

void reverseList(node **head) {
    if (listLength(*head) == 1)
        return;

    node *p1 = *head;
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
    *head = p2;
    return;
}

int main() {
    // testing the above linked list data structure and algorithm
    node *head = NULL;
    node *head2 = NULL;
    
    insertAtStart(&head, 'A');
    insertAtStart(&head, 'B');
    insertAtStart(&head, 'z');
    insertAtEnd(&head, 'o');
    insertAtEnd(&head, 'z');
    insertAtStart(&head, 'a');
    
    
    insertAtIndex(&head, '2', 2);
    insertAtIndex(&head, '8', 8);
    insertAtIndex(&head, '1', 1);

    printList(head);
    printf("%d\n", listLength(head));

    deleteKey(&head, 'a');
    printList(head);
    printf("%d\n", listLength(head));

    deleteKey(&head, 'z');
    printList(head);
    printf("%d\n", listLength(head));

    deleteKey(&head, '8');
    printList(head);
    printf("%d\n", listLength(head));

    deleteAtIndex(&head, 3);
    printList(head);
    printf("%d\n", listLength(head));

    deleteAtIndex(&head, 1);
    printList(head);
    printf("%d\n", listLength(head));

    deleteAtIndex(&head, 4);
    printList(head);
    printf("%d\n", listLength(head));
    
    if (searchKey(head, 'B'))
        printf("B encontrado\n");
    
    insertAtEnd(&head2, 'b');
    insertAtEnd(&head2, 'o');
    insertAtEnd(&head2, 'z');
    insertAtEnd(&head2, 'a');
    insertAtEnd(&head2, 'a');
    insertAtEnd(&head2, 'n');
    printList(head2);
    reverseList(&head2);
    printList(head2);
    
    
}