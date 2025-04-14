
#include "../inc/push_swap.h"

static void	sort_two(t_state *state)
{
	if (state->a->top->num > state->a->top->next->num)
		sa(&state->a);
}

static void	sort_three(t_state *state)
{
	int	first;
	int	second;
	int	third;

	first = state->a->top->num;
	second = state->a->top->next->num;
	third = state->a->top->next->next->num;
	if (first > second && second < third && first < third)
		sa(&state->a);
	else if (first > second && second > third)
	{
		sa(&state->a);
		rra(&state->a);
	}
	else if (first > second && second < third && first > third)
		ra(&state->a);
	else if (first < second && second > third && first < third)
	{
		sa(&state->a);
		ra(&state->a);
	}
	else if (first < second && second > third && first > third)
		rra(&state->a);
}

static void	sort_rest(t_state *state)
{
	while (state->a->size > 3)
		push_min(state);
	sort_three(state);
	while (state->b->size > 0)
		pa(&state->a, &state->b);
}

void	small_sort(t_state *state)
{
	int	size;

	size = state->a->size;
	if (size == 2)
		sort_two(state);
	else if (size == 3)
		sort_three(state);
	else
		sort_rest(state);
}
