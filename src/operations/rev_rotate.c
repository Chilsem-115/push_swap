/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 09:24:59 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/29 09:28:23 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rra(t_stack **a)
{
	if ((*a)->size > 1)
	{
		(*a)->top = (*a)->top->prev;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b)
{
	if ((*b)->size > 1)
	{
		(*b)->top = (*b)->top->prev;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	int	rotated;

	rotated = 0;
	if ((*a)->size > 1)
	{
		(*a)->top = (*a)->top->prev;
		rotated = 1;
	}
	if ((*b)->size > 1)
	{
		(*b)->top = (*b)->top->prev;
		rotated = 1;
	}
	if (rotated)
		write(1, "rrr\n", 4);
}
