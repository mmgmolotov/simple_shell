#include "shell.h"
/**
 *_EOF - function
 * @buffer: buf
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
	char *cmd;
	size_t length = strlen(input);
	pid_t pid;

	cmd = strtok(input, " ");
	if (length > 0 && input[length - 1] == '\n')
	{
	input[length - 1] = '\0';
	}
	pid = fork();
	if (pid == 0)
	{
		char *arr[2];

		arr[0] = cmd;
		arr[1] = NULL;
		execve(cmd, arr, p_name);
		perror(*p_name);
		exit(0);
	}
	else if (pid > 0)
		waitpid(pid, &wwait, 0);
	else
		perror(*p_name);
}
/**
 * _signal - function declaration
 * @num: number argument
*/
void _signal(int num)
{
	if (num == SIGINT)
	{
	}
}
/**
 * h_sig - func handle signal
 * @n_sig: num sig
*/


void h_sig(int n_sig)
{
	if (n_sig == SIGINT)
	{
		printf("\ncisfun$ ");
		fflush(stdout);
	}
}
