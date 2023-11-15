#include "shell.h"

/**
 * main - main function
 * @argc: arguments count
 * @argv: arguments vector
 * @env: enviroments
 * Return: int number
 */

int main(int argc, char *argv[], char **env);
int main(int argc, char *argv[], char **env)
{
	int exit_state;
	char *cmd_line;
	size_t newline_pos;
	size_t n;
	(void)argc;
	(void)argv;

	cmd_line = NULL;
	exit_state = 0;

	while (true)
	{
		if (isatty(0) == 1)
		{
			custom_prompt();
		}
		custom_usercmd(&cmd_line, &n);

		if (strcmp(cmd_line, "exit") == 0)
		{
			break;
		}
		else if (strncmp(cmd_line, "exit ", 5) == 0)
		{
			exit_state = atoi(cmd_line + 5);
			break;
		}
		else if (strcmp(cmd_line, "env") == 0 || strcmp(cmd_line, "printenv") == 0)
		{
			custom_envprint(env);
		}
		custom_executor(cmd_line);

		newline_pos = strcspn(cmd_line, "\n");
		if (newline_pos < n)
		{
			cmd_line[newline_pos] = '\0';
		}
		if (cmd_line != NULL)
		{
			cmd_line = NULL;
		}
	}
	return (exit_state);
}
