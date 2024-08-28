
#include "shell.h"
/**
 * execute_command - Execute a command using execve
 * @command: The command to execute
 */
void execute_command(char **args) {
pid_t child_pid;
int status;

child_pid = fork();
if (child_pid == -1) {
perror("Error:");
} else if (child_pid == 0) {
/*Child process*/
if (execvp(args[0], args) == -1) {
perror("Error:");
}
exit(EXIT_FAILURE); /* Exit child after execvp */
} else {
/* Parent process*/
wait(&status); /* Wait for child to exit*/
}
}

void check_file_exists(char *filename) {
struct stat st;
if (stat(filename, &st) == 0) {
printf("%s: FOUND\n", filename);
} else {
printf("%s: NOT FOUND\n", filename);
}
}

