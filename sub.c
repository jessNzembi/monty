#include "monty.h"

/**
 * _sub - subtracts the top element from the second top
 * @head: pointer to the top of the stack
 * @count: line number
 * Return: void
 */

void _sub(stack_t **head, unsigned int count)
{
	int dif, len = 0;
	stack_t *ptr;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	dif = (ptr->next->n) - (ptr->n);
	ptr->next->n = dif;
	*head = ptr->next;
	(*head)->prev = NULL;
	free(ptr);
}
