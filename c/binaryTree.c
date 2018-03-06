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
    newNode->parent = NULL;
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

int btRemove(BinaryTree* bt, dataType key) {
    return 0;
}

int btInsertNode(Node *root, Node *newNode) {
    if (newNode->data < root->data && !root->left) {
        root->left = newNode;
        newNode->parent = root;
        return 0;
    } else if (newNode->data > root->data && !root->right) {
        root->right = newNode;
        newNode->parent = root;
        return 0;
    }
    
    if (newNode->data < root->data) {
        btInsertNode(root->left, newNode);
    } else {
        btInsertNode(root->right, newNode);
    }
    return 0;
}

Node * isLeaf(BinaryTree * bt, dataType key) {
    Node * target = NULL;
    if ((target = btSearchKey(bt, key)) == NULL) {
        return NULL;
    } else {
        return (!target->left && !target->right) ? target : NULL;
    }
}

int btRemoveKey(BinaryTree* bt, dataType key) {
    Node * target = NULL;
    Node ** parent_pointer = NULL;
    int targetIsNotRoot = TRUE;
    printf("Removendo %d\n", key);

    // Key not on the tree
    if ((target = btSearchKey(bt, key)) == NULL) {
        return -1;
    }
    
    targetIsNotRoot = target->parent != NULL ? TRUE : FALSE;
    if (targetIsNotRoot) {
        parent_pointer = target->parent->left == target ? &target->parent->left : &target->parent->right;
    }

    // Key is a leaf node
    if (!target->left && !target->right) {
        printf("leaf node\n");
        if (targetIsNotRoot) {
            *parent_pointer = NULL;
        }
    // Key has only left child
    } else if (target->left != NULL && target->right == NULL) {
        printf("Tem 1 filho a esquerda\n");
        if (targetIsNotRoot) {
            *parent_pointer = target->left;
        }
        target->left->parent = target->parent;
    // Key has only right child
    } else if (target->left == NULL && target->right != NULL) {
        printf("Tem 1 filho a direita\n");
        if (targetIsNotRoot) {
            *parent_pointer = target->right;
        }
        target->right->parent = target->parent;
    // Key has two children
    } else {
        // TODO: here fits some optimization on the choose of left or rightmost node
        // to keep the tree well balanced
        Node * leftmostLeafFromRightChild = getLeftmostLeaf(target->right);
        Node ** leftmostLeafFromRightChildParent_pointer = leftmostLeafFromRightChild->parent->left == leftmostLeafFromRightChild ? &leftmostLeafFromRightChild->parent->left : &leftmostLeafFromRightChild->parent->right;
        printf("The leftmostLeaf is %d\n", leftmostLeafFromRightChild->data);
        leftmostLeafFromRightChild->left = target->left;
        leftmostLeafFromRightChild->right = target->right;
        *leftmostLeafFromRightChildParent_pointer = NULL;
        leftmostLeafFromRightChild->parent = target->parent;
        if (targetIsNotRoot) {
            *parent_pointer = leftmostLeafFromRightChild;
        }
    }

    // Key is root, update the bt->root
    if (!targetIsNotRoot) {
        bt->root = NULL;
    }
    free(target);
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

Node * getLeftmostLeaf(Node * node) {
    return (!node->left) ? node : getLeftmostLeaf(node->left);
}

Node * getRightmostLeaf(Node * node) {
    return (!node->right) ? node : getRightmostLeaf(node->right);
}

Node * btSearchKeyNode(Node *node, dataType key) {
    if (node->data == key) {
        return node;
    } else if (key < node->data) {
        return (node->left) ? btSearchKeyNode(node->left, key) : NULL;
    } else if (key > node->data) {
        return (node->right) ? btSearchKeyNode(node->right, key) : NULL;
    } else {
        return NULL;
    }
}