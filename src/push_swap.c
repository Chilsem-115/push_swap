/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:34:54 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/23 00:00:14 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack *stack)
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
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
}

int	check_input_chars(int argc, char **argv)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	while (i < argc)
	{
		j = 0;
		s = argv[i];
		while (s[j])
		{
			if (s[j] != ' ' && !ft_isdigit(s[j]) && s[j] != '+' && s[j] != '-')
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
	if (a->top)
		free_stack(a);
	if (b->top)
		free_stack(b);
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
	{
		ft_dprintf(2, "Error: Not Enough Arguments");
		return (1);
	}
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	if (check_input_chars(int argc, char **argv))
	{
		ft_dprintf(2, "Error: Invalid argument");
		return (1);
	}
	if (parse_input(argc, argv, &a))
		panic_exit(2, "Error: Failed Allocation", a, NULL);
	if (is_sorted(a))
		panic_exit(1, NULL, &a, &b);
	sort_list(a, b);
	panic_exit(1, NULL, &a, &b);
}
