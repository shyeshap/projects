/*********************************/
/*    Data Structures            */
/*    Stack                      */       
/*    Author : Shye Shapira      */
/*    Reviewed By: Itay          */
/*    Date:     /11/2019         */
/*                               */
/*********************************/

#include <stdio.h> /* typedef */
#include <stdlib.h> /* malloc */
#include <string.h> /* memcpy */
#include <assert.h> /* assert */

#include "stack.h" /* stack ds */

struct Stack
{
	void *start;
	void *current;
	void *end;
	size_t element_size;
};

stack_t *StackCreate(size_t element_size, size_t capacity)
{
	stack_t *newstack = (stack_t *)malloc(sizeof(stack_t)); 
	if(NULL == newstack)
	{
		return NULL;
	}

	newstack->start = (void *)malloc(element_size * capacity);
	if(NULL == newstack->start)
	{
		return NULL;
	}

	newstack->element_size = element_size;	
	newstack->current = newstack->start;
	newstack->end = (char *)(newstack->start) + (element_size * capacity);

	return newstack;
}

int StackPush(stack_t *stack, const void *data)
{
	assert(NULL != stack);
	assert(NULL != data);
	
	if (stack->current == stack->end)
	{
		return 0;
	}
	else
	{
		memcpy(stack->current, data, stack->element_size);
		stack->current = (char *)(stack -> current) + stack->element_size;
	}
	return 1;
}

void *StackPop(stack_t *stack)
{
	void *curr = StackPeek(stack);

	assert(NULL != stack);
	
	if (stack->current != stack->start)
	{
		stack->current = (char *)(stack->current) - stack->element_size;
	}
	
	return curr;
}

int StackIsEmpty(const stack_t *stack)
{
	assert(NULL != stack);
	
	return (stack->current == stack->start);
}

size_t StackSize(const stack_t *stack)
{
	assert(NULL != stack);
	
	return (((size_t)(stack->current) - (size_t)(stack->start)) / 
		stack -> element_size);
}

void *StackPeek(const stack_t *stack)
{
	assert(NULL != stack);
	
	if (stack->current == stack->start)
	{
		return NULL;
	}
	else
	{
		return (char *)stack->current - stack->element_size;
	}
}

void StackDestroy(stack_t *stack)
{
	assert(NULL != stack);
		
	free(stack->start); stack->start = NULL;
	free(stack); stack = NULL;
}

void StackSortRec(stack_t *stack)
{
	int num = 0, curr = 0;
	
	if (2 > StackSize(stack))
	{
		return;
	}

	else if (2 == StackSize(stack))
	{
		num = *(int *)StackPop(stack);
			
		if (num > *(int *)StackPeek(stack))
		{
			StackPush(stack, &num);
		}
		
		else
		{
			curr = *(int *)StackPop(stack);
			StackPush(stack, &num);
			StackPush(stack, &curr);
		}
			
		return;
	}
	
	num = *(int *)StackPop(stack);
	StackSortRec(stack);
	
	if (num < *(int *)StackPeek(stack))
	{
		curr = *(int *)StackPop(stack);
		StackPush(stack, &num);
		StackSortRec(stack);
		StackPush(stack, &curr);
	}
	
	else
	{
		StackPush(stack, &num);
	}
}










