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

	length = 0;
	while (1)
	{
		the_prompt();
		ssize_t input_readed = getline(&input, &length, stdin);
		if (input_readed == -1)
		{
			if (isatty(STDIN_FILENO)
				printf("exit"\n);
			exit(1);
		}
		pid_t pid = fork();
		if (pid == 0)
		{
			char *argument = {input, NULL};
			execve(input, argument, NULL);
			exit(0);
		}
		else if (pid > 0)
		{
			int wwait;
			waitpid(pid, &wwait, 0);
		}
		else
			perror("fork down");
	}
	return (0);
}

