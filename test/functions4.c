#include "monty.h"
/**
 * _stack - sets mode to FILO
 * @head: pointer to pointer of head
 * @line_number: line number
 * Return: nothing
 */
void _stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	global.mode = 1;
}
/**
 * _queue - sets mote to FILO
 * @head: pointer to pointer of head
 * @line_number: line_number
 * Return: nothing
 */
void _queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	global.mode = 0;
}
