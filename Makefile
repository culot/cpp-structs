CC=	g++
CFLAGS=	-g -Wall -std=c++11
BIN=	test

all:	${BIN}

test:	test.cc splaytree.h
	${CC} ${CFLAGS} -o $@ $^

clean:
	@rm -f ${BIN}
