void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_node **a)
{
	swap(a);
	ft_printf("sa");
}

void	sb(t_node **b)
{
	swap(b);
	ft_printf("sb");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss");
}
