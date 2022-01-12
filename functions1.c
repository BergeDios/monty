#include "monty.h"
/**
 * _swap - swap the positions of the last 2 nodes
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *aux;
	int auxA, auxB;

	if (!(*head) && !(*head)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	auxA = aux->next->n;
	auxB = aux->n;
	aux->next->n = auxB;
	aux->n = auxA;
}

/**
 * _add - add the top two elements of the stack
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _add(stack_t **head, unsigned int line_number)
{
	int val = 0;

	if (!*head && !(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n += (*head)->n;
		_pop(head, line_number);
	}
}
