#include "monty.h"

/**
 * _getline - gets the line from the input buffer
 * @lineptr: pointer to the line to be read
 * @n: size of the line to be read
 * @stream: file to be read
 * Return: pointer to the input buffer
*/


ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t i = 0;
	char *new_ptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= (*n - 1))
		{
			*n *= 2;
			new_ptr = (char *)realloc(*lineptr, *n);
			if (new_ptr == NULL)
				return (-1);
			*lineptr = new_ptr;
		}
		(*lineptr)[i++] = (char)c;
		if (c == '\n')
			break;
	}

	(*lineptr)[i] = '\0';

	if (i == 0 && c == EOF)
	{
		free(*lineptr);
		*lineptr = NULL;
		return (-1);
	}
	return (i);
}
