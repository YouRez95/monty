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

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	temp = temp->next;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	if (temp->next)
		temp->next->prev = (*stack);
	temp->next = *stack;
	temp->prev = NULL;

	*stack = temp;
}
