#include "stack.h"

Stack* createStack(int (*equals)(void* key, void* value2), void (*customPrintItem) (void* data)) {
    return createList(equals, customPrintItem);
}

int stackPut(Stack* stack, void *data) {
    return insertAtStart(stack, data);
}

void *stackPop(Stack* stack) {
    void *data = getAtIndex(stack, 1);
    removeAtIndex(stack, 1);
    return data;
}

int stackIsEmpty(Stack *stack) {
    return stack->length == 0;
}