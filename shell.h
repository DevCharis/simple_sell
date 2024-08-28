#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

/* Function prototypes */
void display_prompt(void);
char *read_input(void);
int execute_command(char *command);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void free_memory(char **args);
void handle_sigint(int sig);

#endif /* SHELL_H */

