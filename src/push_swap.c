/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:34:54 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/29 10:32:48 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top || stack->size == 1)
		return (1);
	current = stack->top;
	while (current->next != stack->top)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_input_chars(int argc, char **argv)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (i < argc)
	{
		j = 0;
		s = argv[i];
		while (s[j])
		{
			if (s[j] == '+' || s[j] == '-')
			{
				if (j != 0 && s[j - 1] != ' ')
					return (1);
				if (!ft_isdigit(s[j + 1]))
					return (1);
			}
			else if (!ft_isdigit(s[j]) && s[j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	panic_exit(int fd, const char *msg, t_stack *a, t_stack *b)
{
	if (msg)
		ft_dprintf(fd, "%s\n", msg);
	if (a)
	{
		free_stack(a);
		free(a);
	}
	if (b)
	{
		free_stack(b);
		free(b);
	}
	if (fd == 1)
		exit(EXIT_SUCCESS);
	else if (fd == 2)
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		panic_exit(2, "Error: Not Enough Arguments", NULL, NULL);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		panic_exit(2, "Error: Allocation failed", a, b);
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
	if (check_input_chars(argc, argv))
		panic_exit(2, "Error: Invalid characters", a, b);
	if (parse_input(argc, argv, &a))
		panic_exit(2, "Error: Failed Allocation", a, NULL);
	if (is_sorted(a))
		panic_exit(1, NULL, a, b);
	sort_list(&a, &b);
	panic_exit(1, NULL, a, b);
}
