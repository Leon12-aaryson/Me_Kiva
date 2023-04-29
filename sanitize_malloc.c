#include "shell.h"
/**
* sanitize_malloc - function that allocates memory
* @size: number of bytes allocated
* Return: ptr
*/
void *sanitize_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		perror("failed to allocate memory");
		return (NULL);
	}
	return (ptr);
}
