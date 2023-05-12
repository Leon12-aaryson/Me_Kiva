#include "shell.h"

/**
* is_exit - function that checks if argument in argv is exit and
* exits teh program
* @argv: array of string arguments
* @lineptr: pointer to buffer storing input line
* @lineptr_cpy: pointer to copy of inpput line
* @no_tokens: no of tokens in argv
* Return: returns exit status
*/

void is_exit(char **argv, char *lineptr, char *lineptr_cpy, int no_tokens)
{
	int x, status;

	(void) no_tokens;
	(void) *lineptr;

	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
			status = _atoi(argv[1]);
		else
			status = EXIT_SUCCESS;
		free(lineptr);
		free(lineptr_cpy);
		for (x = 0; argv[x] != NULL; x++)
			free(argv[x]);
		free(argv);

		exit(status);

	}
}

/**
* is_env - function that checks  if first argument in argv is
* "env" and prints environment variables
* @argv: array of string arguments
* Return: returns integer value
*/

int is_env(char **argv)
{
	int x = 0;

	if (strcmp(argv[0], "env") == 0)
	{
		for (x = 0; environ[x] != NULL; x++)
		{
			_puts(environ[x]);
			_putchar('\n');
		}
	}
	return (x);
}

