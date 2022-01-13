#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global - global structure for head and mode
 * @mode: is stack or queue
 * @head: pointer to pointer to head
 * Description: mode for stack or queue mode and its head pointer
 */
typedef struct global
{
	int mode;
	stack_t *head;
}global_t;

extern global_t global;

int freezer(char *str);
char *_strdup(char *str);
char **_strtok(char *str, char separator);
void _push(stack_t **stack, unsigned int line_number);
size_t print_stack_t(const stack_t *h);
void *getfunc(char **lines);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
int _getcommand(char *token_list[], char *line);
int free_strlist(char *list[]);
void free_dlistint(stack_t *head);
unsigned int checkcomm(char *line);
void findfunc(char *lines[], instruction_t instruct[]);
void _pchar(stack_t **head, unsigned int line_number);
void _rotl(stack_t **head, unsigned int line_number);
void _rotr(stack_t **head, unsigned int line_number);
void add_dnodeint(stack_t **head, int num, unsigned int line_number);
void add_dnodeint_end(stack_t **head, int num, unsigned int line_number);
void _stack(stack_t **head, unsigned int line_number);
void _queue(stack_t **head, unsigned int line_number);
void start_global(void);
#endif
