/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:44:09 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/29 10:44:46 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void free_stack(t_stack **stack)
{
	t_node *current;
	t_node *tmp;

	if (!stack || !*stack)
		return;
	current = (*stack)->top;
	while (current && (*stack)->size--)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(*stack);
	*stack = NULL;
}

static t_node	*create_node(int num, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->index = index;
	node->next = node;
	node->prev = node;
	return (node);
}

void	fill_stack(char **tokens, t_stack **stack)
{
	t_node	*new;
	t_node	*last;
	int		i;

	i = -1;
	while (tokens[++i])
	{
		new = create_node(ft_atoi(tokens[i]), 0);
		if (!new)
			panic_exit(2, "Error", *stack, NULL);
		if (!(*stack)->top)
			(*stack)->top = new;
		else
		{
			last = (*stack)->top->prev;
			last->next = new;
			new->prev = last;
			new->next = (*stack)->top;
			(*stack)->top->prev = new;
		}
		(*stack)->size++;
	}
}

int	parse_input(int argc, char **argv, t_stack **stack)
{
	char	**tokens;

	tokens = NULL;
	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else if (argc > 2)
		tokens = join_args(argc, argv + 1, stack);
	if (!tokens || !*tokens)
		panic_exit(2, "Error", *stack, NULL);
	if (validate_all_tokens(tokens))
	{
		free_tokens(tokens);
		panic_exit(2, "Error", *stack, NULL);
	}
	fill_stack(tokens, stack);
	if (check_duplicates(*stack))
	{
		free_tokens(tokens);
		panic_exit(2, "Error", *stack, NULL);
	}
	free_tokens(tokens);
	return (0);
}
