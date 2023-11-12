#include "simpleshell.h"

/**
 * bring_line - Assign Line Variable for get_line
 * @lineptr: Buffer that Store the Input Str
 * @buffer: Str that is been Called to the Line
 * @n: size of Line
 * @k: size of Buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t k)
{

	if (*lineptr == NULL)
	{
		if  (k > BUFSIZE)
			*n = k;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < k)
	{
		if (k > BUFSIZE)
			*n = k;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - Read Input From Stream
 * @lineptr: Buffer that Stores the Input
 * @n: Size of Lineptr
 * @stream: Stream to be Read From
 * Return: The Numb of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retrival;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	bring_line(lineptr, n, buffer, input);
	retrival = input;
	if (i != 0)
		input = 0;
	return (retrival);
}
