#include "../../inc/push_swap.h"

static void	push(t_stack **dest, t_stack **src) // pushes a node from src to dest
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

void	pa(t_stack **a, t_stack **b) // push the top element of stack b to stack a.
{
	if ((*b)->size > 0)
	{
		push(a, b);
		write(1, "pa\n", 3);
	}
}


void	pb(t_stack **a, t_stack **b) // push the top element of stack a to stack b.
{
	if ((*a)->size > 0)
	{
		push(b, a);
		write(1, "pb\n", 3);
	}
}
