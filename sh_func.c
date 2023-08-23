#include "shell.h"

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
			{
				free(input);
			}
			exit(0);
		}
		input[input_readed - 1] = '\0';
		if (strlen(input) == 0)
		{
			free(input);
			continue;
		}
		fork_process(input, argv[0]);
		free(input);
		input = NULL;
	}
	free(input);
	return (0);
}
