#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include <stddef.h> /* size_t */

typedef struct PQueue pq_t;
typedef int (*match_func)(void*, void*);
typedef int (*compare_func_ptr)(void *data1, void *data2, void *param);

/**********************************************/
/* Returns pointer to the PQ  data structure  */
/* complexity of malloc                       */
/**********************************************/
pq_t *PQCreate(compare_func_ptr cmp_ptr, void *param);

/*************************************************/
/* Destroys the PQ  datastructure and frees it   */
/* from memory                                   */
/* complexity of free                            */
/*************************************************/
void PQDestroy(pq_t *pq);

/*****************************************/
/* Gets the PQ structure and pops the    */
/* highest priority element              */
/* Returns the data removed              */
/* complexity O(1)                       */
/*****************************************/
void *PQDequeue(pq_t *pq);

/*****************************************/
/* Gets the PQ structure and             */
/* Returns 0 for success, 1 for faileure */
/* complexity O(1)                       */
/*****************************************/
int PQEnqueue(pq_t *pq, void *data);

/*********************************************************************/
/* gets the data structure and returns the data wof the highest      */
/* priority element                                                  */
/* complexity O(1)                                                   */
/*********************************************************************/    
void *PQPeek(const pq_t *pq);

/*********************************************************************/    
/* gets the data structure and returns the number of elements  































































































































































































































































































































































































































































































 */                                           
/* complexity O(n)                                                   */
/*********************************************************************/    
size_t PQSize(const pq_t *pq);

/***********************************************/
/* Checks whether the data structure is empty  */
/* returns 1 if its empty or 0 if not empty    */
/* complexity O(1)                             */
/***********************************************/
int PQIsEmpty(const pq_t *pq);

/***********************************************/
/* gets the data structure and removes its     */
/* elements                                    */
/* complexity O(n)                             */
/***********************************************/
void PQClear(pq_t *pq);

/************************************************/
/* gets the data structure and a data to search,*/
/* once the element is found, its removed       */
/* if fail return NULL							*/
/* complexity O(1)                              */
/************************************************/
void *PQErase(pq_t *pq, match_func m_ptr, void *param);

#endif
