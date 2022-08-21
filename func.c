#include "monty.h"

void push(stack_t **stack, unsigned int nline)
{
  stack_t *tmp;
  (void)nline;


	if (stack == NULL || *stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
  {
    head = *stack;
    return;
  }
  tmp = head;
  head = *stack;
  head->next = tmp;
  tmp->prev = head;
}

void pall(stack_t **stack, unsigned int nline)
{
	stack_t *h = *stack;
	(void)nline;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**void addnode(stack_t **stack, unsigned int nline)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(2, line_number);

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}*/

int interpreter_line(char *pline, unsigned int nline, int mode)
{
	const char *delim;
	char *opcode;
	char *val;

	if (pline == NULL)
  {
	  fprintf(stderr, "Error: malloc failed\n");
    free_node();
    exit(EXIT_FAILURE);
    }
 

	delim = "\n ";
	opcode = strtok(pline, delim);
	if (opcode == NULL)
		return (mode);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	if (strcmp(opcode, "stack") == 0)
		return (0);
  
  
  search_func(opcode, val, nline, mode);

	return (mode);
  }

void search_func(char *opcode, char *val, unsigned int nline, int mode)
{
	int i;
	int d;
	instruction_t funct_list[] = {
		{"push", push}, 
		{"pall", pall}, {NULL, NULL}};



   for (i = 0, d = 1; funct_list[i].opcode != NULL; i++)
    {
      
      if(strcmp(opcode, funct_list[i].opcode) == 0)
      {
        
        exec_fun(funct_list[i].f, opcode, val, nline, mode);
        d = 0;
        }
      
    }
  if (d == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", nline, opcode);
    free_node();
		exit(EXIT_FAILURE);
	}
}

void exec_fun(void (*f)(), char *opcode, char *val, unsigned int nline, int mode)
{
	stack_t *node;
	int j = 1;
	int k;

	if (strcmp(opcode, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			j = -1;
		}
		if (val == NULL)
    {
      fprintf(stderr, "L%d: usage: push integer\n", nline);
      free_node();
      exit(EXIT_FAILURE);
    }

		for (k = 0; val[k] != '\0'; k++)
		{
			if (isdigit(val[k]) == 0)
      {
        fprintf(stderr, "L%d: usage: push integer\n", nline);
        free_node();
        exit(EXIT_FAILURE);
        }
		}
    
		node = create_node(atoi(val) * j);
		if (mode == 0)
			f(&node, nline);
  }
   else
		  f(&head, nline);
  }


stack_t *create_node(int n)
{
  stack_t *node;

  node = malloc(sizeof(stack_t ));
  if (node == NULL)
  {
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }
  node->next = NULL;
  node->prev = NULL;
  node->n = n;

  return (node);
}
void free_node()
{
  stack_t *tmp;

  if (head == NULL)
    return;

  while (head != NULL)
    {
      tmp = head;
      head = head->next;
      free(tmp);
    }
}
