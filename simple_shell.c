#include "shell.h"
/**
 * split_string - Split a string into an array of arguments.
 * @str: String to be split.
 * Return: Array of arguments.
 */
char **split_string(char *str)
{
char **result = malloc(64 * sizeof(char *));
int i = 0;
char *token = strtok(str, " \n");
while (token != NULL)
{
result[i++] = token;
token = strtok(NULL, " \n");
}
result[i] = NULL;
return (result);
}
/**
 * print_prompt - Print the shell prompt.
 */
void print_prompt(void)
{
printf("$ ");
}
/**
 * main - Main function to run the simple shell.
 * Return: 0 on success.
 */
int main(void)
{
char *input = NULL;
size_t len = 0;
char **args;
while (1)
{
print_prompt();
getline(&input, &len, stdin);
args = split_string(input);
if (args[0] != NULL)
{
execute_command(args);
}
free(args);
}
free(input);
return (0);
}

