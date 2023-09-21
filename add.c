#include "monty.h"

/**
 * add - add n of two top elements
 *
 * @stack: top element
 * @line_number: line read
 *
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;


	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp->next->n += temp->n;
	(*stack) = (*stack)->next;
	free(temp);
}
