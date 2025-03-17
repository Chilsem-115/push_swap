#include "../inc/push_swap.h"

int	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

    if (!stack)
        return ;
    current = stack->top;
    while (current)
	{
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if(!stack || stack->top)
		return 1;
	current = stack->top;
	while (current->next)
	{
		if(current->num > current->next->num)
			return 0;
		current = current->next;
	}
}

void	initialize_values(t_stack *a, t_stack *b)
{
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		ft_dprintf(2, "Error: no valid argument");
		return (1);
	}
	initialize_values(a, b);
	if (!a || !b)
	{
		perror("Allocation error");
		return EXIT_FAILURE;
	}
	parse_input(argc, argv, a);
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	normalize_stack(a);
	sort_list(a, b);
	free_stack(a);
	free_stack(b);
}
