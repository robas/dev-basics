#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef List Queue;

Queue* createQueue(int (*equals)(void* key, void* value2), void (*customPrintItem) (void* data));

int queuePut(Queue* queue, void *data);

void *queuePop(Queue *queue);

void printQueue(Queue* queue);

int queueIsEmpty(Queue *queue);

#endif