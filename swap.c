#include "monty.h"

/**
 * _swap - swaps the top 2 elements
 * @head: pointer to top of the stack
 * @count: line number
 * Return: void
 */

void _swap(stack_t **head, unsigned int count)
{
	int len = 0, temp;
	stack_t *ptr;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}
