#include "shell.h"

/**
* interactive - this is the main function of the interactive
*	simple shell programe
*@argc: this is an integer argument
*@argv: character pointer array
* Return: The function returns a value of 0 on success
*/

void interactive(int argc, char **argv)
{
	char *lineptr = NULL, *lineptr_cpy = NULL;
	/*char *prompt = "$ ";*/
	size_t x = 0;
	/*int y;*/
	ssize_t reach_char;
	const char *delim = " \n";

	while (1)
	{	printf("$ ");
		fflush(stdout);
		reach_char = getline(&lineptr, &x, stdin);
		if (reach_char == -1)
			break;
		if (reach_char == 1)
			continue;

		argv = input_parser(lineptr, delim, &argc);
		argc = no_token(lineptr, delim);
		is_exit(argv, lineptr, lineptr_cpy, argc);
		is_env(argv);
		if (strcmp(argv[0], "env") != 0)
			exec(argv);
		/*for (y = 0; y <= argc; y++)
			free(argv[y]);
		free(argv);
		free(lineptr);*/
	}
}
/**
* non_interactive - this is the main function of the interactive
*       simple shell programe
*@argc: this is an integer argument
*@argv: character pointer array
* Return: The function returns a value of 0 on success
*/

void non_interactive(int *argc, char **argv)
{
	char *lineptr = NULL, *lineptr_cpy = NULL;
	size_t x = 0;
	ssize_t reach_char;
	const char *delim = " \n";
	/*int y;*/
	/*char **temp;*/

	fflush(stdout);
	reach_char = getline(&lineptr, &x, stdin);

	while (reach_char != -1)
	{
		if (*lineptr != '\n')
		{
			lineptr[reach_char - 1] = '\0';
			lineptr_cpy = _alloc(reach_char);
			strcpy(lineptr_cpy, lineptr);
			if (check_space(lineptr) == 1)
			{
				free(lineptr_cpy);
				exit(0);
			}
			argv = input_parser(lineptr, delim, argc);
			*argc = no_token(lineptr, delim);
			printf("%d\n", *argc);
			is_exit(argv, lineptr, lineptr_cpy, *argc);
			is_env(argv);
			if (strcmp(argv[0], "env") != 0)
				exec(argv);
			/*temp = argv;*/
			/*for (y = 0; y <= *argc; y++)
				free(argv[y]);
			free(argv);*/
			free(lineptr);
		}
		reach_char = getline(&lineptr, &x, stdin);
	}
}

/**
*main - code for main function
*@argc: integer argument
*@argv: pointer array
*Return: returns 0
*/

int main(int argc, char **argv)
{
	char **temp;

	if (isatty(STDIN_FILENO))
	{
		interactive(argc, argv);
	}
	else
	{
		non_interactive(&argc, argv);
	}
	temp = argv;

	if (temp != NULL)
	{
		for (; *temp != NULL; temp++)
		{
			free(*temp);
			*temp = NULL;
		}
		free(argv);
		argv = NULL;
	}
	return (0);
}
