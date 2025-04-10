#include "../inc/push_swap.h"

static t_node	*create_node(int val, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = val;
	node->index = index;
	node->next = node;
	node->prev = node;
	return (node);
}

void	fill_stack(t_state *state)
{
	t_node	*new;
	t_node	*last;
	int		i;

	i = 0;
	while (i < state->token_count)
	{
		new = create_node(state->tokens[i], i);
		if (!new)
			panic_exit(2, "Error: Failed to create node", state);
		if (!state->a->top)
			state->a->top = new;
		else
		{
			last = state->a->top->prev;
			last->next = new;
			new->prev = last;
			new->next = state->a->top;
			state->a->top->prev = new;
		}
		state->a->size++;
		i++;
	}
}
