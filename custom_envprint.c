#include "shell.h"

/**
 * custom_envprint  - print envs to stdout
 * @environ: environment variables
 */

void custom_envprint(char **environ)
{
	int i;
	char c = '\n';

	for (i = 0; environ[i] != NULL; i++)
	{
		custom_printf(environ[i]);
		custom_putchar(c);
	}
}
