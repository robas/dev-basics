#include "queue.h"

Queue* createQueue(int (*equals)(void* key, void* value2), void (*customPrintItem) (void* data)) {
    return createList(equals, customPrintItem);
}

int queuePut(Queue* queue, void *data) {
    return insertAtEnd(queue, data);
}

void *queuePop(Queue* queue) {
    void *data = getAtIndex(queue, 1);
    removeAtIndex(queue, 1);
    return data;
}

void printQueue(Queue* queue) {
    printList(queue);
    return;
}

int queueIsEmpty(Queue *queue) {
    return queue->length == 0;
}