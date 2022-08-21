#include "monty.h"

/**
 * is_digit - check is digit
 * @number: character for check
 * Return: void
 */
void is_digit(char *number)
{
unsigned int i = 0;

if (number == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", var.n_lines);
free(var.getl_info);
handle_dlist_head(var.stack_head);
fclose(var.fp_struct);
exit(EXIT_FAILURE);
}
else if (number[0] != '-' && (number[0] < 48 || number[0] > 57))
{
fprintf(stderr, "L%u: usage: push integer\n", var.n_lines);
free(var.getl_info);
handle_dlist_head(var.stack_head);
fclose(var.fp_struct);
exit(EXIT_FAILURE);
}
for (i = 1; number[i] != '\0'; i++)
{
if (number[i] < 48 || number[i] > 57)
{
fprintf(stderr, "L%u: usage: push integer\n", var.n_lines);
free(var.getl_info);
handle_dlist_head(var.stack_head);
fclose(var.fp_struct);
exit(EXIT_FAILURE);
}
}
}

/**
 * delim_checker - check whitespaces
 * @str: string for check
 * Return: void
 */
int delim_checker(char *str)
{
int index = 0, flag = 0, len = 0;
len = strlen(str);
while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
{
index++;
}

if (index == len)
flag = 1;

return (flag);
}
