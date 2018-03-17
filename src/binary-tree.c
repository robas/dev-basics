#include <limits.h>
#include "binary-tree.h"
#include "queue.h"
#include <stdio.h>

/**
 * Creates a new mallocated binary tree
 * Returns the newly created binary tree
 */
BinaryTree* btCreateBinaryTree(int (*customCompare)(void *key, void *value2), void (*customPrintItem) (void *data)) {
    BinaryTree* newBT = malloc(sizeof(BinaryTree));
    newBT->root = NULL;
    newBT->compare = customCompare ? customCompare : &defaultCompare;
    newBT->printItem = customPrintItem ? customPrintItem : &defaultPrintBtItem;
    return newBT;
}

/**
 * Compares two values, assuming they are both integers
 * Returns:
 *         -1: if the first value is lesser than the second one
 *          0: if the values are equal
 *          1: if the first value is greater than the second one
 */
int defaultCompare(void *_key, void *data) {
    int *value = data;
    int *key = _key;
    if (*key == *value) return 0;
    return (*key < *value) ? -1 : 1;
}

/**
 * Prints a list item assuming the item is an integer
 */
void defaultPrintBtItem(void *data) {
    if (data) {
        int *value = data;
        printf("%d ", *value);
    }
    return;
}

/**
 * Creates a new mallocated tree node with the provided key
 * Returns:
 *          On succcess: a pointer to the created node
 *          On failure:  a NULL pointer
 */
BTNode *btCreateNode(void *data) {
    if (!data) return NULL;

    BTNode *newNode = malloc(sizeof(BTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * Inserts a new node with the provided key into the tree
 * Returns:
 *          On success: 0
 *          On failure: -1 (the data or the binary tree passed is NULL)
 *                       1 (the inserted key already exists in the tree)
 */
int btInsert(BinaryTree* bt, void *data) {
    if (!bt || !data) return -1;
    BTNode *newNode = btCreateNode(data);
    if (!bt->root) {
        bt->root = newNode;
        return 0;
    } else {
        return _btInsertNode(bt, bt->root, newNode);
    }
}

// TODO: CORRIGIR USANDO A FUNÇÃO DE COMPARE.
int _btInsertNode(BinaryTree *bt, BTNode *root, BTNode *newNode) {
    if (bt->compare(newNode->data, root->data) < 0 && !root->left) {
        root->left = newNode;
        return 0;
    } else if (bt->compare(newNode->data, root->data) > 0 && !root->right) {
        root->right = newNode;
        return 0;
    }
    
    if (bt->compare(newNode->data, root->data) < 0) {
        return _btInsertNode(bt, root->left, newNode);
    } else if (bt->compare(newNode->data, root->data) > 0) {
        return _btInsertNode(bt, root->right, newNode);
    } else {
        return 1;
    }
}

/**
 * Check if the intended node is a leaf (node without children)
 * Returns:
 *          NULL: the node is not a leaf
 *          Pointer to the node: if the node IS a leaf
 */
BTNode * isLeaf(BinaryTree * bt, void *data) {
    BTNode * target = NULL;
    if ((target = btSearchKey(bt, data)) == NULL) {
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
BTNode ** btGetParentChild(BinaryTree *bt, void *data) {
    if (bt->root) {
        if (bt->compare(bt->root->data, data) == 0) {
            return &bt->root;
        } else {
            return btGetParentChildNode(bt, bt->root, data);
        }
    } else {
        return NULL;
    }
}

BTNode ** btGetParentChildNode(BinaryTree *bt, BTNode *node, void *data) {
    if (bt->compare(node->left->data, data) == 0) {
        return &node->left;
    } else if (bt->compare(node->right->data, data) == 0) {
        return &node->right;
    } else if (bt->compare(data, node->data) < 0) {
        return (node->left) ? btGetParentChildNode(bt, node->left, data) : NULL;
    } else if (bt->compare(data, node->data) > 0) {
        return (node->right) ? btGetParentChildNode(bt, node->right, data) : NULL;
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
int btRemoveKey(BinaryTree* bt, void *data) {
    BTNode * target = NULL;
    BTNode ** targetParentChild = NULL;
    int targetIsNotRoot = true;

    // Key does not exist in the tree
    if ((target = btSearchKey(bt, data)) == NULL) {
        return -1;
    }
    
    // targetParentChild is a pointer to the target's parent ->left or ->right depending if the target is a left or right child
    targetIsNotRoot = (targetParentChild = btGetParentChild(bt, data)) != NULL ? true : false;

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
        BTNode * replacement = getLeftmostLeaf(target->right);
        BTNode ** replacementParentChild = btGetParentChild(bt, replacement->data);

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
BTNode * btSearchKey(BinaryTree* bt, void *data) {
    if (!bt->root) {
        return NULL;
    } else {
        return _btSearchKeyNode(bt, bt->root, data);
    }
}

BTNode * _btSearchKeyNode(BinaryTree* bt, BTNode *node, void *data) {
    int compareResult = bt->compare(data, node->data);
    if (compareResult == 0) {
        return node;
    } else if (compareResult < 0) {
        return (node->left) ? _btSearchKeyNode(bt, node->left, data) : NULL;
    } else if (compareResult > 0) {
        return (node->right) ? _btSearchKeyNode(bt, node->right, data) : NULL;
    } else {
        return NULL;
    }
}

/**
 * Searchs the leftmost leaf of the provided node
 * Returns:
 *          Pointer to the leftmost leaf
 */
BTNode * getLeftmostLeaf(BTNode * node) {
    return (!node->left) ? node : getLeftmostLeaf(node->left);
}

/**
 * Searchs the rightmost leaf of the provided node
 * Returns:
 *          Pointer to the rightmost leaf
 */
BTNode * getRightmostLeaf(BTNode * node) {
    return (!node->right) ? node : getRightmostLeaf(node->right);
}

/** 
 * Prints the tree by levels by using 2 queues strategy
 */
void btPrint(BinaryTree *bt) {
    if(!bt) return;

    if (!bt->root) {
        printf("Empty Tree\n");
        return;
    }

    Queue *processing = createQueue(bt->compare, bt->printItem);
    Queue *toProcess = createQueue(bt->compare, bt->printItem);
    BTNode *currentNode;

    queuePut(processing, bt->root);
    while (!queueIsEmpty(processing)) {
        while (!queueIsEmpty(processing)) {
            currentNode = queuePop(processing);
            if (currentNode->left) queuePut(toProcess, currentNode->left);
            if (currentNode->right) queuePut(toProcess, currentNode->right);
            bt->printItem(currentNode->data);
        }
        printf("\n");
        Queue *auxQueue = processing;
        processing = toProcess;
        toProcess = auxQueue;
    }
    return;
}

