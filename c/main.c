#include "binaryTree.h"

int main() {
    // printf("Initializing linkedList\n");
    // linkedList* myList = createLinkedList();
    // printf("%d\n", listLength(myList));
    // insertAtStart(myList, 'b');
    // printf("%d\n", listLength(myList));
    // insertAtStart(myList, 'a');
    // printf("%d\n", listLength(myList));
    // insertAtEnd(myList, 'c');
    // insertAtIndex(myList, 'd', 4);
    // printList(myList);
    // printf("%d\n", listLength(myList));
    // printf("%c\n", getAtIndex(myList, 0));
    // printf("%c\n", getAtIndex(myList, 1));
    // printf("%c\n", getAtIndex(myList, 2));
    // printf("%c\n", getAtIndex(myList, 3));
    // printf("%c\n", getAtIndex(myList, 4));
    // printf("%c\n", getAtIndex(myList, 5));
    
    // removeKey(myList, 'c');
    
    // if (searchKey(myList, 'c'))
    //     printf("e está na lista\n");
    // else
    //     printf("e não está na lista\n");
    
    
    // insertAtEnd(myList, 'f');
    // printList(myList);
    // removeAtIndex(myList, 1);
    // printList(myList);
    // insertAtStart(myList, 'b');
    // insertAtIndex(myList, 'a', 1);
    // printList(myList);
    // reverseList(myList);
    // printList(myList);
    
    // removeKey(myList,'b');
    
    // printList(myList);
    // removeAtIndex(myList, myList->length);
    // printList(myList);
    // removeAtIndex(myList, myList->length);
    // printList(myList);
    // removeAtIndex(myList, myList->length);
    // printList(myList);
    // removeAtIndex(myList, myList->length);
    // printList(myList);
    
    // Stack * myStack = createStack();
    // stackPut(myStack, 'a');
    // stackPut(myStack, 'b');
    // stackPut(myStack, 'c');
    // myStack->print(myStack);
    
    // printf("%c\n",stackPop(myStack));
    // printf("%c\n",stackPop(myStack));
    // printf("%c\n",stackPop(myStack));
    // printf("%c\n",stackPop(myStack));
    // printf("%c\n",stackPop(myStack));
    // printf("%c\n",stackPop(myStack));
    
    BinaryTree *bt = btCreateBinaryTree();
    btInsert(bt, 2);
    btInsert(bt, 5);
    btInsert(bt, 0);
    btInsert(bt, 1);
    btInsert(bt, 7);
    btInsert(bt, 6);
    btInsert(bt, 4);
    btInsert(bt, 9);
    btInsert(bt, 10);
    btInsert(bt, -1);
    btInsert(bt, 8);
        
    isLeaf(bt, 5) ? printf("folha\n") : printf("nao folha\n");

    printf("%d\n", getLeftmostLeaf(bt->root)->data);
    printf("%d\n", getRightmostLeaf(bt->root)->data);
    
    int key = 7;
    btRemoveKey(bt, key);
    btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);

    key = 9;
    btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    key = 8;
    btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    key = 10;
    btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    key = 6;
    btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    
    key = 10;
    btRemoveKey(bt, key);
    btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    key = 9;
    btRemoveKey(bt, key);
    btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    key = 8;
    btRemoveKey(bt, key);
    btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);

    key = 6;
    btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    // key = 7;
    // btRemoveKey(bt, key);
    // btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);

    // key = 6;
    // btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);

    // key = -1;
    // btRemoveKey(bt, key);
    // btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);

    // key = 0;
    // btRemoveKey(bt, key);
    // btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);

    // key = 1;
    // btSearchKey(bt, key) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    return 0;
}