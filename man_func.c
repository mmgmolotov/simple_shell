#include "shell.h"
/**
 *_EOF - function
 * Return: void
*/
void _EOF(char *buffer)
{
	if (buffer != NULL)
		free(buffer);
	exit(0);
}
/**
 * proc_input - function that execute a command
 * @input: ptr to input
 * @p_name: ptr to program name
 * Return: void
 */
void proc_input(char *input, char **p_name)
{
	int wwait;
	size_t length = strlen(input);
	pid_t pid = fork();

	input[length - 1] = '\0';
	if (pid == 0)
	{
		char *cmd = strtok(input, " ");
		char arr[2];

		arr[0] = cmd;
		arr[1] = NULL;
		execve(cmd, arr, p_name);
		perror("");
		exit(1);
	}
	else if (pid > 0)
		waitpid(pid, &wwait,0);
	else
		perror("");
}
/**
 * _signal - function declaration
*/
void _signal(int num)
{
	if (num == SIGINT)
}
