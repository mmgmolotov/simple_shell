#include "shell.h"

/**
 * the_prompt - function prints the prompt $
*/
void the_prompt(void)
{
	printf("#cisfun$");
	fflush(stdout);
}
/**
 * main - Entry point
 *
 * Description - let's try to create a little shell
 *
 * Return: 0
*/
int main(void)
{
	char *input;
	size_t length;
      	ssize_t input_readed; /* bach ncompariw integer m3a mokhtalaf signed */
	int wwait;
	pid_t pid;

	/* fix mixed declarations and code */
	input = NULL;
	length = 0;
	while (1)
	{
		the_prompt();
		input_readed = getline(&input, &length, stdin);
		if (input_readed == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("exit\n"); /* what about that printf is it necessary??*/
			free(input);/*9hrtina b leaks*/
			exit(1);
		}
		input[input_readed - 1] = '\0'; /*bach tms7 new line*/

		pid = fork();
		if (pid == 0)
		{
			char *argument[2];
			argument[0] = input;
			argument[1] = NULL; /* argument raha array*/
			execve(input, argument, NULL);
			perror("execve");
			free(input);
			exit(1); /*bdlt 0 b 1 */
		}
		else if (pid > 0)
		{
			waitpid(pid, &wwait, 0);
		}
		else
			perror("fork down");

		free(input);
		input = NULL;
	}
	free(input); /*added this ; i found a mem leak*/
	return (0);
}
/* READ THE COMMENT 
 * AFTER COMPILING : KATKHDM MS MAKAT3TICH l error d no such file or directory ; after u pull the changes try to fix it if u r free ; send message to know that u r working on it .DONE DONE DONE DONE DONE DONE KHASS NJRBO CHECKERS*/
