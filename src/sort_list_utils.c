/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:00:00 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/23 12:00:00 by itamsama         ###   ########.fr       */
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
		*end = len - 1; // preventing overflow
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

int	list_length(t_stack *b)
{
	t_node	*current;
	t_node	*first;
	int		count;

	if (!b || !b->top)
		return (0);
	count = 0;
	current = b->top;
	first = b->top;
	while (1)
	{
		count++;
		current = current->next;
		if (current == first)
			break ;
	}
	return (count);
}
