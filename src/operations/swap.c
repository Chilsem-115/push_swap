/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 09:26:37 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/29 09:27:07 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_stack **stack)
{
	t_node	*first;
	t_node	*second;
	int		temp_num;
	int		temp_index;

	if (!stack || !(*stack) || (*stack)->size < 2)
		return ;
	first = (*stack)->top;
	second = first->next;
	temp_num = first->num;
	temp_index = first->index;
	first->num = second->num;
	first->index = second->index;
	second->num = temp_num;
	second->index = temp_index;
}

void	sa(t_stack **a)
{
	if (!a || !(*a) || (*a)->size < 2)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (!b || !(*b) || (*b)->size < 2)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int	swapped;

	swapped = 0;
	if (a && *a && (*a)->size >= 2)
	{
		swap(a);
		swapped = 1;
	}
	if (b && *b && (*b)->size >= 2)
	{
		swap(b);
		swapped = 1;
	}
	if (swapped)
		write(1, "ss\n", 3);
}
