#include "shell.h"

/**
* _putchar - character to stdout
* @charact: printing
* Return: integer
*/

int custom_putchar(char charact)
{
	return (write(STDOUT_FILENO, &charact, 1));
}
