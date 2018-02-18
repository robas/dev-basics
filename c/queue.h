#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "linkedList.h"

typedef linkedList queue;

queue* createQueue();

void queuePut(queue* queue, dataType data);

dataType queuePop(queue* queue);

#endif