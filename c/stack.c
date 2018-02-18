#include "stack.h"

stack* createStack() {
    return createLinkedList();
}

void stackPut(stack* stack, dataType data) {
    insertAtStart(stack, data);
}

dataType stackPop(stack* stack) {
    dataType ret = getAtIndex(stack, 1);
    removeAtIndex(stack, 1);
    return ret;
}