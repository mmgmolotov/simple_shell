#include "shell.h"
/**
 * ex_bi - exit built in function
 * Return: void
 */
void ex_bi(void)
{
	if (isatty(STDIN_FILENO))
		printf("exit\n");
	exit(0);
}
/**
 * exec_cmd - function that execute a command
 * @input: ptr to input
 * @argv0: ptr to argv[0]
 * Return: void
 */
void exec_cmd(char *input, char *argv0)
{
	char *cmd, *arg;

	cmd = strtok(input, " ");
	arg = strtok(NULL, " ");

	if (cmd != NULL)
	{
		if (strcmp(cmd, "exit") == 0)
		{
			ex_bi();
		}
		else
		{
			fork_process(input, argv0);
			if (arg != NULL)
				printf("%s\n", arg);
		}
	}
}
