#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push1}, {"pall", f_pall1}, {"pint", f_pint1},
				{"pop", f_pop1},
				{"swap", f_swap1},
				{"add", f_add1},
				{"nop", f_nop1},
				{"sub", f_sub1},
				{"mod", f_module},
				{"div", f_div1},
				{"mul", f_mul1},
				{"pchar", f_pchar1},
				{"pstr", f_pstr1},
				{"rotl", f_rotl1},
				{"rotr", f_rotr1},
				{"queue", f_queue1},
				{"stack", f_stack1},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
