#ifndef _STACK_H_
#define _STACK_H_

#include "linkedList.h"

typedef LinkedList Stack;

Stack* createStack();

void stackPut(Stack* stack, dataType data);

dataType stackPop(Stack* stack);

int printStack(Stack* stack);

#endif