/* Adam Fischer
 * ajfische
 * 11/29/16
 * edgeVec.c
 * Contains methods to find minimum connections between vertices
 */ 


#ifndef C101MinPQ
#define C101MinPQ

/* Multiple typedefs for the same type are an error in C. */
typedef struct MinPQNode * MinPQ;

#define UNSEEN ('u')
#define FRINGE ('f')
#define INTREE ('t')

/* ***************** Access functions */

/** isEmpty
	pq must not be NULL.
*/
int isEmptyPQ(MinPQ pq);

/** getMin
 	pq must not be NULL.
*/
int getMin(MinPQ pq);

/** getStatus
	pq must not be NULL, v must be in pq.
*/
int getStatus(MinPQ pq, int id);

/** getParent
	pq must not be NULL, v must be in pq.
*/
int getParent(MinPQ pq, int id);

/** getPriority
	pq must not be NULL, v must be in pq.
*/
double getPriority(MinPQ pq, int id);


/* ***************** Manipulation procedures */

/** delMin
	pq must not be NULL. 
*/
void delMin(MinPQ pq);

/** insertPQ
	pq must not be NULL, v must be in pq.
*/
void insertPQ(MinPQ pq, int id, double priority, int par);

/** decreaseKey
	pq must not be NULL, v must be in pq.
*/
void decreaseKey(MinPQ pq, int id, double priority, int par);


/* ***************** Constructors */

/** createPQ
	status, parent, and fringeWgt must already be allocated.
*/
MinPQ createPQ(int n, int status[], double priority[], int parent[]);


#endif
