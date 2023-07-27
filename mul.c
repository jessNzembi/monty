#include "monty.h"

/**
 * _mul - multiplies the top 2 elements of the stack
 * @head: pointer to the top of the stack
 * @count: line number
 * Return: void
 */

void _mul(stack_t **head, unsigned int count)
{
	int prod, len = 0;
	stack_t *ptr;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	prod = (ptr->n) * (ptr->next->n);
	ptr->next->n = prod;
	*head = ptr->next;
	(*head)->prev = NULL;
	free(ptr);
}
