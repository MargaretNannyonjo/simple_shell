#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>

int custom_printf(const char *output);
void custom_prompt(void);
ssize_t custom_getline(char **buff, size_t *size);
void custom_usercmd(char **command, size_t *size);
void custom_envprint(char **environ);
int custom_putchar(char charact);
void custom_executor(const char *exec_cmd);

#endif
