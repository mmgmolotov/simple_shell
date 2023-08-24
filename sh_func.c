#include "shell.h"

/**
 * main - Entry point
 *
 * Description - let's try to create a little shell
 * Return: void
*/
int main(void)
{
	ssize_t r_bts;
	char *in_buf;
	size_t buf_size;

	r_bts = 0;
	in_buf = NULL;
	buf_size = 0;
	signal(SIGINT, h_sig);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("cisfun$ ");
			fflush(stdout);
		}
		r_bts = getline(&in_buf, &buf_size, stdin);
		if (r_bts == -1)
		{
			_EOF(in_buf);
		}
		else if (r_bts == 1 || strspn(in_buf, " \t\n") == (size_t)r_bts || strspn(in_buf, " \t\n") == (((size_t)r_bts - 1)))
		{
			continue;
		}
		else
		{
			proc_input(in_buf, NULL);
		}
	}
	free(in_buf);
	return (0);
}
