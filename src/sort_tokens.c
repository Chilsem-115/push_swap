
#include "../inc/push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_tokens(t_state *state)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < state->token_count - 1)
	{
		swapped = 0;
		j = 0;
		while (j < state->token_count - i - 1)
		{
			if (state->tokens[j] > state->tokens[j + 1])
			{
				swap_int(&state->tokens[j], &state->tokens[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}
