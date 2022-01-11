#include "monty.h"

/**
 * getfunc - selects correct function
 * @lines: array of instructions
 * Return: pointer to function
 */
void *getfunc(char **lines)
{
	unsigned int pos = 0, i;
	char *command;
	stack_t *head = NULL;
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};

	for (pos = 0; lines[pos]; pos++)
	{
		i = 0;
		command = strtok(lines[pos], " ");
		while (instruct[i].opcode)
		{
			if ((strcmp(instruct[i].opcode, command) == 0))
				instruct[i].f(&head, pos);
			i++;
		}
	}
	return (NULL);
}
