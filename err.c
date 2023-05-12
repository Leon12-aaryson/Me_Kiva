#include "shell.h"

/**
*err - error message
*@argv: pointer argument
*@d: keep track of commands
*Return: returns nothing
*/

void err(char **argv, int d)
{
	_puts("./hsh: ");
	_putchar(d + 48);
	_puts(": ");
	_puts(argv[0]);
	_puts(": not found\n");
}
