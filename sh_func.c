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
 * @input: input to check
 * @name: path name
*/
void fork_process(char *input, char *name)
{
	pid_t pid;
	int wwait;

	pid = fork();
	if (pid == 0)
	{
		char *arr[2];/*we don't use const arass taro (fixed) */

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
 * command_arg - function declaration
 *
 * @input: user input
 * @command: command to execute
 * @argument: argumment added
 * @argv: number of commands
*/
void command_arg(char *input, char *command, char *argument, char argv[])
{
	command = strtok(input, " ");
	argument = strtok(NULL, " ");

	if (command != NULL)
	{
		fork_process(input, &argv[0]);
		if (argument != NULL)
			printf("%s\n", argument);
	}
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
	(void)(argc);

	char *input;
	char *command;
	char *argument;
	size_t length;
	ssize_t input_readed;

	input = NULL;
	length = 0;
	if (argc != 1)
	{
		perror("usage");
		return (0);
	}
	while (1)
	{
		the_prompt();
		input_readed = getline(&input, &length, stdin);
		if (input_readed == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("exit\n");
			free(input);
			exit(0);
		}
		input[input_readed - 1] = '\0';
		if (strlen(input) == 0)
		{
			free(input);
			continue;
		}
		command_arg(input, command, argument, argv[0]);
		free(input);
		input = NULL;
	}
	free(input);
	return (0);
}
