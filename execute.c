#include "shell.h"
/**
 * check_file_exists - Check if a file exists.
 * @path: Path to the file.
 * Return: Void.
 */
void check_file_exists(char *path)
{
if (access(path, F_OK) == 0)
{
printf("File exists: %s\n", path);
}
else
{
printf("File does not exist: %s\n", path);
}
}
/**
 * execute_command - Execute a command with arguments.
 * @args: Command arguments.
 * Return: Void.
 */
void execute_command(char **args)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("Error executing command");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("Fork failed");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
}

