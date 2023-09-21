#include "monty.h"

stack_t *top_node;

/**
 * get_command - get command and check
 *
 * @portion: command
 * @line: line read
 *
 * Return: nothing
 */


void get_command(char *portion, unsigned int line)
{
	unsigned int i;
	char *command;

	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
	};

	for (i = 0; i < sizeof(operations) / sizeof(operations[0]); i++)
	{
		command = strtok(portion, " ");
		if (strcmp(command, operations[i].opcode) == 0)
		{
			operations[i].f(&top_node, line);
			return;
		}

	}

	if (strlen(portion) > 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s", line, portion);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - entry point
 *
 * @argc: counter
 * @argv: file
 *
 * Return: 0 success
 */


int main(int argc, char **argv)
{
	FILE *filePtr;
	size_t n = 0;
	char *bufferData = NULL;
	ssize_t readLine;
	unsigned int line = 0;
	char *portion;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filePtr = fopen(argv[1], "r");
	if (!filePtr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((readLine = getline(&bufferData, &n, filePtr)) != -1)
	{
		line += 1;
		portion = strtok(bufferData, "\n");
		get_command(portion, line);
	}

	free_all(top_node);
	free(bufferData);
	fclose(filePtr);
	return (0);
}