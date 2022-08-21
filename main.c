#include "monty.h"

stack_t *head = NULL;


int main(int argc, char *argv[])
{
	FILE *fd;
  char *pline;
  size_t size;
  int mode = 0;
  unsigned int nline = 1;
  stack_t *head = NULL;

  pline = NULL;
  size = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
 
	fd = fopen(argv[1], "r");
  if (fd == NULL)
  {
    fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
    free_node();
    exit(EXIT_FAILURE);
  }

  while (getline (&pline, &size, fd) != -1)
    {
      
		  mode = interpreter_line(pline, nline, mode);

      nline++;
      }
  
  free(pline);
  fclose(fd);
	return (EXIT_SUCCESS);
  
}
