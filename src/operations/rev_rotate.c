#include ""

void	rev_rotate(t_node **head)
{
	t_node	*prev;
	t_node	*last;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	prev = NULL;
	last = *head;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *head;
	*head = last;
}

void	rra(t_node **a)
{
	rev_rotate(a);
	ft_printf("rra");
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	ft_printf("rrb");
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr");
}
