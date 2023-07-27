#include "monty.h"

/**
 * _pop - removes the top element
 * @head: pointer to the top of the stack
 * @count: line number
 * Return: void
 */

void _pop(stack_t **head, unsigned int count)
{
	stack_t *ptr;

	ptr = *head;
	if (!ptr)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}
	*head = ptr->next;
	if (ptr->next)
		ptr->next->prev = NULL;
	free(ptr);
}
