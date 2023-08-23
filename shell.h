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

void the_prompt(void);
void fork_process(char *input, char *name);
void proc_input(char *input, char *p_name);
void ex_bi(void);
char *r_input(void);
#endif /* SHELL_H */
