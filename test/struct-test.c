#include "struct-test.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct foo *newFoo(char key, char *name, int age, int uptime) {
    struct foo *myFoo = malloc(sizeof(struct foo));
    myFoo->key = key;
    myFoo->name = name;
    myFoo->age = age;
    myFoo->uptime = uptime;
    return myFoo;
}

struct bar *newBar(char *key, int id, int age, int uptime) {
    struct bar *myBar = malloc(sizeof(struct bar));
    myBar->key = key;
    myBar->id = id;
    myBar->age = age;
    myBar->uptime = uptime;
    return myBar;
}

int foo_equals(void *_key, void *data) {
    char *key = _key;
    struct foo *myFoo = data;
    
    return *key == myFoo->key;
}


void foo_customPrintItem(void *data) {
    if (data) {
        struct foo *myFoo = data;
        printf("%c ", myFoo->key);
        printf("%s ", myFoo->name);
        printf("%d ", myFoo->age);
        printf("%d ", myFoo->uptime);
    }
    return;
}

int foo_customCompare(void *data1, void *data2) {
    struct foo *myFoo1 = data1;
    struct foo *myFoo2 = data2;
    if (myFoo1->key == myFoo2->key) return 0;
    return (myFoo1->key < myFoo2->key) ? -1 : 1;
}

int bar_equals(void *_key, void *data) {
    char *key = _key;
    struct bar *myBar = data;
    
    return strcmp(key, myBar->key) == 0;
}


void bar_customPrintItem(void *data) {
    if (data) {
        struct bar *myBar = data;
        printf("%s ", myBar->key);
        // printf("%d ", myBar->id);
        // printf("%d ", myBar->age);
        // printf("%d ", myBar->uptime);
    }
    return;
}

int bar_customCompare(void *data1, void *data2) {
    struct bar *myBar1 = (struct bar *) data1;
    struct bar *myBar2 = (struct bar *) data2;
    return strcmp(myBar1->key, myBar2->key);
}
