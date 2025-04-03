/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@studnet.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 09:25:52 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/29 09:30:46 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra(t_stack **a)
{
	if ((*a)->size > 1)
	{
		(*a)->top = (*a)->top->next;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b)
{
	if ((*b)->size > 1)
	{
		(*b)->top = (*b)->top->next;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	int	rotated;

	rotated = 0;
	if ((*a)->size > 1)
	{
		(*a)->top = (*a)->top->next;
		rotated = 1;
	}
	if ((*b)->size > 1)
	{
		(*b)->top = (*b)->top->next;
		rotated = 1;
	}
	if (rotated)
		write(1, "rr\n", 3);
}
