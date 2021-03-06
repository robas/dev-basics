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

struct foo *newFoo(char key, char *name, int age, int uptime);

struct bar *newBar(char *key, int id, int age, int uptime);

int foo_equals(void *key, void *data);

int foo_customCompare(void *key, void *data);

void foo_customPrintItem(void *data);

int bar_equals(void *key, void *data);

int bar_customCompare(void *data1, void *data2);

void bar_customPrintItem(void *data);

#endif