#include "shell.h"

/**
 * the_prompt - function prints the prompt $
*/
void the_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("#cisfun$");
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
		char *const argument[2];

		argument[0] = input;
		argument[1] = NULL;
		execve(input, argument, NULL);
		fprintf(stderr, "%s: ", name);
		perror("");
		exit(1);
	}
	else if (pid > 0)
		waitpid(pid, &wwait, 0);
	else
	{
		fprintf(stderr, "%s: ", name);
		perror("");
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
	char *input;
	size_t length;
	ssize_t input_readed; /* bach ncompariw integer m3a mokhtalaf signed */

	input = NULL;
	length = 0;
	while (1)
	{
		the_prompt();
		input_readed = getline(&input, &length, stdin);
		if (input_readed == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("exit\n");/*Mouad:ctrl+D katkteb lik exit f normal shell*/
			free(input);/*9hrtina b leaks*/ /*Mouad: OFC ;)*/
			exit(1);
		}
		input[input_readed - 1] = '\0'; /*bach tms7 new line*/ /*yeah i see it*/

		fork_process(input, argv[0]);

		free(input);
		input = NULL;
	}
	free(input); /*added this ; i found a mem leak*/
	return (0);
}
/*MOUAD: we will work with "argc & argv" to fix*/
/*MOUAD: lets work with functions*/
