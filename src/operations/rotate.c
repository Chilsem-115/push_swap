
#include "../../inc/push_swap.h"

void	ra(t_stack **a) // Rotate stack b: the first element becomes the last.
{
	if ((*a)->size > 1)
	{
		(*a)->top = (*a)->top->next;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b) // Rotate stack b: the first element becomes the last.
{
	if ((*b)->size > 1)
	{
		(*b)->top = (*b)->top->next;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b) // Does ra and rb at the same time
{
	int rotated;

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
