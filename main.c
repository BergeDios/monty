#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(char **argv, int argc)
{
	int op, re;
	char *error = "USAGE: monty file", **lines;
	char buffer[1024];

	if (argc != 1)
	{
		fprintf(stderr, "USAGE: monty file");
		return (EXIT_FAILURE);
	}
	op = open(argv[1], O_RDONLY);
	if (op < 0)
	{
		fprintf(stderr, "Error: Can't open file <file>");
		return (EXIT_FALIURE);
	}
	re = read(op, buffer, 10);
	lines = _strtok(buffer, 10);
	for (int i = 0; lines[i]; i++)
		printf("%s\n", lines[i]);
	return (0);
}
