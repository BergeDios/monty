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
}

/**
 * main - interprets monty
 * @argc: argument counter
 * @argv: argument vector
 * Return: 1 on success
 */
int main(int argc, char **argv)
{
	int op, re;
	char *lines[1024];
	char buffer[1024];

	*lines = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	op = open(argv[1], O_RDONLY);
	if (op < 0)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		return (EXIT_FAILURE);
	}
	start_global();
	re = read(op, buffer, 1024);
	buffer[re - 1] = '\0';
	_getcommand(lines, buffer);
	getfunc(lines);
	if (lines[0])
		free_strlist(lines);
	return (0);
}
