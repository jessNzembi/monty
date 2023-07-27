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

	count += 1;
	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	*head = ptr->next;
	if (ptr->next)
		ptr->next->prev = NULL;
	free(ptr);
}
