GCC = gcc
CFLAGS = -std=c99
INCLUDES = -I .
CC = ${GCC} ${CFLAGS} ${INCLUDES}
OBJS = main.o linkedList.o queue.o stack.o binaryTree.o
# To declare 'all' and 'clean' are not to be confused with filenames (in case there is any file named all or clean)
.PHONY: all clean


all: ${OBJS}
	@echo "Building..."
	${CC} ${OBJS} -o target.out
	
main.o: main.c binaryTree.h
	${CC} -c main.c
	
linkedList.o: linkedList.c linkedList.h
	${CC} -c linkedList.c
	
queue.o: queue.c queue.h
	${CC} -c queue.c
	
stack.o: stack.c stack.h
	${CC} -c stack.c
	
binaryTree.o: binaryTree.c binaryTree.h
	${CC} -c binaryTree.c
	
clean:
	@echo "Cleaning up..."
	-rm -rf *.o
	-rm target.out
