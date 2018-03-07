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
typedef int dataType;

typedef struct Node {
    dataType data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct BinaryTree {
    Node *root;
} BinaryTree;

// Functions
BinaryTree* btCreateBinaryTree();

Node ** btGetParentChild(BinaryTree *bt, dataType key);

Node ** btGetParentChildNode(Node *node, dataType key);

Node* btCreateNode(dataType);

int btInsert(BinaryTree* list, dataType data);

Node * isLeaf(BinaryTree * bt, dataType key);

Node * getRightmostLeaf(Node * node);

Node * getLeftmostLeaf(Node * node);

int btInsertNode(Node *root, Node *newNode);

int btRemoveKey(BinaryTree* list, dataType key);

Node * btSearchKey(BinaryTree* list, dataType key);

Node * btSearchKeyNode(Node * list, dataType key);

#endif