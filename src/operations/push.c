/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 09:23:51 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/29 09:29:02 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_node	*node;
	t_node	*last;

	if ((*src)->size == 0)
		return ;
	node = (*src)->top;
	if ((*src)->size == 1)
		(*src)->top = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		(*src)->top = node->next;
	}
	(*src)->size--;
	if ((*dest)->size == 0)
	{
		node->next = node;
		node->prev = node;
		(*dest)->top = node;
	}
	else
	{
		last = (*dest)->top->prev;
		node->next = (*dest)->top;
		node->prev = last;
		last->next = node;
		(*dest)->top->prev = node;
		(*dest)->top = node;
	}
	(*dest)->size++;
}

void	pa(t_stack **a, t_stack **b)
{
	if ((*b)->size > 0)
	{
		push(a, b);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if ((*a)->size > 0)
	{
		push(b, a);
		write(1, "pb\n", 3);
	}
}
