#include "shell.h"

/**
 * custom_prompt - the current directory prompt
 */

void custom_prompt(void)
{
	char prompt[1024];

	if (getcwd(prompt, sizeof(prompt)) == NULL)
	{
		perror("getcwd fail");
		exit(EXIT_FAILURE);
	}
	custom_printf(prompt);
	custom_printf("$ ");
}
