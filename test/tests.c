#include "list.h"
#include "minunit.h"
#include "struct-test.h"
#include "string.h"
#include "binary-tree.h"
#include "stdio.h"

int tests_run = 0;

static char *test_list_default_create() {
    List *my_list = createList(NULL, NULL);
    mu_assert("Error creating list with default functions", my_list != NULL);
    return 0;
}

static char *test_list_foo_create_list() {
    List *my_list = createList(foo_equals, foo_customPrintItem);
    mu_assert("Error creating list with custom foo functions", my_list != NULL);
    return 0;
}

static char *test_list_bar_create_list() {
    List *my_list = createList(bar_equals, bar_customPrintItem);
    mu_assert("Error creating list with custom bar functions", my_list != NULL);
    return 0;
}

static char *test_list_foo_create_node() {
    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    mu_assert("Error creating Node with foo struct", createNode(myFoo) != NULL);
    return 0;
}

static char *test_list_bar_create_node() {
    struct bar *myBar = newBar("abc", 1, 32, 1000);
    mu_assert("Error creating Node with bar struct", createNode(myBar) != NULL);
    return 0;
}

static char *test_list_foo_insertAtStart1() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtStart(my_list, (void *) myFoo);

    char *_key = malloc(sizeof(char));
    *_key = 'a';
    
    mu_assert("Error inserting item at the start of an empty list", searchKey(my_list, _key) == 1);
    return 0;
}

static char *test_list_bar_insertAtStart1() {
    List *my_list = createList(bar_equals, bar_customPrintItem);

    struct bar *myBar = newBar("abc", 1, 32, 1000);
    insertAtStart(my_list, (void *) myBar);

    char *_key = "abc";
    
    mu_assert("Error inserting bar item at the start of an empty list", searchKey(my_list, _key) == 1);
    return 0;
}

static char *test_list_foo_insertAtStart2() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtStart(my_list, (void *) myFoo);
    myFoo = newFoo('b', "Bob", 54, 143145);
    insertAtStart(my_list, (void *) myFoo);

    char *_key = malloc(sizeof(char));
    *_key = 'b';
    mu_assert("Error inserting item at the start of a non-empty list", searchKey(my_list, _key) == 1);
    return 0;
}

static char *test_list_bar_insertAtStart2() {
    List *my_list = createList(bar_equals, bar_customPrintItem);

    struct bar *myBar = newBar("abc", 1, 32, 1000);
    insertAtStart(my_list, (void *) myBar);
    myBar = newBar("bcd", 2, 54, 431231);
    insertAtStart(my_list, (void *) myBar);
    
    mu_assert("Error inserting bar item at the start of a non-empty list", searchKey(my_list, "bcd") == 1);
    return 0;
}

static char *test_list_foo_insertAtEnd1() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtEnd(my_list, (void *) myFoo);

    char *_key = malloc(sizeof(char));
    *_key = 'a';
    
    mu_assert("Error inserting item at the end of an empty list", searchKey(my_list, _key) == 1);
    return 0;
}

static char *test_list_foo_insertAtEnd2() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtEnd(my_list, (void *) myFoo);
    myFoo = newFoo('b', "Bob", 54, 143145);
    insertAtEnd(my_list, (void *) myFoo);

    char *_key = malloc(sizeof(char));
    *_key = 'b';
    mu_assert("Error inserting item at the end of a non-empty list", searchKey(my_list, _key) == 2);
    return 0;
}

static char *test_list_Length1() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    mu_assert("Error getting list length in an empty list", listLength(my_list) == 0);
    return 0;
}

static char *test_list_Length2() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtEnd(my_list, (void *) myFoo);
    myFoo = newFoo('b', "Bob", 54, 143145);
    insertAtEnd(my_list, (void *) myFoo);

    mu_assert("Error getting list length in a non-empty list", listLength(my_list) == 2);
    return 0;
}

static char *test_list_foo_getAtIndex1() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    mu_assert("Error getting item at index 1 in an empty list", getAtIndex(my_list, 1) == NULL);
    return 0;
}

