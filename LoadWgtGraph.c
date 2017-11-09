/* Adam Fischer
 * ajfische
 * 11/29/16
 * LoadWgtGraph.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "edgeVec.h"
#include "LoadWgtGraph.h"
#include "minPQ.h"

typedef char * word;

struct EdgeContents{
    int from;
    int to;
    double wgt;
};

//Returns number on the line
int parseN(char line[]){
    int total;
    word tmp = strdup(line);
    word x = strtok(tmp, "\t\n");

    total = atoi(x);
    return total;
}

// Separate line arguments and put into Edge variable containing from and to
EdgeMake initEdges(char line[]){
    EdgeMake newEdge;
    sscanf(line, "%d %d %lf", &newEdge.from, &newEdge.to, &newEdge.wgt);
    return newEdge;
}

//Put edges into adjInfo
void loadEdges(EdgeVec adjInfo[], EdgeMake z, int directed){
    
    //make directed
    if(directed == 1){
        EdgeInfo newInfo; 
        newInfo.wgt = z.wgt;
        newInfo.to = z.to;
        EdgeVec newVec = adjInfo[z.from];
        edgeVecPush(newVec, newInfo);
    }
    
    //make undirected
    else if(directed == 0){
        EdgeInfo newInfo; 
        newInfo.wgt = z.wgt;
        newInfo.to = z.to;
        EdgeVec newVec = adjInfo[z.from];
        edgeVecPush(newVec, newInfo);
    
        EdgeInfo newInfo2;
        newInfo2.wgt = z.wgt;
        newInfo2.to = z.from;
        EdgeVec newVec2 = adjInfo[z.to];
        edgeVecPush(newVec2, newInfo2);
    }

}

//Prepare Weighted Graph
int loadWgtGraph(FILE * in, EdgeVec adjInfo[], int directed){
    int m = 0;
    char line[1024];
    while(fgets(line, 1024, in) != NULL){
        //Separate to, from and weight on the line
        EdgeMake z = initEdges(line);
        //Assign edgeVecs to array adjinfo
        loadEdges(adjInfo, z, directed);
        m++;
    }
    return m;
}