#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <stdlib.h>
#include <stdio.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

// Data structures

#ifndef _DATATYPE_
#define _DATATYPE_
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