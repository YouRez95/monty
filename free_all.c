#include "monty.h"

/**
 * free_all - free memory
 *
 * @top: topmost of stack
 *
 * Return: nothing
 */


void free_all(char *buffer)
{
	stack_t *temp;

	temp = top_node->next;
	while (top_node != NULL)
	{
		free(top_node);
		top_node = temp;
		if (temp != NULL)
			temp = temp->next;
	}
	free(buffer);
}

