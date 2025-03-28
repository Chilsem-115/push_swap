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

#include "../inc/push_swap.h"

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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < src_len && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
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
