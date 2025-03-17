#include "../inc/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;
	node = malloc(sizeof(t_node));
	if (!node)
	{
		ft_dprintf(1, "Error: allocation failed");
		return (NULL);
	}
	node->value = value;
	node-> index = -1;
	node-> next = NULL;
	node-> prev = NULL;
	return (node);
}


