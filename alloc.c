#include "shell.h"

/**
*_alloc - memory a\llocation funtion
*@c: number of bytes
*
*Return: returns pointer
*/

char *_alloc(int c)
{
	int x = 0;
	char *ptr = malloc(sizeof(char) * c + 1);

	if (!ptr)
	{
		perror("Error allocating memory");
		return (NULL);
	}

	while (x < c)
	{
		ptr[x] = 0;
		x++;
	}
	return (ptr);
}
