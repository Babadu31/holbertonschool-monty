#include "monty.h"

/**
 * op_pop - removes the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 * Return: the number of nodes
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	line_number = line_number;
	
  if (temp == NULL)
	{
		handle_dlist_head(var.stack_head);
		free(var.getl_info);
		fclose(var.fp_struct);
		fprintf(stderr, "L%u: can't pop an empty stack\n", var.n_lines);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	
  if (*stack)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
