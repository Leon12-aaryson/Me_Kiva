#include "shell.h"

/**
*_strncpy - function to copy bytes of strings
*@dest: is the destination ftring
*@src: source string
*@n: number of bytes to copy
*
*Return: destination string
*/

char *_strncpy(char *dest, char *src, int n)
{
	int len, x;

	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}

	for (x = 0; x < n && src[x] != '\0'; x++)
	{
		dest[x] = src[x];
	}

	for (; x < n; x++)
	{
		dest[x] = '\0';
	}
	return (dest);
}
