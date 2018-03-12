# Dev Basics

## Objective
My objective here is to recall some basic college knowledge by writing basic algorithms and data structures in C language.

Data structures:
* Linked List
* Stack
* Queue
* Binary Tree

Algorithms:
* Bubble Sort
* Selection Sort

## Compilation
There is a Makefile, so all you need to do is run:
```
$ make
```
Which generates a target.out file.
It's not working right now, because I'm focusing on the List data structure, so instead:
```
$ make list
```

If your intention is to generate a debuggable output:
```
$ make debug
```
Which generates a debug.out file.

If your intention is to test any of the libs:
```
$ make list-test
```
Which generates a test.out file.