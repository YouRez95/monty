#include "monty.h"

/**
 * sub - substracty two first top element
 *
 * @stack: top element
 * @line_number: line read
 *
 * Return: nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	temp = *stack;
	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = temp->next->n - temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
