#include <limits.h>
#include "binaryTree.h"
#include "queue.h"

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
 * Returns the newly created node
 */
BTNode *btCreateNode(void *data) {
    BTNode *newNode = malloc(sizeof(BTNode));
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
int btInsert(BinaryTree* bt, void *data) {
    BTNode *newNode = btCreateNode(data);
    if (!bt->root) {
        bt->root = newNode;
        return 0;
    } else {
        return btInsertNode(bt->root, newNode);
    }
}

int btInsertNode(BTNode *root, BTNode *newNode) {
    if (newNode->data < root->data && !root->left) {
        root->left = newNode;
        return 0;
    } else if (newNode->data > root->data && !root->right) {
        root->right = newNode;
        return 0;
    }
    
    if (newNode->data < root->data) {
        return btInsertNode(root->left, newNode);
    } else if (newNode->data > root->data) {
        return btInsertNode(root->right, newNode);
    } else {
        return -1;
    }
}

/**
 * Check if the intended node is a leaf (node without children)
 * Returns:
 *          NULL: the node is not a leaf
 *          Pointer to the node: if the node IS a leaf
 */
BTNode * isLeaf(BinaryTree * bt, void *key) {
    BTNode * target = NULL;
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
BTNode ** btGetParentChild(BinaryTree *bt, void *key) {
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

BTNode ** btGetParentChildNode(BTNode *node, void *key) {
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
int btRemoveKey(BinaryTree* bt, void *key) {
    BTNode * target = NULL;
    BTNode ** targetParentChild = NULL;
    int targetIsNotRoot = true;

    // Key does not exist in the tree
    if ((target = btSearchKey(bt, key)) == NULL) {
        return -1;
    }
    
    // targetParentChild is a pointer to the target's parent ->left or ->right depending if the target is a left or right child
    targetIsNotRoot = (targetParentChild = btGetParentChild(bt, key)) != NULL ? true : false;

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
BTNode * btSearchKey(BinaryTree* bt, void *key) {
    if (!bt->root) {
        return NULL;
    } else {
        return btSearchKeyNode(bt->root, key);
    }
}

BTNode * btSearchKeyNode(BTNode *node, void *key) {
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

/** TODO
 * Prints the tree by levels
 */
// void btPrint(BinaryTree *bt) {
//     Queue *nodes = createQueue(bt->compare, bt->printItem);
//     void *currentValue;
//     BTNode *node;

//     if (!bt->root) {
//         printf("Empty Tree\n");
//         return;
//     }

//     node = bt->root;
//     queuePut(nodes, node->data);
//     queuePut(nodes, INT_MIN);
    
//     while ((currentValue = queuePop(nodes)) != INT_MAX) {        
//         if (currentValue == INT_MIN) {
//             printf("\n");
//             if (queueIsEmpty(nodes)) {
//                 queuePut(nodes, currentValue);
//             }
//         } else {
//             printf("%d ", currentValue);
//             node = btSearchKey(bt, currentValue);
//             if (node->left) {queuePut(nodes, node->left->data);}
//             if (node->right) {queuePut(nodes, node->right->data);}
//         }
//     }
//     return;
// }

