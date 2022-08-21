#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 * Return: the number of nodes
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	size_t n = 0;
	stack_t *temp = *stack;

	line_number = line_number;
	n = dlistint_len(var.stack_head);
	
  if (n < 2)
	{
		handle_dlist_head(var.stack_head);
		free(var.getl_info);
		fclose(var.fp_struct);
		fprintf(stderr, "L%u: can't add, stack too short\n", var.n_lines);
		exit(EXIT_FAILURE);
	}
	
  if (*stack != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->n = (*stack)->n + (*stack)->prev->n;
		(*stack)->prev = NULL;
		free(temp);
	}
}
