#include "monty.h"

/**
 * free_all - free memory
 *
 * Return: nothing
 */


void free_all(void)
{
	stack_t *temp;

	if (!top_node)
		return;
	temp = top_node->next;
	while (top_node != NULL)
	{
		free(top_node);
		top_node = temp;
		if (temp != NULL)
			temp = temp->next;
	}
}

