/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:03:45 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/23 00:18:50 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

double	ft_atoi(const char *str)
{
	double	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * sign);
}

int	ft_isdigit(const int x)
{
	if (x >= '0' && x <= '9' )
		return (1);
	return (0);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	i;

	i = ft_strlen(src) + 1;
	dst = (char *)malloc(i);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, i);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	return (str);
}
