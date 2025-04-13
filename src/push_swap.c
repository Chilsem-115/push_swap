/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:34:54 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/29 10:32:48 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
static void print_tokens(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->token_count)
	{
		ft_printf("%d\n", state->tokens[i]);
		i++;
	}
}
*/

static void	initialize_program(t_state *state)
{
	state->a = malloc(sizeof(t_stack));
	state->b = malloc(sizeof(t_stack));
	if (!state->a || !state->b)
		panic_exit(2, "Error: Allocation failed", state);
	state->a->top = NULL;
	state->a->size = 0;
	state->b->top = NULL;
	state->b->size = 0;
}

int	main(int argc, char **argv)
{
	t_state		*state;

	state = malloc(sizeof(t_state));
	if (!state)
		panic_exit(2, "Error: Failed allocation", NULL);
	initialize_program(state);
	if (argc < 2)
		panic_exit(2, "Error: Not Enough Arguments", state);
	initial_check(state ,argc, argv);
	parse_input(state, argc, argv);
//	print_tokens(state);
	check_dup(state);
	is_sorted(state);
	fill_stack(state);
	sort_list(state);
	panic_exit(1, NULL, state);
}
