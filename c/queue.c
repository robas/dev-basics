#include "queue.h"

queue* createQueue() {
    return createLinkedList();
}

void queuePut(queue* queue, dataType data) {
    insertAtEnd(queue, data);
}

dataType queuePop(queue* queue) {
    dataType ret = getAtIndex(queue, 1);
    removeAtIndex(queue, 1);
    return ret;
}