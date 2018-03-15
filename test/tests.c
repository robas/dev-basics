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

    struct foo *myFoo = malloc(sizeof(myFoo));
    myFoo->key = 'r';
    myFoo->name = "lalala";
    myFoo->age = 32;
    myFoo->uptime = 1000;
    
    insertAtStart(my_list, (void *) myFoo);
    char *_key = malloc(sizeof(char));
    *_key = 'r';
    
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