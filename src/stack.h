#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef List Stack;

Stack* createStack(int (*equals)(void* key, void* value2), void (*customPrintItem) (void* data));

int stackPut(Stack *stack, void *data);

void *stackPop(Stack* stack);

void printStack(Stack* stack);

int stackIsEmpty(Stack *stack);

#endif