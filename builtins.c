#include "simple_shell.h"
/**
 * handle_exit - Handles the exit built-in command
 * 
 * Return: None
 */
void handle_exit(void)
{
exit(EXIT_SUCCESS);
}
/**
 * print_env - Prints the current environment variables
 * 
 * Return: None
 */
void print_env(void)
{
extern char **environ;
int i; /* Declare loop variable outside the loop */
for (i = 0; environ[i] != NULL; i++) /* Iterate and print environment variables */
{
printf("%s\n", environ[i]);
}
}

