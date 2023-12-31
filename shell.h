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

#define MAXX 1024
void proc_input(char *input, char **p_name);
void _EOF(char *buffer);
void h_sig(int n_sig);
void _signal(int num);
#endif /* SHELL_H */
