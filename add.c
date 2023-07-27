#include "monty.h"

/**
 * _add - adds the top 2 elements of the stack
 * @head: pointer to the top of the stack
 * @count: line number
 * Return: void
 */

void _add(stack_t **head, unsigned int count)
{
	int sum, len = 0;
	stack_t *ptr;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	sum = (ptr->n) + (ptr->next->n);
	ptr->next->n = sum;
	*head = ptr->next;
	(*head)->prev = NULL;
	free(ptr);
}
