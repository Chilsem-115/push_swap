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

#include "push_swap.h"

int	find_max_index(t_stack *b, int max_val)
{
	t_node	*current;
	int		index;

	index = 0;
	current = b->top;
	while (current)
	{
		if (current->num == max_val)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

void	pre_sort(t_stack *a, t_stack *b, int len, int *arr)
{
	int	start;
	int	end;

	start = 0;
	end = set_end_value(len, end);
	while (a->top != NULL)
	{
		if (a->top->num >= arr[start] && a->top->num <= arr[end])
		{
			pb(a, b);
			slide(&start, &end, len);
		}
		else if (a->top->num < arr[start])
		{
			pb(a, b);
			rb(&b->top);
			slide(&start, &end, len);
		}
		else
			ra(&a->top);
	}
}

void	sort_back(t_stack *a, t_stack *b)
{
	int	max_val;
	int	middle;
	int	max_index;
	int	len_b;

	len_b = list_length(b);
	while (b->top != NULL)
	{
		max_val = get_max(b);
		middle = len_b / 2;
		max_index = find_max_index(b, max_val);
		rotate_to_max(b, max_val, max_index, middle);
		pa(a, b);
		len_b--;
	}
}

void	sort_list(t_stack *a, t_stack *b, int len, int *arr)
{
	pre_sort(a, b, len, arr);
	sort_back(a, b);
}
