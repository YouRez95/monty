#include "monty.h"

/**
 * mul - mul the second element by the top
 *
 * @stack: top element
 * @line_number: line read
 *
 * Return: nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	temp = *stack;
	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = temp->next->n * temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
