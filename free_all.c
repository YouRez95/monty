#include "monty.h"

/**
 * free_all - free memory
 *
 * @top: topmost of stack
 *
 * Return: nothing
 */


void free_all(stack_t *top)
{
	stack_t *temp;

	temp = top->next;
	while (top != NULL)
	{
		free(top);
		top = temp;
		if (temp != NULL)
			temp = temp->next;
	}
}

