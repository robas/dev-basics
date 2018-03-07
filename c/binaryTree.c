#include "binaryTree.h"

/**
 * Creates a new mallocated binary tree
 * Returns the newly created binary tree
 */
BinaryTree* btCreateBinaryTree() {
    BinaryTree* newBT = malloc(sizeof(BinaryTree));
    newBT->root = NULL;
    return newBT;
}

/**
 * Creates a new mallocated tree node with the provided key
 * Returns the newly created node
 */
Node *btCreateNode(dataType data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * Inserts a new node with the provided key into the tree
 * Returns:
 *           0: the node was correctly inserted
 *          -1: the key already exists
 */
int btInsert(BinaryTree* bt, dataType data) {
    Node *newNode = btCreateNode(data);
    if (!bt->root) {
        printf("inserting root\n");
        bt->root = newNode;
        return 0;
    } else {
        return btInsertNode(bt->root, newNode);
    }
}

int btInsertNode(Node *root, Node *newNode) {
    if (newNode->data < root->data && !root->left) {
        printf("inserting left\n");
        root->left = newNode;
        return 0;
    } else if (newNode->data > root->data && !root->right) {
        printf("inserting right\n");
        root->right = newNode;
        return 0;
    }
    
    if (newNode->data < root->data) {
        printf("menor, chamando no left\n");
        return btInsertNode(root->left, newNode);
    } else if (newNode->data > root->data) {
        printf("maior, chamando no right\n");
        return btInsertNode(root->right, newNode);
    } else {
        printf("iguaaaal\n");
        return -1;
    }
}

/**
 * Check if the intended node is a leaf (node without children)
 * Returns:
 *          NULL: the node is not a leaf
 *          Pointer to the node: if the node IS a leaf
 */
Node * isLeaf(BinaryTree * bt, dataType key) {
    Node * target = NULL;
    if ((target = btSearchKey(bt, key)) == NULL) {
        return NULL;
    } else {
        return (!target->left && !target->right) ? target : NULL;
    }
}

/**
 * Search for the parent of the node containing the provided key
 * Returns:
 *          NULL: if the tree is empty or the key was not found
 *          Pointer to the intended node's parent ->left or ->right depending if the intended node is a left or right child
 */
Node ** btGetParentChild(BinaryTree *bt, dataType key) {
    if (bt->root) {
        if (bt->root->data == key) {
            return &bt->root;
        } else {
            return btGetParentChildNode(bt->root, key);
        }
    } else {
        return NULL;
    }
}

Node ** btGetParentChildNode(Node *node, dataType key) {
    if (node->left->data == key) {
        return &node->left;
    } else if (node->right->data == key) {
        return &node->right;
    } else if (key < node->data) {
        return (node->left) ? btGetParentChildNode(node->left, key) : NULL;
    } else if (key > node->data) {
        return (node->right) ? btGetParentChildNode(node->right, key) : NULL;
    } else {
        return NULL;
    }
}

/**
 * Removes the node with the provided key from the tree
 * Returns:
 *           0: the removal was a success
 *          -1: the provided key does not exist
 */
int btRemoveKey(BinaryTree* bt, dataType key) {
    Node * target = NULL;
    Node ** targetParentChild = NULL;
    int targetIsNotRoot = TRUE;

    // Key does not exist in the tree
    if ((target = btSearchKey(bt, key)) == NULL) {
        return -1;
    }
    
    // targetParentChild is a pointer to the target's parent ->left or ->right depending if the target is a left or right child
    targetIsNotRoot = (targetParentChild = btGetParentChild(bt, key)) != NULL ? TRUE : FALSE;

    // Key is a leaf node
    if (!target->left && !target->right) {
        *targetParentChild = NULL;
        
    // Key has only left child
    } else if (target->left && !target->right) {
        *targetParentChild = target->left;
        
    // Key has only right child
    } else if (!target->left && target->right) {
        *targetParentChild = target->right;
        
    // Key has two children
    } else {
        // Improvement: Here fits some optimization on the choose between the "leftmost from right" or "rightmost from left" node to keep the tree well balanced
        //              Currently using the replacement node as the leftmost leaf from right
        Node * replacement = getLeftmostLeaf(target->right);
        Node ** replacementParentChild = btGetParentChild(bt, replacement->data);

        // If replacement is the target left or right child, it must be NULL
        replacement->left = (target->left == replacement) ? NULL : target->left;
        replacement->right = (target->right == replacement) ? NULL : target->right;
        
        // Updates the replacement parent and the removed target parent
        *replacementParentChild = NULL;
        *targetParentChild = replacement;
    }
    
    free(target);
    return 0;
}

/**
 * Searchs the tree for the provided key
 * Returns:
 *          NULL: the key is empty or was not found
 *          Pointer to the intended node
 */
Node * btSearchKey(BinaryTree* bt, dataType key) {
    if (!bt->root) {
        return NULL;
    } else {
        return btSearchKeyNode(bt->root, key);
    }
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


Node * getLeftmostLeaf(Node * node) {
    return (!node->left) ? node : getLeftmostLeaf(node->left);
}

Node * getRightmostLeaf(Node * node) {
    return (!node->right) ? node : getRightmostLeaf(node->right);
}

