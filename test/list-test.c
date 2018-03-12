#include "list.h"
#include "minunit.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int tests_run = 0;

struct foo {
    int key;
    char character;
    int age;
    int uptime;
};

int compare (void *key, void *data) {
    char *val1 = key;
    struct foo *val2 = data;
    
    return *val1 == val2->key;
}

static char *test_list_create() {
    List *my_list = createList(NULL, NULL);
    mu_assert("Error: List not created", my_list != NULL);
    return 0;
}

static char *test_list_insert() {
    List *my_list = createList(NULL, NULL);
    
    struct foo *foo1 = malloc(sizeof(struct foo));
    foo1->key = 1;
    foo1->character = 'r';
    foo1->age = 32;
    foo1->uptime = 100432;
    
    insertAtStart(my_list, foo1);
    int *_key = malloc(sizeof(int));
    *_key = 1;
    
    mu_assert("Error: Item not inserted", searchKey(my_list, _key) == TRUE);
    return 0;
}

static char * all_tests() {
     mu_run_test(test_list_create);
     mu_run_test(test_list_insert);
     return 0;
 }

int main() {
    char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf(ANSI_COLOR_GREEN "ALL TESTS PASSED" ANSI_COLOR_RESET "\n");
     }
     printf("Tests run: %d\n", tests_run);
 
     return result != 0;
}