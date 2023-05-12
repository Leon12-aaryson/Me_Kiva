#include "shell.h"

/**
*com - checking coommand doesn't exists
*@command: users input commmand
*@argv: pointer argument
*@d: counting commands
*Return: returns integer
*/

int com(char *command, char **argv, int d)
{
	int i = 0;

	if (!command)
	{
		i = 1;
		err(argv, d);
		free(command);
	}
	return (i);
}
