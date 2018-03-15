#ifndef STRUCT_TEST_H
#define STRUCT_TEST_H

struct foo {
    char key;
    char *name;
    int age;
    int uptime;
};

struct bar {
    char *key;
    int id;
    int age;
    int uptime;
};

int foo_equals (void *key, void *data);

int foo_compare (void *key, void *data);

void foo_customPrintItem(void *data);

int bar_equals (void *key, void *data);

int bar_compare (void *key, void *data);

void bar_customPrintItem(void *data);

#endif