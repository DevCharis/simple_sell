#include "shell.h"
/**
 * check_file_exists - Check if a file exists.
 * @path: Path to the file.
 * Return: 1 if file exists, 0 otherwise.
 */
int check_file_exists(char *path)
{
return (access(path, F_OK) == (0));
}
/**
 * execute_command - Execute a command with arguments.
 * @args: Command arguments.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char **args)
{
pid_t pid;
int status;
char *command = args[0];
pid = fork();
if (pid == 0)
{
if (execvp(command, args) == -1)
{
perror("Error executing command");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Fork failed");
return (-1);
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (0);
}

