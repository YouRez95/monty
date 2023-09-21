#include "monty.h"

/**
 * swap - swap btw two top element
 *
 * @stack: top element
 * @line_number: line read
 *
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int data;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = data;
}
