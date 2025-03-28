#include "../../inc/push_swap.h"

void	push(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dest;
	*dest = temp;
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pa");
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	ft_printf("pb");
}
