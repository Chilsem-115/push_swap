/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:00:00 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/29 10:30:56 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	set_end_value(int len)
{
	if (len > 100)
		return (35);
	else if (len > 5)
		return (len / 6);
	else
		return (len);
}

void	slide(int *start, int *end, int len)
{
	(*start)++;
	(*end)++;
	if (*end >= len)
		*end = len - 1;
}

void	rotate_to_max(t_stack **b, int max_val, int max_index, int middle)
{
	if (max_index == -1)
		return ;
	if (max_index <= middle)
	{
		while ((*b)->top->num != max_val)
			rb(b);
	}
	else
	{
		while ((*b)->top->num != max_val)
			rrb(b);
	}
}

int	get_max(t_stack *b)
{
	t_node	*current;
	t_node	*first;
	int		max;

	if (!b || !b->top)
		return (0);
	current = b->top;
	first = b->top;
	max = current->num;
	while (1)
	{
		if (current->num > max)
			max = current->num;
		current = current->next;
		if (current == first)
			break ;
	}
	return (max);
}

int	find_max_index(t_stack *b, int max_val)
{
	t_node	*current;
	int		index;

	if (!b || !b->top)
		return (-1);
	current = b->top;
	index = 0;
	while (1)
	{
		if (current->num == max_val)
			return (index);
		index++;
		current = current->next;
		if (current == b->top)
			break ;
	}
	return (-1);
}
