#include "list.h"
#include "minunit.h"
#include "struct-test.h"

int tests_run = 0;

static char *test_list_default_create() {
    List *my_list = createList(NULL, NULL);
    mu_assert("Error: List not created", my_list != NULL);
    return 0;
}

static char *test_list_foo_create() {
    List *my_list = createList(foo_equals, foo_customPrintItem);
    mu_assert("Error: List not created", my_list != NULL);
    return 0;
}

static char *test_list_foo_insert() {
    List *my_list = createList(foo_equals, foo_customPrintItem);

    struct foo *myFoo = malloc(sizeof(struct foo));
    myFoo->key = 'r';
    myFoo->name = "lalala";
    myFoo->age = 32;
    myFoo->uptime = 1000;
    insertAtStart(my_list, (void *) myFoo);
    
    // struct foo *myFoo2 = malloc(sizeof(struct foo));
    // myFoo2->key = 'a';
    // myFoo2->name = "lala lele";
    // myFoo2->age = 33;
    // myFoo2->uptime = 14400;
    // insertAtEnd(my_list, (void *) myFoo2);
    
    // struct foo *myFoo3 = malloc(sizeof(struct foo));
    // myFoo3->key = 'b';
    // myFoo3->name = "lal lala le";
    // myFoo3->age = 34;
    // myFoo3->uptime = 196870;
    // insertAtEnd(my_list, (void *) myFoo3);
    
    char *_key = malloc(sizeof(char));
    *_key = 'r';
    
    printList(my_list);
    
    
    mu_assert("Error: Item not correctly inserted", searchKey(my_list, _key) == true);
    return 0;
}

static char * all_tests() {
     mu_run_test(test_list_default_create);
     mu_run_test(test_list_foo_create);
     mu_run_test(test_list_foo_insert);
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