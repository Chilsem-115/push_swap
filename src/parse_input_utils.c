/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:54:07 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/23 00:58:43 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_exit(char **tokens, char *temp, t_stack **stack)
{
	int	i;

	i = 0;
	if (temp)
		free(temp);
	if (tokens)
	{
		while (tokens[i])
			free(tokens[i++]);
		free(tokens);
	}
	if (stack && *stack)
		panic_exit(2, "Error", *stack, NULL);
	else
		panic_exit(2, "Error", NULL, NULL);
}

static char	*process_argument(char *temp, char *arg, t_stack **stack)
{
	char	*new_temp;
	char	*with_space;

	if (is_valid_token(arg))
		free_exit(NULL, temp, stack);
	with_space = ft_strjoin(temp, " ");
	free(temp);
	if (!with_space)
		free_exit(NULL, NULL, stack);
	new_temp = ft_strjoin(with_space, arg);
	free(with_space);
	if (!new_temp)
		free_exit(NULL, new_temp, stack);
	return (new_temp);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

char	**join_args(int argc, char **argv, t_stack **stack)
{
	char	*temp;
	char	**result;
	int		i;

	temp = ft_strdup(argv[1]);
	if (!temp)
		free_exit(NULL, NULL, stack);
	i = 1;
	while (++i < argc)
		temp = process_argument(temp, argv[i], stack);
	result = ft_split(temp, ' ');
	free(temp);
	if (!result)
		free_exit(NULL, NULL, stack);
	return (result);
}

int	check_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;

	if (!stack || !stack->top || stack->size == 1)
		return (0);
	current = stack->top;
	while (1)
	{
		runner = current->next;
		while (runner != stack->top)
		{
			if (current->num == runner->num)
				return (1);
			runner = runner->next;
		}
		current = current->next;
		if (current == stack->top)
			break ;
	}
	return (0);
}
