/* Adam Fischer
 * ajfische
 * 11/29/16
 * LoadWgtGraph.h
 */

#ifndef LoadGraph_h
#define LoadGraph_h
#include <stdio.h>
#include "edgeVec.h"


typedef struct EdgeContents EdgeMake;

//Return first character as an int
int parseN(char line[]);

//Return a new edge
EdgeMake initEdges(char line[]);

//Put new edges into adjInfo
void loadEdges(EdgeVec adjInfo[], EdgeMake z, int directed);

//Prepare weighted graph
int loadWgtGraph(FILE * in, EdgeVec adjInfo[], int directed);

#endif
