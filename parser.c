#include "shell.h"
/**
* input_parser - function that parses input
* @lineptr: input string
* @delim: delimiter
* @no_tokens: number of tokens
* Return: pointer to pointer of string arguments
*/

char **input_parser(char *lineptr, const char *delim, int *no_tokens)
{
	char **av, *token, *lineptr_cpy, *lineptr_cpy2;
	int x;

	if (!lineptr || !delim || !no_tokens)
		return (NULL);
	lineptr_cpy = strdup(lineptr);
	lineptr_cpy2 = strdup(lineptr);
	if (lineptr_cpy == NULL)
		return (NULL);

	*no_tokens = 0;
	token = strtok(lineptr_cpy, delim);
	while (token != NULL)
	{
		(*no_tokens)++;
		token = strtok(NULL, delim);
	}
	(*no_tokens)++;
	if (*no_tokens == 0)
	{
		return (NULL);
	}
	av = sanitize_malloc(sizeof(char *) * (*no_tokens));
	token = strtok(lineptr_cpy2, delim);
	for (x = 0; token; x++)
	{
		av[x] = sanitize_malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(av[x], token);
		token = strtok(NULL, delim);
	}
	av[x] = NULL;
	free(lineptr_cpy);
	free(lineptr_cpy2);
	return (av);
}
