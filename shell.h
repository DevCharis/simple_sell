#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * split_string - Splits a string into an array of arguments.
 * @str: The input string to be split.
 *
 * Return: An array of strings (arguments).
 */
char **split_string(char *str);

/**
 * execute_command - Executes a command in a child process.
 * @args: An array of command arguments.
 *
 * This function forks a child process and uses execvp to execute the command.
 */
void execute_command(char **args);

/**
 * print_prompt - Prints the shell prompt.
 *
 * This function displays the shell prompt for user input.
 */
void print_prompt();

/**
 * check_file_exists - Checks if a file exists in the filesystem.
 * @filename: The name of the file to check.
 *
 * This function uses stat to check if a file exists and prints the result.
 */
void check_file_exists(char *filename);

#endif /* SHELL_H */

