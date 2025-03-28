/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:44:09 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/23 00:58:15 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*create_node(int num, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	fill_stack(char **tokens, t_stack *stack)
{
	int		i;
	int		num;
	t_node	*new_node;
	t_node	*last;

	i = 0;
	while (tokens[i])
	{
		num = ft_atoi(tokens[i]);
		new_node = create_node(num, 0);
		if (!new_node)
			panic_exit(2, "Error: Failed Allocation", stack, NULL);
		if (!stack->top)
			stack->top = new_node;
		else
		{
			last = stack->top;
			while (last->next)
				last = last->next;
			last->next = new_node;
			new_node->prev = last;
		}
		stack->size++;
		i++;
	}
}

int	check_duplicate(t_node *head)
{
	t_node	*current;
	t_node	*runner;

	current = head;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->num == runner->num)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	parse_input(int argc, char **argv, t_stack *stack)
{
	char	**tokens;
	int		i;

	tokens = NULL;
	i = 0;
	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		if (argv[1])
			tokens = join_args(argc, argv);
		else
			panic_exit(2, "Error: Invalid Argument", stack, NULL);
	}
	if (tokens)
	fill_stack(tokens, stack);
	if (check_duplicate(stack->top))
		panic_exit(2, "Error: Invalid Argument", stack, NULL);
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
	return (0);
}
