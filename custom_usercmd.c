#include "shell.h"

/**
 * custom_usercmd - entered by user
 * @command: parsed command
 * @size: command read
 */

void custom_usercmd(char **command, size_t *size)
{
	ssize_t read_command;

	read_command = custom_getline(command, size);

	if (read_command == -1)
	{
		if (*command == NULL)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (feof(stdin))
		{
			custom_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	if ((*command)[read_command - 1] == '\n')
	{
		(*command)[read_command - 1] = '\0';
		*size = strlen(*command);
	}
}
