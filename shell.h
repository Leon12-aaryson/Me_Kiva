#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

char **tokenize_input(char *input);
void execute_command(char **tokens);
void shell_loop(void);

char *_strchr(const char *s, char c);
char *_strncpy(char *dest, char *src, int n);
int _strlen(const char *str);
void interactive(int argc, char **argv);

int _strncmp(const char *s1, const char *s2, size_t n);
char *_alloc(int c);
ssize_t _getline(char **strptr, size_t *x, FILE *stream);
char _putchar(char c);
char *_strtok(char *str, const char *delim);
int no_token(char *lineptr, const char *delim);
char **input_parser(char *lineptr, const char *delim, int *no_tokens);
void execmd(char *command, char **argv, char *actual_command);
int stat(const char *pathname, struct stat *statbuf);
char *location(char *command);
void *sanitize_malloc(size_t size);
void sanitize(char **argv);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int check_space(char *lineptr);
void exec(char **argv);
void _puts(char *str);
void is_env(char **argv);
void is_exit(char **argv, char *lineptr, char *lineptr_cpy, int no_tokens);
int _atoi(char *x);
ssize_t reader(char *buffer, size_t *begin, size_t end,
		char **strptr, size_t *x);
void cd_cmd(char **argv);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);

#endif
