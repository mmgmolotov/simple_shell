#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

void proc_input(char *input, char **p_name);
void _EOF(char *beffer);
void _prompt(void);
void _signal(int num);
#endif /* SHELL_H */
