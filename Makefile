GCC = gcc
CFLAGS = -std=c99
DEBUG_FLAGS = -g
INCLUDES = -I ./src -I ./test
CC = ${GCC} ${CFLAGS} ${INCLUDES}
DEBUG_CC = ${GCC} ${DEBUG_FLAGS} ${CFLAGS} ${INCLUDES}
OBJS = main.o list.o queue.o stack.o binaryTree.o
EXE = target.out
DBG = debug.out
TEST_OUTPUT = test.out
SRC_DIR = ./src
TEST_DIR = ./test
# To declare 'all' and 'clean' are not to be confused with filenames (in case there is any file named 'all' or 'clean')
.PHONY: all clean


all: ${OBJS}
	@echo "Building..."
	${CC} ${OBJS} -o ${EXE}

debug: ${OBJS}
	@echo "Building with debugging symbols"
	${DEBUG_CC} ${OBJS} -o ${DBG}

main.o: ${SRC_DIR}/main.c
	${CC} -c ${SRC_DIR}/main.c
	
list.o: ${SRC_DIR}/list.c ${SRC_DIR}/list.h
	${CC} -c ${SRC_DIR}/list.c

list-test.o: ${TEST_DIR}/list-test.c
	${CC} -c ${TEST_DIR}/list-test.c

queue.o: ${SRC_DIR}/queue.c ${SRC_DIR}/queue.h
	${CC} -c ${SRC_DIR}/queue.c
	
stack.o: ${SRC_DIR}/stack.c ${SRC_DIR}/stack.h
	${CC} -c ${SRC_DIR}/stack.c
	
binaryTree.o: ${SRC_DIR}/binaryTree.c ${SRC_DIR}/binaryTree.h
	${CC} -c ${SRC_DIR}/binaryTree.c
	
clean:
	@echo "Cleaning up..."
	-rm -f *.o
	-rm -f *.out

list: main.o list.o
	@echo "Building List..."
	${CC} main.o list.o -o ${EXE}

queue: main.o queue.o list.o
	@echo "Building Queue..."
	${CC} main.o queue.o list.o -o ${EXE}

stack: main.o stack.o list.o
	@echo "Building Stack..."
	${CC} main.o stack.o list.o -o ${EXE}

list-test: list-test.o list.o
	@echo "Building Test..."
	${CC} list-test.o list.o -o ${TEST_OUTPUT}