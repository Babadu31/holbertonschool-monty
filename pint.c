#include "monty.h"

/**
 * op_pint - prints the value at the top of the
 * stack, followed by a new line
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 * Return: void
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
if ((*stack) == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
free(var.getl_info);
fclose(var.fp_struct);
handle_dlist_head((*stack));
exit(EXIT_FAILURE);
}
printf("%d\n", ((*stack))->n);
}
