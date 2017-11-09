/* Adam Fischer
 * ajfische
 * 11/29/16
 * minPQ.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "minPQ.h"

struct MinPQNode{
    int numVertices;
    int numPQ;
    int minVertex;
    double oo;
    int *status;
    int *parent;
    double *fringeWgt;
};

//Once pq is empty it will return 0
int isEmptyPQ(MinPQ pq) {
    return (pq->numPQ);
}

//Load minimum vertices
int getMin(MinPQ pq) {
    if (pq->minVertex == -1) {
        double minWgt = pq->oo;
        for (int v = 1; v <= pq->numVertices; v++) {
            if (pq->status[v] == FRINGE) {
                //Check if current fringeWgt is smaller than minWgt
                if (pq->fringeWgt[v] < minWgt) {
                    //Change the minVertex to current vertex
                    pq->minVertex = v;
                    //Change minWgt to current vertex wgt
                    minWgt = pq->fringeWgt[v];
                }
            }
        }
    }
    return pq->minVertex;
}


int getStatus(MinPQ pq, int id) {
    return pq->status[id];
}


int getParent(MinPQ pq, int id) {
    return pq->parent[id];
}


double getPriority(MinPQ pq, int id) {
    return pq->fringeWgt[id];
}

//Remove seen vertex frmo list
void delMin(MinPQ pq) {
    int oldMin = getMin(pq);
    
    pq->status[oldMin] = INTREE;
    pq->minVertex = -1;
    pq->numPQ--;
}

//Insert seen vertex into priority queue
void insertPQ(MinPQ pq, int id, double priority, int par) {
    //id = current vertice
    pq->parent[id] = par;
    pq->fringeWgt[id]= priority;
    pq->status[id] = FRINGE;
    pq->minVertex = -1;
    pq->numPQ++;
}


void decreaseKey(MinPQ pq, int id, double priority, int par) {
    pq->parent[id] = par;
    pq->fringeWgt[id] = priority;
    pq->minVertex = -1;
}

//Initialize priority queue
MinPQ createPQ(int n, int status[], double priority[], int parent[]) {
    MinPQ pq = calloc(n+1, sizeof(MinPQ));
    pq->parent = parent;
    pq->fringeWgt = priority;
    pq->status = status;
    //Initialize all vertices to unseen
    for (int i = 1; i <= n; i++){
        pq->status[i] = UNSEEN;
    }
    pq->numVertices = n;
    pq->numPQ = 0;
    //Smallest vertex you can travel to next
    pq->minVertex = -1;
    pq->oo = ULONG_MAX;
    return pq;
}

