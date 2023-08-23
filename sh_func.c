#include "shell.h"

/**
 * main - Entry point
 *
 * Description - let's try to create a little shell
 *
 * @argc: length of gcc
 * @argv: argument to check
 * @evp: arg envirnement
 * Return: 0
*/
int main(int argc, char **argv, char **evp)
{
	int r_bts;
	char *in_buf;
	size_t buf_size;
	(void)argc;
	(void)argv;

	r_bts = 0;
	in_buf = NULL;
	buf_size = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("cisfun$ ");
		}
		r_bts = getline(&in_buf, &buf_size, stdin);
		if (r_bts == EOF)
		{
			_EOF(in_buf);
		}
		else if (*in_buf == '\n' || strspn(in_buf, "\n") == strlen(in_buf))
		{
			continue;
		}
		else
		{
			proc_input(in_buf, evp);
		}
		free(in_buf);
		in_buf = NULL;
	}
	return (0);
}
