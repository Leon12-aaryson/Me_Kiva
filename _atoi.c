#include "shell.h"
/**
* _atoi - function that changes a string to an integer
* @str: string parameter to be chnged
* Return: integer value of string
*/

int _atoi(char *str)
{
	int x = 0;
	unsigned int outcome = 0;
	int sign = 1;
	int flag = 0;

	while (str[x])
	{
		if (str[x] == 45)
			sign *= -1;
		while (str[x] >= 48 && str[x] <= 57)
		{
			flag = 1;
			outcome = (outcome * 10) + (str[x] - '0');
			x++;
		}
		if (flag == 1)
			break;
		x++;
	}
	outcome *= sign;
	return (outcome);
}
