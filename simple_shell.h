#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> /* Include for strcspn */
#include <sys/wait.h> /* Include for waitpid */
#include <sys/stat.h>
#include <fcntl.h>
/* Function prototypes */
void prompt(void);
void execute_command(char *input);
char **parse_input(char *input); /* New function prototype */
char *find_command(char *command); /* Function to find command in PATH */

#endif /* SIMPLE_SHELL_H */

