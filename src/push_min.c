
#include "../inc/push_swap.h"

static int	find_min_index(t_stack *a)
{
	t_node	*cur;
	int		i;
	int		min;
	int		min_index;

	min_index = 0;
	cur = a->top;
	min = cur->num;
	i = 0;
	while (i < a->size)
	{
		if (cur->num < min)
		{
			min = cur->num;
			min_index = i;
		}
		cur = cur->next;
		i++;
	}
	return (min_index);
}

static void	rotate_to_top(t_stack **a, int index)
{
	int	size;

	size = (*a)->size;
	if (index <= size / 2)
	{
		while (index-- > 0)
			ra(a);
	}
	else
	{
		index = size - index;
		while (index-- > 0)
			rra(a);
	}
}

void	push_min(t_state *state)
{
	int	min_index;

	min_index = find_min_index(state->a);
	rotate_to_top(&state->a, min_index);
	pb(&state->a, &state->b);
}
