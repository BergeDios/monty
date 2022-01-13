#include "monty.h"

global_t global;
/**
 * start_global - start global variables
 * Return: nothing
 */
void start_global(void)
{
	global.mode = 1;
	global.head = NULL;
	global.command = NULL;
}
/**
 * main - interprets monty
 * @argc: argument counter
 * @argv: argument vector
 * Return: 1 on success
 */
int main(int argc, char **argv)
{
	char *lines[1024];
	char *buffer;
	size_t buffsize = 1024;
	FILE *op;
	unsigned int line_number = 1;

	*lines = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	op = fopen(argv[1], "r");
	if (op == NULL)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		return (EXIT_FAILURE);
	}
	start_global();
	printf("before getline\n");
	while (getline(&buffer, &buffsize, op) != -1)
	{
		if (buffer[(strlen(buffer) - 1)] == '\n')
			buffer[(strlen(buffer) - 1)] = '\0';
		printf("buffer is: %s\n", buffer);
		global.command = strtok(buffer, " ");
		printf("*commands is:*%s*\n", global.command);
		if (!global.command)
			continue;
		if (global.command[0] == '#')
		{
			free(buffer);
			buffer = NULL;
			continue;
		}
		getfunc(line_number);
		line_number++;
		free(buffer);
		buffer = NULL;
	}
	return (0);
}
