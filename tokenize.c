#include "shell.h"
/**
* no_token - function that returns the number of tokens
* @lineptr: string to tokenize
* @delim: set of bytes that delimit the tokens in parsed string
* Return: number of tokens
*
*/
int no_token(char *lineptr, const char *delim)
{
	int no_tokens = 0;
	char *token = NULL;

	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		no_tokens++;
		token = strtok(NULL, delim);
	}
	return (no_tokens);
}
