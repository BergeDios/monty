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
/**
 * _rotl - rotates the first element of stack to end
 * @head: pointer to pointer to head
 * @line_number: line number
 * Return: void
 */
void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp1 = NULL;
	stack_t *temp2 = NULL;

	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		return;
	temp1 = (*head)->next;
	temp2 = *head;

	for (; temp2->next != NULL; temp2 = temp2->next)
		;

	temp1->prev = NULL;
	temp2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp2;
	*head = temp1;
}
/**
 * _rotr - reverse the stack
 * @head: pointer to pointer of head
 * @line_number: line number
 * Return: nothing
 */
void _rotr(stack_t **head, unsigned int line_number)
{
	stack_t *aux = NULL;

	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
		return;
	aux = *head;
	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *head;
	aux->prev = NULL;
	(*head)->prev = aux;
	*head = aux;
}
/**
 * add_dnodeint_end - adds node at end of dll
 * @head: pointer to pointer to head
 * @num: data for new node
 * @line_number: line number for error
 * Return: address of new node or NULL
 */
void add_dnodeint_end(stack_t **head, int num, unsigned int line_number)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "L%u: usage: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->next = NULL;
	temp = *head;

	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		*head = new;
	new->prev = temp;
}
