# Dev Basics

## Objective
The purpose of this project is to recall some basic CS knowledge by developing some data structures and algorithms in C language.

## Status
By now we have the following data structures and algorithms implemented as libraries:

### Data structures:
* Linked List
* Stack
* Queue
* Binary Tree

The interesting point about the data structures is that they can hold whatever data type or struct you like, having only to provide a comparison function and a print function when you create the list/stack/queue/binary tree.

### Algorithms:
* Bubble Sort
* Selection Sort

The algorithms are a work in progress... not even close to the work already done on the data structures.

## Compilation
There is a Makefile, so all you need to do is run:
```
$ make
```
Which generates a target.out file with some sample usages.

If your intention is to generate a debuggable output:
```
$ make debug
```
Which generates a debug.out file.

If you are working with the code and want to run the libraries tests:
```
$ make test
```
Which generates a test.out file.