static char *test_list_foo_getAtIndex2() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtEnd(my_list, (void *) myFoo);
    myFoo = newFoo('b', "Bob", 54, 143145);
    insertAtEnd(my_list, (void *) myFoo);

    struct foo *myFooSearch = getAtIndex(my_list, 1);
    
    mu_assert("Error getting item at index 1 in a non-empty list",  myFooSearch->age == 32);
    return 0;
}

static char *test_list_foo_getAtIndex3() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtEnd(my_list, (void *) myFoo);
    myFoo = newFoo('b', "Bob", 54, 143145);
    insertAtEnd(my_list, (void *) myFoo);

    struct foo *myFooSearch = getAtIndex(my_list, 2);
    
    mu_assert("Error getting item at last index in a non-empty list",  myFooSearch->age == 54);
    return 0;
}

static char *test_list_foo_insertAtIndex1() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtIndex(my_list, (void *) myFoo, 1);

    struct foo *myFooSearch = getAtIndex(my_list, 1);
    
    mu_assert("Error inserting item in the first index in an empty list",  strcmp(myFooSearch->name, "Aron") == 0);
    return 0;
}

static char *test_list_foo_insertAtIndex2() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtIndex(my_list, (void *) myFoo, 1);
    myFoo = newFoo('b', "Bob", 54, 143145);
    insertAtIndex(my_list, (void *) myFoo, 1);
    
    
    struct foo *myFooSearch = getAtIndex(my_list, 1);
    
    mu_assert("Error inserting item in the first index in a non-empty list",  myFooSearch->age == 54);
    return 0;
}

static char *test_list_foo_insertAtIndex3() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

   struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtIndex(my_list, (void *) myFoo, 1);
    myFoo = newFoo('c', "Cody", 20, 9857423);
    insertAtIndex(my_list, (void *) myFoo, 2);
    myFoo = newFoo('b', "Bob", 54, 143145);
    insertAtIndex(my_list, (void *) myFoo, 2);

    struct foo *myFooSearch = getAtIndex(my_list, 2);
    
    mu_assert("Error inserting item in the second index in a non-empty list",  myFooSearch->age == 54);
    return 0;
}

static char *test_list_foo_insertAtIndex4() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

   struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtIndex(my_list, (void *) myFoo, 1);
    myFoo = newFoo('c', "Cody", 20, 9857423);
    insertAtIndex(my_list, (void *) myFoo, 2);
    myFoo = newFoo('b', "Bob", 54, 143145);
    insertAtIndex(my_list, (void *) myFoo, 2);
    myFoo = newFoo('d', "Danny", 30, 66532);
    insertAtIndex(my_list, (void *) myFoo, 4);

    struct foo *myFooSearch = getAtIndex(my_list, 4);
    
    mu_assert("Error inserting item in the last index in a non-empty list",  myFooSearch->age == 30);
    return 0;
}

static char *test_list_foo_insertAtIndex5() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    insertAtIndex(my_list, (void *) myFoo, 1);
    myFoo = newFoo('c', "Cody", 20, 9857423);
    insertAtIndex(my_list, (void *) myFoo, 2);
    myFoo = newFoo('b', "Bob", 54, 143145);
    insertAtIndex(my_list, (void *) myFoo, 2);
    myFoo = newFoo('d', "Danny", 30, 66532);
    insertAtIndex(my_list, (void *) myFoo, 4);

    struct foo *myFooSearch = getAtIndex(my_list, 5);
    
    mu_assert("Error inserting item in an out-of-bounds index in a non-empty list",  myFooSearch == NULL);
    return 0;
}

static char *test_binaryTree_default_create() {
    BinaryTree *bt = btCreateBinaryTree(NULL, NULL);
    mu_assert("Error creating binary tree with default functions", bt != NULL);
    return 0;
}

static char *test_binaryTree_foo_create_binaryTree() {
    BinaryTree *bt = btCreateBinaryTree(foo_customCompare, foo_customPrintItem);
    mu_assert("Error creating binary tree with custom foo functions", bt != NULL);
    return 0;
}

static char *test_binaryTree_foo_create_node() {
    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    mu_assert("Error creating binary tree node with foo struct", btCreateNode(myFoo) != NULL);
    return 0;
}

static char *test_binaryTree_foo_insert1() {
    BinaryTree *bt = btCreateBinaryTree(foo_customCompare, foo_customPrintItem);
    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    
    mu_assert("Error inserting foo item in an empty binary tree", btInsert(bt, (void *) myFoo) == 0);
    return 0;
}

