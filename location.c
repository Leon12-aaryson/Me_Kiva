#include "shell.h"
/**
* location - function that return path of a command
* @command: command whose path is returned
* Return: path of command
*/
char *location(char *command)
{
	char *path = NULL, *path_copy = NULL, *path_token = NULL, *file_path = NULL;
	int command_length, dir_length;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			dir_length = strlen(path_token);
			file_path = malloc(command_length + dir_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			/* let's test if this file path actually exists and return it if it does*/
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				/* free up the file_path memory so we can check for another path*/
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
