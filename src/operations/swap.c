
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

void	sa(t_stack **a) // swaps the first 2 elements of stack a
{
	if (!a || !(*a) || (*a)->size < 2)
		return ;
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b) // swaps the first 2 elements of stack b
{
	if (!b || !(*b) || (*b)->size < 2)
		return ;
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b) // do both sa and sb
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
		ft_putstr_fd("ss\n", 1);
}
