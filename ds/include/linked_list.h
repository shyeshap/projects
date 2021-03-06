/*********************************/
/*    Data Structures            */
/*    Single Linked List         */       
/*    Author :Guy Cohen Zedek    */
/*    Reviewed By:               */
/*    Date:    2/12/2019         */
/*                               */
/*********************************/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stddef.h>

typedef struct Node
{
    void *data;
    struct Node *next;
}node_t;

typedef int (*action_func_ptr_t)(void *node, void *additional);
typedef int (*match_func_ptr_t)(void *node, void *additional);

/* Creates a new node */
/* WARNING: Doesnt get NULL pointer */
node_t *SLLCreateNode(node_t *next, const void *data);

/* Destroys the data structure */
/* WARNING: Doesnt get NULL pointer */
void SLLDestroy(node_t *node);

/* Inserts a new node before the node sent to the function */
/* WARNING: Doesnt get NULL pointer */
int SLLInsert(node_t *node, node_t *next_node);

/* Inserts a new node after the node sent to the function */
/* WARNING: Doesnt get NULL pointer */
int SLLInsertAfter(node_t *new_node, node_t *previous_node);

/* Removes the node before the node sent to the function */
/* WARNING: Can't remove last  node */
/* WARNING: Doesnt get NULL pointer */
void SLLRemove(node_t *node);

/* Removes the node after the node sent to the function */
/* WARNING: Doesnt get NULL pointer */
void SLLRemoveAfter(node_t *node);

/* Returns a node according to a condition specified by the user */
/* WARNING: Doesnt get NULL pointer */
node_t *SLLGetNode(const node_t *head, match_func_ptr_t func_ptr, void *additional);

/* Performs a generic operation on all nodes in the data structure */
/* WARNING: Doesnt get NULL pointer */
int SLLForEach(node_t *head, action_func_ptr_t func_ptr, void *additional);

/* Returns the number of nodes */
/* WARNING: Doesnt get NULL pointer */
size_t SLLSize(const node_t *head);

/* Flips the direciton of pointing from last to first */
/* WARNING: Doesnt get NULL pointer */
node_t *SLLFlip(node_t *head);

/* Checks if a loop occurs in the structure */
/* Returns 0 - loop occurs, 1 - loop doesnt occur */
/* WARNING: Doesnt get NULL pointer */
int SLLHasLoop(const node_t *head);

/* Returns a pointer to the node the create an  */
/* WARNING: Doesnt get NULL pointer */
node_t *SLLFindIntersection(const node_t *head1, const node_t *head2);

node_t *SLLFlipRec(node_t *head);
#endif
