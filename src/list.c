#include "list.h"

/**
 * Creates a new Linked List, setting its attributes and 'methods' (function pointers)
 * if the function pointer argument is NULL, the Linked List assumes it's own and default
 * implementation.
 * The default 'Equals' function that assumes the key is an integer
 * Returns: a pointer to the created Linked List
 */
List* createList(int (*customEquals) (void *key, void *data), void (*customPrintItem) (void *data)) {
    List* newList = malloc(sizeof(List));
    newList->head = NULL;
    newList->length = 0;
    newList->equals = customEquals ? customEquals : &defaultEquals;
    newList->printItem = customPrintItem ? customPrintItem : &defaultPrintItem;
    return newList;
}

/**
 * Compares two values, assuming they are both integers
 * Returns:
 *          true: if the values are equal
 *          false: if the values are not equal
 */
int defaultEquals(void *_key, void *data) {
    int *value = data;
    int *key = _key;
    return *key == *value;
}

/**
 * Prints a list item assuming the item is an integer
 */
void defaultPrintItem(void *data) {
    if (data) {
        int *value = data;
        printf("%d ", *value);
    }
    return;
}

/**
 * Prints the provided list
 */
void printList(List* list) {
    if (!list) {
        printf("The list is empty\n");
        return;
    }
    if (!list->head) {
        printf("The list is empty\n");
        return;
    }
    
    Node* iterator = list->head;
    for (Node* iterator = list->head; iterator; iterator = iterator->next) {
        list->printItem(iterator->data);
    }
    printf("\n");
    return;
}

/**
 * Creates a new linked list Node
 * Returns:
 *          On succcess: a pointer to the created node
 *          On failure:  a NULL pointer
 */
Node *createNode(void *data) {
    if (!data) return NULL;
    
    Node *newNode = malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}


/**
 * Calculates the list length, not very usefull, since the List data structure has a 'length' field
 * Returns:
 *          On success: the number (int) of items in the list
 *          On failure: -1
 */
int listLength(List* list) {
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
void * getAtIndex(List *list, int index) {
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
 *          On success: true
 *          On failure: false 
 */ 
int insertAtStart(List* list, void *data) {
    if (!list || !data) return false;
    
    Node *newNode = createNode(data);
    if (!newNode) {
        return false;
    } else {
        newNode->next = list->head;
        list->head = newNode;
        list->length++;
        return true;
    }
}

/**
 * Inserts the provided data as the last item in the list.
 * All the data intended to be inserted into the list is referenced by
 * a pointer to void, since we don't know the data type
 * Returns: 
 *          On success: true
 *          On failure: false
 */
int insertAtEnd(List* list, void *data) {
    if (!list || !data) return false;
    
    Node *newNode = createNode(data);
    if (!newNode) {
        return false;
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
        return true;
    }
}

/**
 * Inserts the provided data in the list at the specified index,
 * considering an 1 based array
 * All the data intended to be inserted into the list is referenced by
 * a pointer to void, since we don't know the data type
 * Returns: 
 *          On success: true
 *          On failure: false
 */
int insertAtIndex(List* list, void *data, int index) {
    if (!list || !data) return false;
    
    if (index > list->length+1 || index < 1)
        return false;

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
    return true;
}

/**
 * Deletes the first entry which key corresponds to the provided key
 * The key is referenced by a pointer to void, since we don't know the data type
 * Returns: 
 *          On success: true
 *          On failure (did not find the key): false
 */
int removeKey(List *list, void *key) {
    if (!list || !key) return false;
    
    if (list->equals(key, list->head->data)) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->length--;
        return true;
    } else {
        Node *iterator = list->head;
        while (iterator->next) {
            if (list->equals(key, iterator->next->data)) {
                Node *temp = iterator->next;
                iterator->next = iterator->next->next;
                free(temp);
                list->length--;
                return true;
            } else {
                iterator = iterator->next;
            }
        }
    }
    return false;
}

/**
 * Deletes the entry at the provided key, considering an 1 based array
 * Returns: 
 *          On success: true
 *          On failure (invalid index): false
 */
int removeAtIndex(List *list, int index) {
    if (!list) return false;
    
    if (index < 1 || index > list->length) {
        return false;
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
        return true;
    }
}

/**
 * Searches for the provided key into the list
 * Returns:
 *          On success (the key exists): the item index, considering an 1 based list
 *          On failure (the does not exists): 0
 */
int searchKey(List *list, void *key) {
    if (!list || !key) return 0;
    
    int index = 1;
    for (Node *iterator = list->head; iterator; iterator = iterator->next,index++) {
        if (list->equals(key, iterator->data))
            return index;
    }
    return 0;
}

/**
 * Reverses the list elements
 * Returns:
 *          On success: true
 *          On failure: false
 */
int reverseList(List *list) {
    if (!list) return false;
    
    if (list->length <= 1)
        return true;

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
    return true;
}