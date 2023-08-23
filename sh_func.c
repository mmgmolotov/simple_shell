#include "shell.h"

/**
 * the_prompt - function prints the prompt $
*/
void the_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("#cisfun$ ");
		fflush(stdout);
	}
}
/**
 * fork_process - function declaration
 *
 * @my_input: input to check
 * @name: path name
*/
void fork_process(char *input, char *name)
{
	pid_t pid;
	int wwait;

	pid = fork();
	if (pid == 0)
	{
		char *arr[2];

		arr[0] = input;
		arr[1] = NULL;
		execve(input, arr, NULL);
		perror(name);
		exit(1);
	}
	else if (pid > 0)
		waitpid(pid, &wwait, 0);
	else
		perror(name);
}
/**
 * main - Entry point
 *
 * Description - let's try to create a little shell
 *
 * @argc: length of gcc
 * @argv: argument to check
 *
 * Return: 0
*/
int main(int argc, char *argv[])
{
	char *input;

	if (argc != 1)
	{
		perror("usage");
		return (0);
	}
	while (1)
	{
		the_prompt();
		input = r_input();
		if (strlen(input) == 0)
		{
			free(input);
			continue;
		}
		proc_input(input, argv[0]);
		free(input);
	}
	return (0);
}
