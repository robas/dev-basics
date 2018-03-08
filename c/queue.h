#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "linkedList.h"

typedef LinkedList Queue;

Queue* createQueue();

void queuePut(Queue* queue, dataType data);

dataType queuePop(Queue* queue);

int printQueue(Queue* queue);

int queueIsEmpty(Queue *queue);

#endif