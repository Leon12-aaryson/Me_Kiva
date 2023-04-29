#include "shell.h"
/**
* _setenv - sets environment variable
* @name: name of variable
* @value: value to be set
* @overwrite: determines whether to overwrite existing variable
* Return: 0 on success / -1 on failure
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	char **env = NULL, **new_env = NULL;
	size_t str_len, x;
	char *new_value = NULL;

	/* is variable already existing? */
	str_len = strlen(name);
	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, str_len) == 0 && (*env)[str_len] == '=')
		{
			/* update the existing variable if allowed */
			if (!overwrite)
				return (0);

			new_value = malloc(_strlen(value) + str_len + 2);
			sprintf(new_value, "%s=%s", name, value);
			*env = new_value;
			return (0);
		}
	}

	/* count the existing variables */
	x = 0;
	for (env = environ; *env != NULL; env++)
		x++;

	new_env = malloc((x + 2) * sizeof(char *));
	memcpy(new_env, environ, x * sizeof(char *));


	new_value = malloc(_strlen(value) + str_len + 2);
	sprintf(new_value, "%s=%s", name, value);
	new_env[x] = new_value;
	new_env[x + 1] = NULL;

	environ = new_env;
	return (0);
}

/**
* _unsetenv - deletes the variable name from the environment
* @name: variable to be deleted
* Return: 0 on success / -1 on failure
*/
int _unsetenv(const char *name)
{
	char **env = NULL, **lineptr = NULL;
	size_t str_len;

	if (name == NULL || *name == '\0' || _strchr(name, '=') != NULL)
		return (-1);

	str_len = strlen(name);
	for (env = environ; *env != NULL;)
	{
		/* Check if variable matches name */
		if (strncmp(*env, name, str_len) == 0 && (*env)[str_len] == '=')
		{
			lineptr = env;
			free(*env);

			while (*(lineptr + 1) != NULL)
			{
				*lineptr = *(lineptr + 1);
				lineptr++;
			}
			*lineptr = NULL;

			return (0);
		}
	}
	return (0);
}

