#include "monty.h"
/**
 * _push - inserts node at begginning
 * @head: opinter to pointer of head
 * @line_number: number of line of opcode
 * Return: 1 success -1 fail
 */
void _push(stack_t **head, unsigned int line_number)
{
	int num;
	char *value;

	value = strtok(NULL, " ");
	if (value == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(value);
	if (global.mode == 1)
		add_dnodeint(head, num, line_number);
	if (global.mode == 0)
		add_dnodeint_end(head, num, line_number);
}
/**
 * add_dnodeint - adds node at beggining of dll
 * @head: pointer to pinter to head of dll
 * @num: data for new node
 * @line_number: line number for error
 * Return: nothing
 */
void add_dnodeint(stack_t **head, int num, unsigned int line_number)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "L%d: usage: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	temp = global.head;
	if (temp != NULL)
	{
		while (temp->prev != NULL)
			temp = temp->prev;
	}
	new->next = temp;
	if (temp != NULL)
		temp->prev = new;
	*head = new;
}
/**
 * _pall - prints all nodes
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *aux;

	(void)line_number;
	if (*head)
	{
		aux = *head;
		while (aux->prev != NULL)
		{
			aux = aux->prev;
		}
		while (aux != NULL)
		{
			printf("%d\n", aux->n);
			aux = aux->next;
		}
	}
}

/**
 * _pint - print the head node
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _pint(stack_t **head, unsigned int line_number)
{
	if (!head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _pop - removes the top element of the stack
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _pop(stack_t **head, unsigned int line_number)
{

	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
}