static char *test_binaryTree_bar_insert1() {
    BinaryTree *bt = btCreateBinaryTree(foo_customCompare, foo_customPrintItem);
    struct bar *myBar = newBar("abc", 1, 32, 1000);
    
    mu_assert("Error inserting bar item in an empty binary tree", btInsert(bt, (void *) myBar) == 0);
    return 0;
}

static char *test_binaryTree_foo_insert2() {
    BinaryTree *bt = btCreateBinaryTree(foo_customCompare, foo_customPrintItem);
    struct foo *myFoo = newFoo('a', "Aron", 32, 1000);
    myFoo = newFoo('c', "Cody", 20, 9857423);
    
    mu_assert("Error inserting foo item in a non-empty binary tree", btInsert(bt, (void *) myFoo) == 0);
    return 0;
}

static char *test_binaryTree_bar_insert2() {
    BinaryTree *bt = btCreateBinaryTree(bar_customCompare, bar_customPrintItem);
    struct bar *myBar = newBar("abc", 1, 32, 1000);
    btInsert(bt, (void *) myBar);
    struct bar *mySearch = newBar("abc", 0, 0, 0);
    mu_assert("Error inserting bar item in a non-empty binary tree", btSearchKey(bt, mySearch) != NULL);
    return 0;
}

static char *test_binaryTree_bar_remove1() {
    BinaryTree *bt = btCreateBinaryTree(bar_customCompare, bar_customPrintItem);
    struct bar *mySearch = newBar("abc", 1, 32, 1000);
    
    mu_assert("Error removing bar item from an empty binary tree", btRemoveKey(bt, mySearch) == -1);
    return 0;
}

static char *test_binaryTree_bar_remove2() {
    BinaryTree *bt = btCreateBinaryTree(bar_customCompare, bar_customPrintItem);
    struct bar *myBar = newBar("abc", 1, 32, 1000);
    btInsert(bt, (void *) myBar);
    struct bar *mySearch = newBar("abc", 0, 0, 0);
    mu_assert("Error removing bar item from a non-empty binary tree", btRemoveKey(bt, mySearch) == 0);
    return 0;
}

static char * all_tests() {
     mu_run_test(test_list_default_create);
     mu_run_test(test_list_foo_create_list);
     mu_run_test(test_list_bar_create_list);
     mu_run_test(test_list_foo_create_node);
     mu_run_test(test_list_bar_create_node);
     mu_run_test(test_list_foo_insertAtStart1);
     mu_run_test(test_list_bar_insertAtStart1);
     mu_run_test(test_list_foo_insertAtStart2);
     mu_run_test(test_list_bar_insertAtStart2);
     mu_run_test(test_list_foo_insertAtEnd1);
     mu_run_test(test_list_foo_insertAtEnd2);
     mu_run_test(test_list_Length1);
     mu_run_test(test_list_Length2);
     mu_run_test(test_list_foo_getAtIndex1);
     mu_run_test(test_list_foo_getAtIndex2);
     mu_run_test(test_list_foo_getAtIndex3);
     mu_run_test(test_list_foo_insertAtIndex1);
     mu_run_test(test_list_foo_insertAtIndex2);
     mu_run_test(test_list_foo_insertAtIndex3);
     mu_run_test(test_list_foo_insertAtIndex4);
     mu_run_test(test_list_foo_insertAtIndex5);
     mu_run_test(test_binaryTree_default_create);
     mu_run_test(test_binaryTree_foo_create_binaryTree);
     mu_run_test(test_binaryTree_foo_create_node);
     mu_run_test(test_binaryTree_foo_insert1);
     mu_run_test(test_binaryTree_bar_insert1);
     mu_run_test(test_binaryTree_foo_insert2);
     mu_run_test(test_binaryTree_bar_insert2);
     mu_run_test(test_binaryTree_bar_remove1);
     mu_run_test(test_binaryTree_bar_remove2);


     return 0;
 }

int main() {
    char *result = all_tests();
     if (result != 0) {
         print_err(result);
     }
     else {
         print_ok("ALL TESTS PASSED");
     }
     printf("Tests run: %d\n", tests_run);
 
     return result != 0;
}