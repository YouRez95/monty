#include "monty.h"

/**
 * pop - remove the top element
 *
 * @stack: stack
 * @line_number: line read
 *
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	free(temp);
}
