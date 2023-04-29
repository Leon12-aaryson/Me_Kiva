#include "shell.h"

/**
*_strncmp - function compares two strings
*@s1: first null terminated string
*@s2: second null terminated string
*@n: the maximam number of characters
*
*Return: returns string
*/

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((s1[i] < s2[i]) ? -1 : 1);
		}

		i++;
	}
	if (i == n)
		return (0);
	return ((s1[i] == '\0') ? -1 : 1);
}

