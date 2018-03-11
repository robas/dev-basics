#ifndef _STACK_H_
#define _STACK_H_

#include "linkedList.h"

typedef LinkedList Stack;

Stack* createStack();

void stackPut(Stack* stack, Key key, void * data);

void * stackPop(Stack* stack);

int printStack(Stack* stack);

int stackIsEmpty(Queue *queue);

#endif