#include "shell.h"

/**
*_putchar - character return function
*@c: character
*Return: returns chararter
*/

char _putchar(char c)
{
	return (write(1, &c, 1));
}
