
#include "../inc/push_swap.h"

static void	fill_array(int *arr, t_stack *stack)
{
	t_node	*current;
	int		i;
	int		count;

	if (!arr || !stack || !stack->top)
		return ;
	current = stack->top;
	i = 0;
	count = stack->size;
	while (count > 0)
	{
		arr[i] = current->num;
		i++;
		current = current->next;
		count--;
	}
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*create_sorted_array(t_stack *stack)
{
	int	*arr;

	if (!stack || !stack->top)
		return (NULL);
	arr = malloc(stack->size * sizeof(int));
	if (!arr)
		return (NULL);
	fill_array(arr, stack);
	sort_array(arr, stack->size);
	return (arr);
}
