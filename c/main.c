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
    printf("%d\n", btInsert(bt, 2));
    printf("%d\n", btInsert(bt, 5));
    printf("%d\n", btInsert(bt, 0));
    // btInsert(bt, 1);
    // btInsert(bt, 7);
    // btInsert(bt, 6);
    printf("%d\n", btInsert(bt, 4));
    printf("%d\n", btInsert(bt, 5));
    // btInsert(bt, 9);
    // btInsert(bt, 10);
    // btInsert(bt, -1);
    // btInsert(bt, 8);
    int key;
    Node *node = NULL;
    
    // isLeaf(bt, key) ? printf("%d é folha\n") : printf("%d não é folha\n");
    // printf("LeftmostLeaf %d\n", getLeftmostLeaf(bt->root)->data);
    // printf("RightmostLeaf %d\n", getRightmostLeaf(bt->root)->data);
    // key = 9;
    // btRemoveKey(bt, key);
    // (node = btSearchKey(bt, key)) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    // printf("Right: %d \t Left: %d\n", node->right, node->left);
    // btRemoveKey(bt, key);
    
    // key = 2;
    // (node = btSearchKey(bt, key)) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    // btRemoveKey(bt, key);
    // (node = btSearchKey(bt, key)) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    
    // printf("Root Data %d\n", bt->root->data);
    // printf("Left %d\n", bt->root->left);
    // printf("Right %d\n", bt->root->right);
    
    // printf("Left Data %d\n", bt->root->left->data);
    // printf("Left->left %d\n", bt->root->left->left);
    // printf("Left->right %d\n", bt->root->left->right);
    
    // printf("Right Data %d\n", bt->root->right->data);
    // printf("Right->left %d\n", bt->root->right->left);
    // printf("Right->right %d\n", bt->root->right->right);
    // printf("Right Data %d\n", bt->root->right->data);
    
    // printf("Left Data %d\n", bt->root->left->data);
    // printf("Left %d\n", bt->root->left->left);
    // printf("Right %d\n", bt->root->left->right);
    // key = 6;
    // (node = btSearchKey(bt, key)) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    // printf("Left %d\n", node->left->data);
    // printf("Right %d\n", node->right->right->right->data);
    
    // key = -1;
    // btRemoveKey(bt, key);
    // key = 0;
    // (node = btSearchKey(bt, key)) ? printf("encontrei %d\n",key) : printf("não encontrei %d\n", key);
    // printf("Left %d\n", node->left);
    // printf("Right %d\n", node->right);
    
    
    return 0;
}