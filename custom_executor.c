#include "shell.h"

/**
 * custom_executor - to execute and creates a child process
 * @exec_cmd: command execute
 */

void custom_executor(const char *exec_cmd);
void custom_executor(const char *exec_cmd)
{
	pid_t fork_value;
	char *delimiter = "\n";
	char *token;
	char *token_array[200];
	int count = 0;
	char *env[] = {NULL};

	fork_value = fork();

	if (fork_value == -1)
	{
		perror("fork Error");
		exit(EXIT_FAILURE);
	}
	else if (fork_value == 0)
	{
		token = strtok((char *)exec_cmd, delimiter);

		while (token != NULL)
		{
			token_array[count] = token;
			token = strtok(NULL, delimiter);
			count++;
		}
		token_array[count] = NULL;

		if (strcmp(token_array[0], "clear") == 0)
		{
			if (system("clear") == -1)
			{
				perror("clear");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		if (strchr(token_array[0], '/') != NULL)
		{
			if (execve(token_array[0], token_array, env) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *path_envs = getenv("PATH");
			char *path_cpy = strdup(path_envs);
			char *path_toks = strtok(path_cpy, ":");

			free(path_cpy);
			while (path_toks != NULL)
			{
				char pash[256];

				snprintf(pash, sizeof(pash), "%s/%s", path_toks, token_array[0]);
				if (execve(pash, token_array, env) != -1)
				{
					exit(EXIT_SUCCESS);
				}
				path_toks = strtok(NULL, ":");
			}
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
