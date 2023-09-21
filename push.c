#include "monty.h"

/**
 * isInteger - check num is Integer
 *
 * @num: number
 *
 * Return: bool
 */


bool isInteger(char *num)
{
	while (*num != '\0')
	{
		if (*num < '0' || *num > '9')
			return (false);
		num++;
	}
	return (true);
}

/**
 * push - push on the stack
 *
 * @stack: stack
 * @line_number: line read
 *
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *num;
	stack_t *newNode;

	num = strtok(NULL, " ");


	if (num == NULL || !isInteger(num))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = atoi(num);
	newNode->next = *stack;
	newNode->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = newNode;
	*stack = newNode;
}
