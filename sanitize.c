#include "shell.h"
/**
* sanitize - frees argv
* @argv: pointer to pointer to be cleaned up
* Return: nothing
*/
void sanitize(char **argv)
{
	int x;

	for (x = 0; argv[x] != NULL; x++)
		free(argv[x]);

	free(argv);
}
