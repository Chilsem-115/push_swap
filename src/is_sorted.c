#include "../inc/push_swap.h"

void	is_sorted(t_state *state)
{
	int	i;

	i = 0;
	if (state->token_count < 2)
		panic_exit(1, NULL, state);
	while (i < state->token_count - 1)
	{
		if (state->tokens[i] > state->tokens [i + 1])
			return ;
		i++;
	}
	panic_exit(1, NULL, state);
}
