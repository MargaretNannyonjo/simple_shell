#include "shell.h"
/**
* custom_printf - stdout char
* @output: printed string
* Return: always an integer
*/
int custom_printf(const char *output)
{
	return (write(STDOUT_FILENO, output, strlen(output)));
}
