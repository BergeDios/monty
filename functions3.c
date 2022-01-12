#include "monty.h"
/**
 * checkcomm - checks for #
 * @line: instruction to check
 * Return: 0 no comment, 1 if comment
 */
unsigned int checkcomm(char *line)
{
	int pos = 0;

	for (pos = 0; line[pos]; pos++)
	{
		if (line[pos] == ' ')
			continue;
		else if (line[pos] == '#')
			return (1);
		else
			return (0);
	}
	return (0);
}
