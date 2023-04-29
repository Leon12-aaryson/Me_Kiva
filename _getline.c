#include "shell.h"
/**
* _getline - function that reads a line from stdin
* @strptr: pointer to buffer that stores the line read
* @x: size of buffer
* @stream: user input from keyboard
* Return: no of characters read, -1 on error / EOF
*/

ssize_t _getline(char **strptr, size_t *x, FILE *stream)
{
	char *location = NULL;
	size_t buff_size = *x;
	size_t read_char = 0;
	ssize_t n_bytes = 0;
	int y = fileno(stream);
	char *buff = NULL;

	if (strptr == NULL || x == NULL || stream == NULL)
		return (-1);
	if (buff_size == 0)
	{
		buff_size = 100;
	}
	buff = _alloc(buff_size);
	location = buff;
	while ((n_bytes = read(y, location, 1)) > 0)
	{
		read_char++;
		if (read_char >= buff_size)
		{
			buff_size *= 2;
			buff = realloc(buff, buff_size);
			if (buff == NULL)
				return (-1);
		}
		if (buff[read_char - 1] == '\n')
			break;
		location++;
	}
	if (n_bytes == -1 || n_bytes == 0)
	{
		free(buff);
		return (-1);
	}
	buff[read_char] = '\0';
	*strptr = buff;
	*x = buff_size;
	return (read_char);
}
