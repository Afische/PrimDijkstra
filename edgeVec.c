/* Adam Fischer
 * ajfische
 * 11/29/16
 * edgeVec.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "edgeVec.h"

struct EdgeVecNode {
	  EdgeInfo * data;
    int sz;
    int capacity;
};

//Return edge data at top of stack
EdgeInfo edgeTop(EdgeVec myVec){
  	return myVec->data[myVec->sz];
}

//Find edge info at indicated position in stack
EdgeInfo edgeData(EdgeVec myVec, int i){
    return myVec->data[i];
}

//Return size of edge stack
int edgeSize(EdgeVec myVec){
  	return myVec->sz;
}

//Return edge stack capacity
int edgeCapacity(EdgeVec myVec){
  	return myVec->capacity;
}

//Initialize EdgeVec
EdgeVec edgeMakeEmptyVec(void){
  	EdgeVec myVec = calloc(1, sizeof(EdgeVec));
    myVec->capacity = 4;
  	myVec->data = calloc(4, sizeof(EdgeInfo));
  	myVec->sz = 0;

  	return myVec;
}

//Add EdgeInfo to EdgeVec
void edgeVecPush(EdgeVec myVec, EdgeInfo newE){
	if (myVec->sz < myVec->capacity){
    myVec->data[myVec->sz] = newE;
    myVec->sz++;
  }
  //Make more room if not big enough
  else{
    myVec->capacity = 2* myVec->capacity;
    myVec->data = realloc(myVec->data, sizeof(EdgeInfo) * myVec->capacity);
    myVec->data[myVec->sz] = newE;
    myVec->sz++;
  }
}

//Decrease size of EdgeVec
void edgeVecPop(EdgeVec myVec){
    myVec->sz--;
  }