#include "linkedList.h"

/**
 * Creates a new Linked List, setting its attributes and 'methods' (function pointers)
 * if the function pointer argument is NULL, the Linked List assumes it's own and default
 * implementation.
 * The default 'Equals' function that assumes the key is an integer
 * Returns: a pointer to the created Linked List
 */
LinkedList* createLinkedList(int (*customEqualsFunction) (void *value1, void *value2)) {
    LinkedList* newList = malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->length = 0;
    
    newList->equals = customEqualsFunction ? customEqualsFunction : &defaultEquals;
    return newList;
}

/**
 * Compares two values, assuming they are both integers
 * Returns:
 *          TRUE: if the values are equal
 *          FALSE: if the values are not equal
 */
int defaultEquals (void *_key, void *data) {
    int *value = data;
    int *key = _key;
    return (*key == *value) ? TRUE : FALSE;
}

/**
 * Creates a new linked list Node
 * Returns:
 *          On succcess: a pointer to the created node
 *          On failure:  a NULL pointer
 */
Node *createNode(void *data) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}


/**
 * Calculates the list length, not very usefull, since the data structure has a 'length' field
 * Returns:
 *          On success: the number (int) of items in the list
 *          On failure: -1
 */
int listLength(LinkedList* list) {
    if (!list) return -1;
    
    int i = 0;
    for (Node *iterator = list->head; iterator; iterator = iterator->next) {
        i++;
    }
    return i;
}

/**
 * Gets the Node at the provided index, considering an 1 based array
 * Returns:
 *          On success: a pointer to the Node at the provided index
 *          On failure: a NULL pointer
 */
void * getAtIndex(LinkedList *list, int index) {
    if (!list) return NULL;
    if (index > list->length || index < 1) {
        return NULL;
    } else {
        Node *iterator = list->head;
        // TODO: colocar o for em uma linha só
        for (int i = 1; i < index && iterator->next; i++) {
            iterator = iterator->next;
        }
        return iterator->data;
    }
}

/**
 * Inserts the provided data as the first item in the list.
 * All the data intended to be inserted into the list is referenced by
 * a pointer to void, since we don't know the data type
 * Returns: 
 *          On success: TRUE
 *          On failure: FALSE 
 */ 
int insertAtStart(LinkedList* list, void *data) {
    if (!list) return FALSE;
    
    Node *newNode = createNode(data);
    if (!newNode) {
        return FALSE;
    } else {
        newNode->next = list->head;
        list->head = newNode;
        list->length++;
        return TRUE;
    }
}

/**
 * Inserts the provided data as the last item in the list.
 * All the data intended to be inserted into the list is referenced by
 * a pointer to void, since we don't know the data type
 * Returns: 
 *          On success: TRUE
 *          On failure: FALSE
 */
int insertAtEnd(LinkedList* list, void *data) {
    if (!list) return FALSE;
    
    Node *newNode = createNode(data);
    if (!newNode) {
        return FALSE;
    } else {
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
        return TRUE;
    }
}

/**
 * Inserts the provided data in the list at the specified index,
 * considering an 1 based array
 * All the data intended to be inserted into the list is referenced by
 * a pointer to void, since we don't know the data type
 * Returns: 
 *          On success: TRUE
 *          On failure: FALSE
 */
int insertAtIndex(LinkedList* list, void *data, int index) {
    if (!list) return FALSE;
    
    if (index > list->length+1 || index < 1)
        return FALSE;

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
    return TRUE;
}

/**
 * Deletes the first entry which key corresponds to the provided key
 * The key is referenced by a pointer to void, since we don't know the data type
 * Returns: 
 *          On success: TRUE
 *          On failure (did not find the key): FALSE
 */
int removeKey(LinkedList *list, void *key) {
    if (!list) return FALSE;
    
    if (list->equals(key, list->head->data)) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->length--;
        return TRUE;
    } else {
        Node *iterator = list->head;
        while (iterator->next) {
            if (list->equals(key, iterator->next->data)) {
                Node *temp = iterator->next;
                iterator->next = iterator->next->next;
                free(temp);
                list->length--;
                return TRUE;
            } else {
                iterator = iterator->next;
            }
        }
    }
    return FALSE;
}

/**
 * Deletes the entry at the provided key, considering an 1 based array
 * Returns: 
 *          On success: TRUE
 *          On failure (invalid index): FALSE
 */
int removeAtIndex(LinkedList *list, int index) {
    if (!list) return FALSE;
    
    if (index < 1 || index > list->length) {
        return FALSE;
    } else {
        if (index == 1) {
            Node *temp = list->head;
            list->head = temp->next;
            free(temp);
        } else {
            Node *iterator = list->head;
        
            for (int i = 1; i < index-1 && iterator->next; i++, iterator = iterator->next);
            Node *temp = iterator->next;
            iterator->next = iterator->next->next;
            free(temp);
        }
        list->length--;
        return TRUE;
    }
}

/**
 * Searches for the provided key into the list
 * Returns:
 *          On success (the key exists): TRUE
 *          On failure (the does not exists): FALSE
 */
int searchKey(LinkedList *list, void *key) {
    if (!list) return FALSE;
    
    for (Node *iterator = list->head; iterator; iterator = iterator->next) {
        if (list->equals(key, iterator->data))
            return TRUE;
    }
    return FALSE;
}

/**
 * Reverses the list elements
 * Returns:
 *          On success: TRUE
 *          On failure: FALSE
 */
int reverseList(LinkedList *list) {
    if (!list) return FALSE;
    
    if (list->length <= 1)
        return TRUE;

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
    return TRUE;
}