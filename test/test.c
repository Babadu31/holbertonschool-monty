#include "monty.h"

#define Size 4
int Top = -1, inp_array[Size];

void Push(void);
void Pop(void);
void show(void);

/**
* main - abc
* Return: dzd
* @ac: sdsd
* @av: dzdsd
**/
int main(int ac, char **av)
{
FILE *fp;
char *line = NULL;
size_t len = 0;
ssize_t read;
int choice;

while (1)
{
if (scanf("%d", &choice))
{};
switch (choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
show();
break;
case 4:
exit(0);
default:
printf("\nInvalid choice!!");
}
}

(void)ac;

fp = fopen(av[1], "r");
if (fp == NULL)
exit(EXIT_FAILURE);

while ((read = getline(&line, &len, fp)) != -1)
{
printf("%s", line);
}

fclose(fp);
if (line)
free(line);
exit(EXIT_SUCCESS);
}

/**
* push - ddfdf
**/
void push(void)
{
int x;

if (Top == Size - 1)
{
printf("\nOverflow!!");
}
else
{
printf("\nEnter element to be inserted to the stack:");
if (scanf("%d", &x)) { }
Top = Top + 1;
inp_array[Top] = x;
}


/**
* pop - dasas
**/
void pop(void)
{
if (Top == -1)
{
printf("\nUnderflow!!");
}
else
{
printf("\nPopped element:  %d", inp_array[Top]);
Top = Top - 1;
}
}

/**
* show - sasa
**/
void show(void)
{
if (Top == -1)
{
printf("\nUnderflow!!");
}
else
{
printf("\nElements present in the stack: \n");
for (int i = Top; i >= 0; --i)
printf("%d\n", inp_array[i]);
}
}
}
