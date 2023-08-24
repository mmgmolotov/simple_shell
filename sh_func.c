#include "shell.h"
/**
 * _prompt - function print the prompt
*/
void _prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "#cisfun$ ", 9);
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
int main(int argc, char **argv)
{
	char *input;
	char **env;
	size_t length;
	ssize_t input_readed;
	(void)(argc);
	(void)(argv);

	input = NULL;
	length = 0;
	while (1)
	{
		_prompt();
		signal(SIGINT, _signal);
		input_readed = getline(&input, &length, stdin);
		input[input_readed - 1] = '\0';
		if (input_readed == -1)
			_EOF(input);
		else if (strspn(input, " \t\r\n") == strlen(input))
			continue;
		else
			proc_input(input, env);
		free(input);
		input = NULL;
	}
	free(input);
	return (0);
}
