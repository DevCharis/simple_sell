#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - Simple shell implementation
 * Return: Always 0.
 */
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
while (1)
{
printf("#cisfun$ ");
nread = getline(&line, &len, stdin);
if (nread == -1)
{
perror("getline");
break;
}
system(line);
}
free(line);
return (0);
}

