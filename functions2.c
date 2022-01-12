#include "monty.h"

/**
 * _div - div the top two elements of the stack
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _div(stack_t **head, unsigned int line_number)
{
	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->n == 0)
		{
			fprintf(stderr, "L%d>: division by zero", line_number);
			exit(EXIT_FAILURE);
		}
		(*head)->next->n = (*head)->next->n / (*head)->n;
		_pop(head, line_number);
	}
}
/**
 * free_strlist - frees a char *list[]
 * @list: list to free
 * Return: 0 on success or -1 on failure
 */
int free_strlist(char *list[])
{
	int pos;

	if (!*list)
	{
		perror("no list to free");
		return (-1);
	}
	for (pos = 0; list[pos]; pos++)
		free(list[pos]);
	return (0);
}
/**
 * free_dlistint - frees a dll
 * @head: head of linked list pointer
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	if (head)
	{
		while (head->prev != NULL)
			head = head->prev;
	}

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
/**
 * _mod - rest of the division of the second top element by the next
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _mod(stack_t **head, unsigned int line_number)
{
	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->n == 0)
		{
			fprintf(stderr, "L%d>: division by zero", line_number);
			exit(EXIT_FAILURE);
		}
		(*head)->next->n = (*head)->next->n / (*head)->n;
		_pop(head, line_number);
	}
}
