#include "monty.h"

/**
 * _div - divides the 2nd element by the first
 * @head: pointer to the top of the stack
 * @count: line number
 * Return: void
 */

void _div(stack_t **head, unsigned int count)
{
	int div, len = 0;
	stack_t *ptr;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	div = (ptr->next->n) / (ptr->n);
	ptr->next->n = div;
	*head = ptr->next;
	(*head)->prev = NULL;
	free(ptr);
}
