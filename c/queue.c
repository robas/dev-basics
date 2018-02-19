#include "queue.h"

Queue* createQueue() {
    return createLinkedList();
}

void queuePut(Queue* queue, dataType data) {
    insertAtEnd(queue, data);
}

dataType queuePop(Queue* queue) {
    dataType ret = getAtIndex(queue, 1);
    removeAtIndex(queue, 1);
    return ret;
}