#include "shell.h"

/**
* interactive - this is the main function of the interactive
*	simple shell programe
*@envp: environment
*@argc: this is an integer argument
*@argv: character pointer array
* Return: The function returns a value of 0 on success
*/

void interactive(int argc, __attribute__((unused)) char **argv, char **envp)
{
	char *lineptr = NULL, *lineptr_cpy = NULL, **av = NULL;
	size_t x = 0;
	int y = 0, d = 0;
	ssize_t reach_char;
	const char *delim = " \n";

	while (1)
	{
		_puts("$ ");
		d++;
		fflush(stdout);
		reach_char = getline(&lineptr, &x, stdin);
		if (reach_char == -1)
			break;
		if (reach_char == 1)
			continue;
		av = input_parser(lineptr, delim, &argc);
		if (av[0] == NULL)
		{
			free(av);
			continue;
		}
		argc = no_token(lineptr, delim);
		is_exit(av, lineptr, lineptr_cpy, argc);
		is_env(av);
		if (strcmp(av[0], "env") != 0)
			exec(av, envp, d);
		for (y = 0; y < argc; y++)
			free(av[y]);
		free(av);

	}
	free(lineptr);
}
/**
* non_interactive - this is the main function of the interactive
*       simple shell programe
*@envp: environment
*@argc: this is an integer argument
*@argv: character pointer array
* Return: The function returns a value of 0 on success
*/

void non_interactive(int argc, __attribute__((unused)) char **argv,
char **envp)
{
	char *lineptr = NULL, *lineptr_cpy = NULL, **av = NULL;
	size_t x = 0;
	ssize_t reach_char = 0;
	const char *delim = " \n";
	int y, d = 0;


	while (1)
	{
		d++;
		reach_char = getline(&lineptr, &x, stdin);
		if (reach_char == -1)
			break;
		if (reach_char == 1)
			continue;
		av = input_parser(lineptr, delim, &argc);
		if (av[0] == NULL)
		{
			free(av);
			continue;
		}
		argc = no_token(lineptr, delim);
		is_exit(av, lineptr, lineptr_cpy, argc);
		is_env(av);
		if (strcmp(av[0], "env") != 0)
			exec(av, envp, d);
		for (y = 0; y < argc; y++)
			free(av[y]);
		free(av);
	}
	free(lineptr);
}

/**
*main - code for main function
*@argc: integer argument
*@envp: environment
*@argv: pointer array
*Return: returns 0
*/

int main(int argc, char **argv, char **envp)
{
	if (isatty(STDIN_FILENO))
	{
		interactive(argc, argv, envp);
	}
	else
	{
		non_interactive(argc, argv, envp);
	}
	return (0);
}
