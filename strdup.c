#include "shell.h"
/**
 * _strdup - function  that returns a pointer to a newly
 * allocated space in memory  which contains a copy of string
 * given as a parameter
 * @str: string to be duplicated
 * Return: duplicate string on success or NULL on failure
 */

char *_strdup(char *str)
{
	char *cpy = NULL;
	int i, j = 0;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	cpy = malloc(sizeof(char) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
	{
		cpy[j] = str[j];
	}
	return (cpy);
}
