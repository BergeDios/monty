#include "monty.h"
/**
 * main - interprets monty
 * @argc: argument counter
 * @argv: argument vector
 * Return: 1 on success
 */
int main(int argc, char **argv)
{
	int op, re, i;
	char **lines;
	char buffer[1024];

	(void)head;
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
	re = read(op, buffer, 1024);
	buffer[re - 1] = 0;
	lines = _strtok(buffer, 10);
	for (i = 0; lines[i]; i++)
	{
		printf("%s\n", lines[i]);
	}
	_push(lines[0]);
	return (0);
}
