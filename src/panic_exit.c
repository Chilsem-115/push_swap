#include "../inc/push_swap.h"

static void	free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*tmp;
	int		count;

	if (!stack || !*stack)
		return;
	current = (*stack)->top;
	count = (*stack)->size;
	while (current && count > 0)
	{
		tmp = current->next;
		free(current);
		current = tmp;
		count--;
	}
	free(*stack);
	*stack = NULL;
}

void	panic_exit(int fd, const char *msg, t_state *state) 
{
	if (msg)
		ft_dprintf(fd, "%s\n", msg);
	if (state)
	{
		if (state->tokens)
		{
			free(state->tokens);
			state->tokens = NULL;
		}
		if (state->a)
		{
			free_stack(state->a);
			state->a = NULL;
		}
		if (state->b)
		{
			free_stack(state->b);
			state->b = NULL;
		}
		free(state);
	}
	if (fd == 1)
		exit(EXIT_SUCCESS);
	else if (fd == 2)
		exit(EXIT_FAILURE);
}
