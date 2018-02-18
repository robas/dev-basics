#include "queue.h"

queue* createQueue() {
    return createLinkedList();
}

void put(queue* queue, dataType data) {
    insertAtEnd(queue, data);
}

dataType pop(queue* queue) {
    dataType ret = getAtIndex(queue, queue->length);
    removeAtIndex(queue, queue->length);
    return ret;
}