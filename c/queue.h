#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "linkedList.h"

typedef linkedList queue;

queue* createQueue();

void put(queue* queue, dataType data);

dataType pop(queue* queue);

#endif