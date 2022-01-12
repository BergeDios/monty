#include "monty.h"

/**
 * getfunc - selects correct function
 * @lines: array of instructions
 * Return: pointer to function
 */
void *getfunc(char **lines)
{
	stack_t *head = NULL;
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pstr", _pstr},
		{NULL, NULL}
	};
	findfunc(lines, instruct);
	free_dlistint(head);
	return (NULL);
}
/**
 * _getcommand - gets the line and separates into tokens
 * @token_list: pointer to token list
 * @line: pointer to prompt input
 * Return: 0 on succes | -1 on failure
 */
int _getcommand(char *token_list[], char *line)
{
	char *token = NULL, *delim = "\n";
	int pos_tok = 0;

	token = strtok(line, delim);
	while (token != NULL)
	{
		token_list[pos_tok] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!token_list[pos_tok])
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		strcpy(token_list[pos_tok], token);
		pos_tok++;
		token = strtok(NULL, delim);
	}
	token_list[pos_tok] = NULL;
	return (0);
}
/**
 * findfunc - findes correct function
 * @lines: instruction list
 * @instruct: struct of instructions functions
 * Return: void
 */
void findfunc(char *lines[], instruction_t instruct[])
{
	unsigned int pos = 0, i = 0, check;
	char *command;
	stack_t *head = NULL;

	for (pos = 0; lines[pos]; pos++)
	{
		check = checkcomm(lines[pos]);
		if (check == 1 || lines[pos][0] == '\n')
			continue;
		i = 0;
		command = strtok(lines[pos], " ");
		while (instruct[i].opcode)
		{
			if ((strcmp(instruct[i].opcode, command) == 0))
			{
				instruct[i].f(&head, (pos + 1));
				break;
			}
			i++;
		}
		if (instruct[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", (pos + 1), command);
			exit(EXIT_FAILURE);
		}
	}
}
