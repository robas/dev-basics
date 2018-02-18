#ifndef _STACK_H_
#define _STACK_H_

#include "linkedList.h"

typedef linkedList stack;

stack* createStack();

void stackPut(stack* stack, dataType data);

dataType stackPop(stack* stack);

#endif