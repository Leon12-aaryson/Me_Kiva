#include "shell.h"
/**
* execmd - create child process and execute
* @argv: pointer to pointer of string
* @command: path to command to be executeds
* @envp: environment
* Return: nothing
*/
void execmd(char *command, char **argv, char **envp)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork has failed");
		return;
	}
	if (pid == 0)
	{
		execve(command, argv, envp);
		perror("execve failed");
		return;

	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait failed");
			return;
		}
		if (!WIFEXITED(status))
		{
			fprintf(stderr, "%s: command failure\n", argv[0]);
			return;
		}
	}
}

/**
* exec - function that executes a command
* @envp: environment
* @d: increament commands
* @argv: array of string arguments
* Return: returns void value
*/

void exec(char **argv, char **envp, int d)
{
	char *command;
	int m = 0;

	if (argv)
	{
		command = argv[0];
		if (strcmp(command, "cd") == 0)
			cd_cmd(argv);
		else if (strcmp(command, "setenv") == 0)
		{
			if (argv[1] && argv[2])
			{
				if (setenv(argv[1], argv[2], 1) == -1)
					perror("setenv failed");
			}
			else
				perror("setenv requires 2 arguments");
		}
		else if (strcmp(command, "unsetenv") == 0)
		{
			if (argv[1])
			{
				if (_unsetenv(argv[1]) == -1)
					fprintf(stderr, "Error: unsetenv failed\n");
			}
			else
				fprintf(stderr, "Error: unsetenv requires one argument\n");
		}
		else
		{
			command = location(argv[0], &m);
			if (com(command, argv, d))
				return;
			execmd(command, argv, envp);
			if (m == 0)
				free(command);
		}
	}

}

/**
* cd_cmd - function that changes working directory
* @argv: array of rguments passed to cd command
*/
void cd_cmd(char **argv)
{
	char *dir = NULL;
	char *home = NULL;
	char *oldpwd = NULL;
	char cwd[PATH_MAX];

	dir = argv[1];
	if (dir == NULL)
	{
		home = getenv("HOME");
		if (home != NULL)
			dir = home;
	}
	else if (strcmp(dir, "-") == 0)
	{
		oldpwd = getenv("OLDPWD");
		if (oldpwd != NULL)
		{
			dir = oldpwd;
			printf("%s\n", dir);
		}
	}

	if (dir != NULL)
	{
		if (chdir(dir) == -1)
			perror("Error: cd failed");
		else
		{
			_setenv("OLDPWD", getenv("PWD"), 1);
			if (getcwd(cwd, sizeof(cwd)) != NULL)
				_setenv("PWD", cwd, 1);
		}
	}
}

