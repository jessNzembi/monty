#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @head: pointer to the top of the stack
 * @count: line number
 * Return: void
 */

void _pint(stack_t **head, unsigned int count)
{
	if (*head)
	{
		printf("%d\n", (*head)->n);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}
}
