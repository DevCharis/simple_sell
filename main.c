#include "simple_shell.h"
/**
 * main - Entry point of the shell
 * 
 * Return: Always 0 (Success)
 */
int main(void)
{
char *input;
size_t len = 0;
while (1)
{
printf(":) ");
if (getline(&input, &len, stdin) == -1)
{
free(input);
exit(EXIT_FAILURE);
}
execute_command(input);
}
free(input);
return 0;
}

