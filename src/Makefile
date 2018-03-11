GCC = gcc
CFLAGS = -std=c99
DEBUG_FLAGS = -g
INCLUDES = -I .
CC = ${GCC} ${CFLAGS} ${INCLUDES}
DEBUG_CC = ${GCC} ${DEBUG_FLAGS} ${CFLAGS} ${INCLUDES}
OBJS = main.o list.o queue.o stack.o binaryTree.o
EXE = target.out
DBG = debug.out
# To declare 'all' and 'clean' are not to be confused with filenames (in case there is any file named 'all' or 'clean')
.PHONY: all clean


all: ${OBJS}
	@echo "Building..."
	${CC} ${OBJS} -o ${EXE}

debug: ${OBJS}
	@echo "Building with debugging symbols"
	${DEBUG_CC} ${OBJS} -o ${DBG}

main.o: main.c
	${CC} -c main.c
	
list.o: list.c list.h
	${CC} -c list.c
	
queue.o: queue.c queue.h
	${CC} -c queue.c
	
stack.o: stack.c stack.h
	${CC} -c stack.c
	
binaryTree.o: binaryTree.c binaryTree.h
	${CC} -c binaryTree.c
	
clean:
	@echo "Cleaning up..."
	-rm -rf *.o
	-rm target.out debug.out

list: main.o list.o
	@echo "Building List..."
	${CC} main.o list.o -o ${EXE}