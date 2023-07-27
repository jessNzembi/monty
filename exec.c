#include "monty.h"

/**
 * execute - executes the opcodes
 * @stack: pointer to head of stack
 * @count: line counter
 * @file: pointer to file containing opcodes
 * @content: content
 * Return: 0 on success, 1 otherwise
 */

int execute(stack_t **stack, unsigned int count, FILE *file, char *content)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		/*{"add", _add},
		{"nop", nop},*/
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (!opcode)
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (instructions[i].opcode)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, count);
			return (0);
		}
		i++;
	}
	fclose(file);
	free(content);
	free_stack(*stack);
	fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
	exit(EXIT_FAILURE);
}
