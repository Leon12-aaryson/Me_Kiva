#include "shell.h"

/**
 * _strtok - function breaks down strings into tokens
 * @str: string that is to be tokenised or broken down
 * @delim: trigger for termination of function
 *
 * Return: string/token
 */
char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *current_token = NULL;
	const char *delim_char;

	if (str)
		next_token = str;

	while (*next_token)
	{
		for (delim_char = delim; *delim_char; ++delim_char)
			if (*next_token == *delim_char)
				break;
		if (!*delim_char)
			break;
		++next_token;
	}
	if (!*next_token)
		return (NULL);
	current_token = next_token;

	while (*next_token)
	{
		for (delim_char = delim; *delim_char; ++delim_char)
			if (*next_token == *delim_char)
				break;
		if (*delim_char)
			break;
		++next_token;
	}
	if (*next_token)
		*next_token++ = '\0';

	return (current_token);
}
