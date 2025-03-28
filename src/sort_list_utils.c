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

int	set_end_value(int len, int end)
{
	if (len > 5 && len <= 100)
		end = len / 6;
	else
		end = 35;
	return (end);
}

void	slide(int *start, int *end, int len)
{
	(*start)++;
	(*end)++;
	if (*end >= len)
		*end = len - 1;
}


void	rotate_to_max(t_stack *b, int max_val, int max_index, int middle)
{
	if (max_index <= middle)
	{
		while (b->top->num != max_val)
			rb(&b->top);
	}
	else
	{
		while (b->top->num != max_val)
			rrb(b);
	}
}

int	get_max(t_stack *b)
{
	t_node	*current;
	int		max;

	if (!b || !b->top)
		return (0);
	current = b->top;
	max = current->num;
	while (current)
	{
		if (current->num > max)
			max = current->num;
		current = current->next;
	}
	return (max);
}

int	list_length(t_stack *b)
{
	t_node	*current;
	int		count;

	count = 0;
	current = b->top;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
