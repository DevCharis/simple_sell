#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
char *command = NULL;
size_t size = 0;
while (1)
{
printf("#cisfun$ ");
if (getline(&command, &size, stdin) == -1)
{
free(command);
exit(0);
}
command[strcspn(command, "\n")] = 0; // Remove newline character
if (fork() == 0)
{
execve(command, NULL, environ);
perror(command);
exit(1);
}
wait(NULL);
}
free(command);
return (0);
}

