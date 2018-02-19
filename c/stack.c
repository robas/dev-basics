#include "stack.h"

Stack* createStack() {
    return createLinkedList();
}

void stackPut(Stack* stack, dataType data) {
    insertAtStart(stack, data);
}

dataType stackPop(Stack* stack) {
    dataType ret = getAtIndex(stack, 1);
    removeAtIndex(stack, 1);
    return ret;
}