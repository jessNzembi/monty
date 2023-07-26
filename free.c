#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: pointer to the top of the stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
