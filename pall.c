#include "monty.h"
/**
 * pall - entry point
 *
 * @stack: stack
 * @line_number: line read
 *
 * Return: nothing
 */



void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	temp = *stack;
	if (temp == NULL)
	{
		printf("stack is Empty\n");
		return;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
