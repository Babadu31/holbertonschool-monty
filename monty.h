#ifndef MONTY_H
#define MONTY_H
<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdarg.h>
#include <ctype.h>

=======
#define  _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
>>>>>>> cd905391497bc4dbbc2b2f04b24a87279cc6b957

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
<<<<<<< HEAD
extern stack_t *head;
void push(stack_t **stack, unsigned int nline);
void pall(stack_t **stack, unsigned int nline);
void pint(stack_t **stack, unsigned int nline);
int interpreter_line(char *pline, unsigned int nline, int mode);
void search_func(char *opcode, char *v, unsigned int nline, int mode);
void exec_fun(void (*f)(), char *opcode, char *v, unsigned int nline, int mode);

stack_t *create_node(int n);
void free_node();
=======

/**
 * struct global_s - funtional data for project
 * @n_lines: lines counter
 * @stack_head: stack head
 * @fp_struct: file
 * @getl_info: line content
 * @node_data: data node number
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct global_s
{
	FILE *fp_struct;
	stack_t *stack_head;
	char *getl_info;

	int node_data;
	unsigned int n_lines;

} global_t;

extern global_t var;

void execute_opcode(char *opcode);
void handle_dlist_head(stack_t *head);
char *split_str(char *str_to_split);
void is_digit(char *number);
int delim_checker(char *str);
size_t dlistint_len(stack_t *h);

void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
>>>>>>> cd905391497bc4dbbc2b2f04b24a87279cc6b957

#endif
