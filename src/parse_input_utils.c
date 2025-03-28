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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	if (s1)
		ft_strlcpy(str, s1, s1_len + 1);
	if (s2)
		ft_strlcat(str, s2, s1_len + s2_len + 1);
	return (str);
}

int	is_valid_int(const char *str)
{
	long	num;
	size_t	len;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	len = ft_strlen(str);
	if (len > 11)
		return (1);
	return (0);
}

int	is_valid_token(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (1);
		i++;
	}
	if (is_valid_int(str))
		return (1);
	return (0);
}

static void	free_exit(char **tokens, char *temp)
{
	int	i;

	i = 0;
	if (temp)
		free(temp);
	if (tokens)
	{
		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
	panic_exit(2, "Error: Invalid Argument", NULL, NULL);
}

char	**join_args(int argc, char **argv)
{
	char	*temp;
	char	*old_temp;
	char	**ret;
	int		i;

	temp = ft_strdup(argv[1]);
	i = 2;
	while (i < argc)
	{
		old_temp = temp;
		temp = ft_strjoin(temp, " ");
		free(old_temp);
		old_temp = temp;
		if (is_valid_token(argv[i]))
			free_exit(NULL, temp);
		temp = ft_strjoin(temp, argv[i]);
		free(old_temp);
		if (!temp)
			panic_exit(2, "Error: Invalid Argument", NULL, NULL);
		i++;
	}
	ret = ft_split(temp, ' ');
	free(temp);
	return (ret);
}
