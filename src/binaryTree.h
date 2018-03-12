#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef _KEYTYPE_
#define _KEYTYPE_
typedef int dataType;
#endif

typedef struct BTNode {
    dataType data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

typedef struct BinaryTree {
    BTNode *root;
} BinaryTree;

// Functions
BinaryTree* btCreateBinaryTree();

BTNode ** btGetParentChild(BinaryTree *bt, dataType key);

BTNode ** btGetParentChildNode(BTNode *node, dataType key);

BTNode* btCreateNode(dataType);

int btInsert(BinaryTree* bt, dataType data);

BTNode * isLeaf(BinaryTree * bt, dataType key);

BTNode * getRightmostLeaf(BTNode * node);

BTNode * getLeftmostLeaf(BTNode * node);

int btInsertNode(BTNode *root, BTNode *newNode);

int btRemoveKey(BinaryTree* bt, dataType key);

BTNode * btSearchKey(BinaryTree* bt, dataType key);

BTNode * btSearchKeyNode(BTNode * bt, dataType key);

void btPrint(BinaryTree *bt);

#endif