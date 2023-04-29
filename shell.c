#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 10
#define MAX_ARG_LENGTH 256

char** parse_path() {
    char* path_str = getenv("PATH");
    char* path = strtok(path_str, ":");
    char** path_dirs = malloc(sizeof(char*));
    int path_count = 0;
    while (path != NULL) {
        path_dirs[path_count++] = path;
        path_dirs = realloc(path_dirs, (path_count + 1) * sizeof(char*));
        path = strtok(NULL, ":");
    }
    path_dirs[path_count] = NULL;
    return path_dirs;
}

void print_env() {
	extern char **environ;
    char** env = environ;
    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
}

int check_command_exists(char* command, char** path_dirs) {
	int i;
    char command_path[MAX_ARG_LENGTH];
    for (i = 0; path_dirs[i] != NULL; i++) {
        sprintf(command_path, "%s/%s", path_dirs[i], command);
        if (access(command_path, X_OK) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char command[MAX_ARG_LENGTH];
/*   char arg[MAX_ARG_LENGTH];*/
    char* args[MAX_ARGS + 1];
    pid_t pid;
    int status;
    int arg_count;

    char** path_dirs = parse_path();

    while (1) {
        printf("$ ");
        fgets(command, MAX_ARG_LENGTH, stdin);
        if (feof(stdin)) {
            exit(0);
        }
        arg_count = 0;
        args[arg_count++] = strtok(command, " \n");
        while ((args[arg_count] = strtok(NULL, " \n")) != NULL) {
            arg_count++;
        }
        args[arg_count] = NULL;
        if (arg_count == 0) {
            continue;
        }
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }
        if (strcmp(args[0], "env") == 0) {
            print_env();
            continue;
        }
        if (check_command_exists(args[0], path_dirs) == 0) {
            printf("Command not found: %s\n", args[0]);
            continue;
        }
        if ((pid = fork()) == -1) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
            /* child process */
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            /* parent process */
            if (wait(&status) == -1) {
                perror("wait");
                exit(1);
            }
        }
    }
}

