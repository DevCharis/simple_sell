#include "simple_shell.h"
/**
 * parse_input - Parses the input string into an array of arguments
 * @input: The command line input from the user
 * 
 * Return: An array of arguments
 */
char **parse_input(char *input)
{
char **argv = malloc(64 * sizeof(char *)); /* Allocate memory for arguments */
char *token;
int position = 0;
token = strtok(input, " "); /* Split input into tokens */
while (token != NULL)
{
argv[position] = token;
position++;
token = strtok(NULL, " ");
}
argv[position] = NULL; /* Null terminate the array */
return argv;
}

