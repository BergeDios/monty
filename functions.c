#include "monty.h"
/**
 * _push - inserts node at begginning
 * @instructions: string to convert into n data
 * Return: 1 success -1 fail
 */
int _push(char *instructions)
{
	stack_t *node, *temp;
	int num;
	char *token;
	stack_t *head = NULL;

	token = NULL;


	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		return (-1);
	}
	token = strtok(instructions, " ");
	token = strtok(NULL, " ");
	num = atoi(token);
	node->n = num;
	node->prev = NULL;
	temp = head;

	if (temp != NULL)
	{
		/* making sure temp is at start*/
		while (temp->prev != NULL)
			temp = temp->prev;
	}
	node->next = temp;
	if (temp != NULL)
		temp->prev = node;
	head = node;
	print_stack_t(head);
	return (1);
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
