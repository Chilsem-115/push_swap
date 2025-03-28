void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	*head = first->next;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	ft_printf("ra");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_printf("rb");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr");
}
