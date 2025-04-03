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

int	is_valid_int(const char *str)
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

int	is_valid_token(char *str)
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
		if (!ft_isdigit(str[i]))
			return (1);
	return (is_valid_int(str));
}

int	validate_all_tokens(char **tokens)
{
	int	i;
	int	j;
	int	nums[1000];

	if (!tokens || !*tokens)
		return (1);
	i = -1;
	while (tokens[++i] && i < 999)
	{
		if (is_valid_token(tokens[i]))
			return (1);
		nums[i] = ft_atoi(tokens[i]);
		j = -1;
		while (++j < i)
			if (nums[j] == nums[i])
				return (1);
	}
	if (tokens[i])
		return (1);
	return (0);
}
