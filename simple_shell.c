#include "shell.h"

char **split_string(char *str) {
char **result = malloc(64 * sizeof(char*));
int i = 0;
char *token = strtok(str, " \n");
while (token != NULL) {
result[i++] = token;
token = strtok(NULL, " \n");
}
result[i] = NULL;
return result;
}

void print_prompt() {
printf("$ ");
}

int main(void) {
char *input = NULL;
size_t len = 0;
char **args; /* Declare args at the beginning */
while (1) {
print_prompt(); /* Print the shell prompt */
getline(&input, &len, stdin); /* Get input from user */
/* Split input into arguments */
args = split_string(input);
if (args[0] != NULL) {
execute_command(args); /* Execute the command */
}
free(args); /* Free allocated memory for arguments */
}
free(input); /* Free allocated memory for input */
return 0;
}

