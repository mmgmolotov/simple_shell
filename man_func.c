#include "shell.h"
/**
 * ex_bi - exit built in function
 * Return: void
 *void ex_bi(void)
{
	if (isatty(STDIN_FILENO))
		printf("exit\n");
	exit(0);
*/
/**
 * proc_input - function that execute a command
 * @input: ptr to input
 * @p_name: ptr to program name
 * Return: void
 */
void proc_input(char *input, char *p_name)
{
	char *cmd, *arg;

	cmd = strtok(input, " ");
	arg = strtok(NULL, " ");

	if (cmd != NULL)
	{
		fork_process(input, p_name);
		if (arg != NULL)
			printf("%s\n", arg);
	}
}
/**
 * r_input - func that read the input
 * Return: void
 */
char *r_input(void)
{
	char *input;
	size_t length;
	ssize_t input_readed;

	input = NULL;
	length = 0;
	input_readed = getline(&input, &length, stdin);
	if (input_readed == -1)
	{
		if (isatty(STDIN_FILENO))
			free(input);
		exit(0);
	}
	input[input_readed - 1] = '\0';
	return (input);
}
