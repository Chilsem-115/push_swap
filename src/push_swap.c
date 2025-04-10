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

static void print_tokens(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->token_count)
	{
		ft_printf("%d\n", state.tokens[i]);
		i++;
	}
}

static void	initialize_stacks(t_state *state)
{
	state = malloc(sizeof(t_state));
	state->a = malloc(sizeof(t_stack));
	state->b = malloc(sizeof(t_stack));
	if (!a || !b)
		panic_exit(2, "Error: Allocation failed", state);
	state->a->top = NULL;
	state->a->size = 0;
	state->b->top = NULL;
	state->b->size = 0;
}

int	main(int argc, char **argv)
{
	t_state		*state;

	initialize_program(state);
	if (argc < 2)
		panic_exit(2, "Error: Not Enough Arguments", state);
	initial_check(state ,argc, argv);
	parse_input(state, argc, argv); // to make an array of integers
	print_tokens(state); 			// to make sure its correct
	check_dup(state); 				// to exit when a duplicate is found
	is_sorted(state) 				// to exit if the input is already sorted
	fill_stack(state); 				// to fill in the arguments into stack a
	sort_list(state, state.tokens); // sorting the list
	panic_exit(1, NULL, state); 	// to free state before exiting the program
}
