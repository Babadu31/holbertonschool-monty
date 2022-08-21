#include "monty.h"

/**
 * op_pall - prints all the values on the stack
 * starting from the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 * Return: void
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
stack_t *printer_aux = *stack;

printer_aux = *stack;
line_number = line_number;

while (printer_aux != NULL)
{
printf("%d\n", printer_aux->n);
printer_aux = printer_aux->next;
}
}
