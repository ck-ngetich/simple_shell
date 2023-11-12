#include "main.h"

/**
 * read_line - Read's the Input Str.
 *
 * @i_eof: Return the Value of getline function
 * Return: Input Str.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
