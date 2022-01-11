#include "monty.h"
/**
 * _push - inserts node at begginning
 * @head: opinter to pointer of head
 * @line_number: number of line of opcode
 * Return: 1 success -1 fail
 */
void _push(stack_t **head, unsigned int line_number)
{
	stack_t *node, *temp;
	int num;
	char *value;

	(void)line_number;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	value = strtok(NULL, " ");
	num = atoi(value);
	node->n = num;
	node->prev = NULL;
	temp = *head;

	if (temp != NULL)
	{
		/* making sure temp is at start*/
		while (temp->prev != NULL)
			temp = temp->prev;
	}
	node->next = temp;
	if (temp != NULL)
		temp->prev = node;
	*head = node;
}
/**
 * print_stack_t - print all the nodes of a doubly linked lists
 * @h: pointer to head of linked list
 * Return: number of nodes
 */
size_t print_stack_t(const stack_t *h)
{
	size_t num = 0;

	if (!h)
		return (num);
	while (h->prev != NULL)/* makes sure you at the start*/
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}
	return (num);


}
/**
 * _pall - prints all nodes
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _pall(stack_t **head, unsigned int line_number)
{
	(void)line_number;

	while ((*head)->prev != NULL)
	{
		*head = (*head)->prev;
	}
	while (*head != NULL)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
}