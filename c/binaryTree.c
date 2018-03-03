#include "binaryTree.h"

BinaryTree* btCreateBinaryTree() {
    BinaryTree* newBT = malloc(sizeof(BinaryTree));
    newBT->root = NULL;
    return newBT;
}

Node *btCreateNode(dataType data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// int btInsertRoot(BinaryTree* bt, dataType data) {
//     Node *newNode = btCreateNode(data);
//     if (!bt->root) {
//         bt->root = newNode;
//     } else {
//         // Handle most complex case
//     }
    
//     return 0;
// }

int btInsert(BinaryTree* bt, dataType data) {
    Node *newNode = btCreateNode(data);
    if (!bt->root) {
        bt->root = newNode;
    } else {
        btInsertNode(bt->root, newNode);
    }
    
    return 0;
}

int btInsertNode(Node *root, Node *newNode) {
    if (newNode->data < root->data && !root->left) {
        root->left = newNode;
        return 0;
    } else if (newNode->data > root->data && !root->right) {
        root->right = newNode;
        return 0;
    }
    
    if (newNode->data < root->data) {
        btInsertNode(root->left, newNode);
    } else {
        btInsertNode(root->right, newNode);
    }
    
    return 0;
}

int btRemoveKey(BinaryTree* bt, dataType key) {
    return 0;
}

Node * btSearchKey(BinaryTree* bt, dataType key) {
    if (!bt->root) {
        return NULL;
    } else {
        return btSearchKeyNode(bt->root, key);
    }
    return 0;
}

// testar!!!
Node * btSearchKeyNode(Node *node, dataType key) {
    if (node->data == key) {
        return node;
    } else if (key < node->data) {
        return (node->left) ? btSearchKeyNode(node->left, key) : NULL;
    } else if (key > node->data) {
        return (node->right) ? btSearchKeyNode(node->right, key) : NULL;
    }
}