#include "simple_shell.h"
/**
 * find_command_in_path - Checks if a command exists in the given PATH
 * @command: The command to search for
 * 
 * Return: The full path of the command if found, NULL otherwise
 */
char *find_command_in_path(char *command)
{
char *path = getenv("PATH"); /* Get the PATH environment variable */
char *token = strtok(path, ":"); /* Tokenize the PATH */
struct stat buf; /* Buffer for file status */
char *full_path; /* Full command path */

/* Iterate through each path */
while (token != NULL)
{
full_path = malloc(strlen(token) + strlen(command) + 2); /* Allocate memory for full path */
if (full_path == NULL) /* Check for malloc failure */
{
perror("Memory allocation failed");
return NULL;
}
sprintf(full_path, "%s/%s", token, command); /* Create full path */
if (stat(full_path, &buf) == 0) /* Check if command exists */
{
return full_path; /* Return full path if command is found */
}
free(full_path); /* Free allocated memory for full path */
token = strtok(NULL, ":"); /* Move to next path */
}
return NULL; /* Command not found in PATH */
}

