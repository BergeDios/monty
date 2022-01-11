#include "monty.h"
/**
 * _push - inserts node at begginning
 * @instruction: string to convert into n data
 * Return: 1 success -1 fail
 */
int _push(char *n)
{
	stack_t *node, *temp;

	head = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		return (-1);
	}
	node->n = n;
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
	return (1);
}
