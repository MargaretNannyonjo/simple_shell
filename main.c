#include "shell.h"

/**
 * main - function main
 *
 * Return: 0
 */

int main(void)
{
	while (true)
	{
		char *line = NULL;
		size_t n = 0;

		custom_prompt();
		custom_getline(&line, &n);
	}
	return (0);
}
