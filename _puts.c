#include "shell.h"

/**
*_puts - output character
*@str: string argumnet
*Returns: string
*/

void _puts(char *str)
{
	int i;

	for (i = 0 ; str[i] != '\0' ; ++i)
	{
		_putchar(str[i]);
	}
}
