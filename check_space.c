#include "shell.h"

/**
* check_space - checks for space
* @lineptr: string to check for space
* Return: 1 on success or 0 on failure
*/

int check_space(char *lineptr)
{
	int x = 0;

	while (lineptr[x] != '\0')
	{
		if (lineptr[x] == ' ')
			return (1);
		x++;
	}
	return (0);
}
