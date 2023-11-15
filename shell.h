#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>

int custom_printf(const char *output);
ssize_t custom_getline(char **buff, size_t *size);

#endif
