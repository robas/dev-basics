#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct BTNode {
    void *data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

typedef struct BinaryTree {
    BTNode *root;
    void (*printItem) (void *data);
    int (*compare) (void *key, void *data);
} BinaryTree;

// Functions
BinaryTree* btCreateBinaryTree(int (*customCompare)(void *key, void *value2), void (*customPrintItem) (void *data));

int defaultCompare(void* key, void* data);

void defaultPrintBtItem(void* data);

BTNode ** btGetParentChild(BinaryTree *bt, void *key);

BTNode ** btGetParentChildNode(BTNode *node, void *key);

BTNode* btCreateNode(void *data);

int btInsert(BinaryTree* bt, void *data);

BTNode * isLeaf(BinaryTree * bt, void *key);

BTNode * getRightmostLeaf(BTNode * node);

BTNode * getLeftmostLeaf(BTNode * node);

int btInsertNode(BTNode *root, BTNode *newNode);

int btRemoveKey(BinaryTree* bt, void *key);

BTNode * btSearchKey(BinaryTree* bt, void *key);

BTNode * btSearchKeyNode(BTNode * bt, void *key);

// TODO
// void btPrint(BinaryTree *bt);

#endif