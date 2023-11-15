#include "shell.h"

/**
 * custom_getline - reads input from user
 * @buff: where the input is been stored
 * @size: size of buff read
 * Return: an integer
 */

ssize_t custom_getline(char **buff, size_t *size)
{
	static char stat_buff[1024];

	ssize_t num_read;

	*buff = NULL;
	*buff = stat_buff;

	*size = sizeof(stat_buff) / sizeof(char);

	num_read = read(0, *buff, *size);

	if (num_read == -1)
	{
		perror("Error");

		exit(EXIT_FAILURE);
	}
	else if (num_read == 0)
	{
		if (isatty(0))
			custom_printf("\n");
		exit(EXIT_SUCCESS);
	}
	return (num_read);
}
