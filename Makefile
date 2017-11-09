#Adam Fischer
#ajfische
#11/29/16
#Makefile

CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

greedy04: greedy04.o minPQ.o edgeVec.o LoadWgtGraph.o LoadWgtGraph.o
	${CC} -o greedy04 greedy04.o minPQ.o edgeVec.o LoadWgtGraph.o 

minPQ.o: minPQ.c minPQ.h
	${CC} -c ${CFLAGS} minPQ.c

edgeVec.o: edgeVec.c edgeVec.h
	${CC} -c ${CFLAGS} edgeVec.c

LoadWgtGraph.o: LoadWgtGraph.c LoadWgtGraph.h
	${CC} -c ${CFLAGS} LoadWgtGraph.c

greedy04.o: greedy04.c
	${CC} -c ${CFLAGS} greedy04.c
