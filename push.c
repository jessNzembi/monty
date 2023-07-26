#include "monty.h"

/**
 * _push - add an element to the top of a stack
 * @head: pointer to the top of the stack
 * @count: line number
 * Return: void
 */

void _push(stack_t **head, unsigned int count)
{
	stack_t *new = malloc(sizeof(stack_t));
	int n = 0;

	if (bus.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}
