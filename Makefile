GCC = gcc
CFLAGS = -std=c99
DEBUG_FLAGS = -g
INCLUDES = -I ./src -I ./test
CC = ${GCC} ${CFLAGS} ${INCLUDES}
DEBUG_CC = ${GCC} ${DEBUG_FLAGS} ${CFLAGS} ${INCLUDES}
OBJS = list.o queue.o stack.o binary-tree.o sample.o
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
	-rm -f *.o
debug: ${OBJS}
	@echo "Building with debugging symbols"
	${DEBUG_CC} ${OBJS} -o ${DBG}

sample.o: ${SRC_DIR}/sample.c
	${CC} -c ${SRC_DIR}/sample.c

list.o: ${SRC_DIR}/list.c ${SRC_DIR}/list.h
	${CC} -c ${SRC_DIR}/list.c

queue.o: ${SRC_DIR}/queue.c ${SRC_DIR}/queue.h
	${CC} -c ${SRC_DIR}/queue.c
	
stack.o: ${SRC_DIR}/stack.c ${SRC_DIR}/stack.h
	${CC} -c ${SRC_DIR}/stack.c

binary-tree.o: ${SRC_DIR}/binary-tree.c ${SRC_DIR}/binary-tree.h
	${CC} -c ${SRC_DIR}/binary-tree.c

struct-test.o: ${TEST_DIR}/struct-test.c ${TEST_DIR}/struct-test.h
	${CC} -c ${TEST_DIR}/struct-test.c

tests.o: ${TEST_DIR}/tests.c
	${CC} -c ${TEST_DIR}/tests.c

clean:
	@echo "Cleaning up..."
	-rm -f *.o
	-rm -f *.out

test: tests.o struct-test.o list.o binary-tree.o queue.o
	@echo "Building Tests..."
	${CC} struct-test.o tests.o list.o queue.o binary-tree.o -o ${TEST_OUTPUT}