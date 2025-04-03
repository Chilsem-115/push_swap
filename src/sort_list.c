/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:00:00 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/29 09:59:50 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pre_sort(t_stack **a, t_stack **b, int len, int *arr)
{
	int	start;
	int	end;

	start = 0;
	end = set_end_value(len);
	while ((*a)->top != NULL)
	{
		if ((*a)->top->num >= arr[start] && (*a)->top->num <= arr[end])
		{
			pb(a, b);
			slide(&start, &end, len);
		}
		else if ((*a)->top->num < arr[start])
		{
			pb(a, b);
			rb(b);
			slide(&start, &end, len);
		}
		else
			ra(a);
	}
}

void	sort_back(t_stack **a, t_stack **b)
{
	int	max_val;
	int	middle;
	int	max_index;

	while ((*b)->top != NULL)
	{
		max_val = get_max(*b);
		middle = ((*b)->size) / 2;
		max_index = find_max_index(*b, max_val);
		if (max_index == -1)
			break ;
		rotate_to_max(b, max_val, max_index, middle);
		pa(a, b);
	}
}

void	sort_list(t_stack **a, t_stack **b)
{
	int	*arr;

	arr = create_sorted_array(*a);
	if (!arr)
		return ;
	pre_sort(a, b, (*a)->size, arr);
	sort_back(a, b);
	free(arr);
}
