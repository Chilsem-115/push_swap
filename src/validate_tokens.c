/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:54:07 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/23 00:58:43 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_valid_int(const char *str)
{
	long	num;
	size_t	len;

	num = ft_atoi(str);
	len = ft_strlen(str);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	if (len > 11 || (len == 11 && *str != '-' && *str != '+'))
		return (1);
	return (0);
}

static int	is_valid_token(char *str)
{
	int	i;

	if (!str || !*str)
		return (1);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return (1);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (is_valid_int(str));
}

int	validate_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return (1);
	i = 0;
	while (tokens[i])
	{
		if (is_valid_token(tokens[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_dup(t_state state)
{
	int	i;
	int	j;

	if (!state->tokens)
		panic_exit(2, "Error: Invalid tokens", state);
	i = 0;
	while (i < state->token_count)
	{
		j = i + 1;
		while (j < state->token_count)
		{
			if (state->tokens[i] == state->tokens[j])
				panic_exit(2, "Error: Invalid tokens", state);
			j++;
		}
		i++;
	}
	return ;
}
