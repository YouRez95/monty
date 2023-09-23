#include "monty.h"

/**
 * pchar - print the first element
 *
 * @stack: top element
 * @line_number: line read
 *
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (!temp)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127)
	{
		fprintf(stderr, "L%u: can,t pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)temp->n);
}
