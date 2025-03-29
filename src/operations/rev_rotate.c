#include "../../inc/push_swap.h"

void	rra(t_stack **a) //Reverse rotate stack a: the last element becomes the top.
{
	if ((*a)->size > 1)
	{
		(*a)->top = (*a)->top->prev;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b) // Reverse rotate stack b: the last element becomes the top.
{
	if ((*b)->size > 1)
	{
		(*b)->top = (*b)->top->prev;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b) // Reverse rotate both stacks.
{
	int rotated;

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
