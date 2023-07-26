#include "monty.h"

/**
 * _pall - prints elements of the stack
 * @head: pointer to stack head
 * @count: line number
 * Return: void
 */

void _pall(stack_t **head, unsigned int count)
{
	stack_t *ptr;
	(void)count;

	ptr = *head;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
