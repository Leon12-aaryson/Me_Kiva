#include "shell.h"
/**
 * _strcat - function that concatenates two strings
 * @dest: destination string to be concatenated
 * @src: source string to be concatenated
 * Return: pointer to resulting string dest
 *
 */
char *_strcat(char *dest, char *src)
{
	int length, x;
	/*derive size of string dest and store it in length*/
	length = 0;
	while (dest[length] != '\0')
	{
		++length;
	}


	for (x = 0; src[x] != '\0'; ++x, ++length)
	{
		dest[length] = src[x];
	}
	dest[length] = '\0';

	return (dest);
}
