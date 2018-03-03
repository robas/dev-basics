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

Node* btCreateNode(dataType);

// int btInsertRoot(BinaryTree* list, dataType data);

int btInsert(BinaryTree* list, dataType data);

int btInsertNode(Node *root, Node *newNode);

int btRemoveKey(BinaryTree* list, dataType key);

int btSearchKey(BinaryTree* list, dataType key);

#endif