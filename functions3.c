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
/**
 * _pchar - prints char at top of stack
 * @head: pointer to pointer to head
 * @line_number: number of instruction line
 * Return: no return
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
