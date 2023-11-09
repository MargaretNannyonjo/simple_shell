#include "shell.h"
/**
* _printf - stdout char
* @string: printed string
* Return: always an integer
*/
int _printf(const char *output)
{
	return (write(STDOUT_FILENO, output, strlen(output)));
}
