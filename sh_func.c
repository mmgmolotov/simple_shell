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
void fork_process(char *my_input, char *name)
{
	pid_t pid;
	int wwait;

	pid = fork();
	if (pid == 0)
	{
		char *arr[2];

		arr[0] = my_input;
		arr[1] = NULL;
		execve(my_input, arr, NULL);
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
 * @user_input: user input
 * @com: command to execute
 * @argu: argumment added
 * @argv: number of commands
*/
void command_arg(char *user_input, char *com, char *argu, char argv[])
{
	com = strtok(user_input, " ");
	argu = strtok(NULL, " ");

	if (com != NULL)
	{
		fork_process(user_input, &argv[0]);
		if (argu != NULL)
			printf("%s\n", argu);
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
	char *input, **command, **argument;

	size_t length;
	ssize_t input_readed;

	(void)(argc);

	input = NULL;
	*command = NULL;
	*argument = NULL;
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
		command_arg(input, *command, *argument, argv[0]);
		free(input);
		input = NULL;
	}
	free(command);
	free(argument);
	return (0);
}
