#include "simple_shell.h"
/**
 * execute_command - Executes the given command
 * @input: The command line input from the user
 * 
 * Return: None
 */
void execute_command(char *input)
{
pid_t pid; /* Process ID */
int status; /* Status of executed command */
char **argv; /* Command arguments */
char *full_path;

input[strcspn(input, "\n")] = 0; /* Remove newline character */
if (strcmp(input, "exit") == 0) /* Check for 'exit' command */
{
exit(EXIT_SUCCESS); /* Exit the shell */
}
if (strcmp(input, "env") == 0) /* Check for 'env' command */
{
print_env(); /* Call print_env function to print environment */
return; /* Return to prompt after printing environment variables */
}
argv = parse_input(input); /* Parse the input into arguments */
if (argv[0] == NULL) /* If no command is entered, return */
{
free(argv);
return;
}
full_path = find_command_in_path(argv[0]); /* Find command in PATH */
if (full_path == NULL) /* Command not found */
{
perror(argv[0]); /* Print error if command does not exist */
free(argv); /* Free allocated memory for arguments */
return; /* Return to prompt */
}
pid = fork(); /* Fork process */
if (pid < 0) /* Fork failed */
{
perror("Fork failed");
free(full_path);
free(argv);
return;
}
else if (pid == 0) /* Child process */
{
execve(full_path, argv, NULL); /* Execute command */
perror(full_path); /* Print error if command fails */
exit(EXIT_FAILURE); /* Exit on failure */
}
else /* Parent process */
{
waitpid(pid, &status, 0); /* Wait for child process to complete */
}
free(full_path); /* Free allocated memory for full path */
free(argv); /* Free allocated memory for arguments */
}
