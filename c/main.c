#include "list.h"

struct lala {
    int key;
    char letra;
    int idade;
    int uptime;
};


int compare (void *key, void *data) {
    char *val1 = key;
    struct lala *val2 = data;
    
    return *val1 == val2->key;
}

int main() {
    printf("Initializing linkedList\n");
    // List* myList = createList(compare);
    List* myList = createList(NULL, NULL);
    printf("%d\n", listLength(myList));

    struct lala *no1 = malloc(sizeof(struct lala));
    no1->key = 1;
    no1->letra = 'r';
    no1->idade = 32;
    no1->uptime = 100432;
    
    struct lala *no2 = malloc(sizeof(struct lala));
    no2->key = 2;
    no2->letra = 'y';
    no2->idade = 19;
    no2->uptime = 919191;
    
    struct lala *no3 = malloc(sizeof(struct lala));
    no3->key = 3;
    no3->letra = 'z';
    no3->idade = 23;
    no3->uptime = 666;
    // char id = 'k';
    // void *vid = &id;
    
    // if (myList->compare(vid, node->data) ) {
    //     printf("\nieiii\n");
    // }
    
    int b = 1;
    int *a = &b;
    
    insertAtStart(myList, no1);
    printf("%d\n", listLength(myList));
    
    insertAtEnd(myList, no2);
    printf("%d\n", listLength(myList));
    printList(myList);
    searchKey(myList, a) ? printf("encontrou %d\n", *a) : printf("NAO encontrou %d\n", *a);
    
    removeKey(myList, a);
    
    searchKey(myList, a) ? printf("encontrou %d\n", *a) : printf("NAO encontrou %d\n", *a);
    
    insertAtIndex(myList, no3, 2);
    printList(myList);
    
    *a = 2;
    searchKey(myList, a) ? printf("encontrou %d\n", *a) : printf("NAO encontrou %d\n", *a);
    

    
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
    
    // BinaryTree *bt = btCreateBinaryTree();
    // btInsert(bt, 2);
    // btInsert(bt, 5);
    // btInsert(bt, 0);
    // btInsert(bt, 1);
    // btInsert(bt, 7);
    // btInsert(bt, 6);
    // btInsert(bt, 4);
    // btInsert(bt, 5);
    // btInsert(bt, 9);
    // btInsert(bt, 10);
    // btInsert(bt, -1);
    // btInsert(bt, 8);
    // int key;
    // BTNode *node = NULL;
    

    // btPrint(bt);
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