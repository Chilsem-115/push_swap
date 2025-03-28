/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:33:25 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/23 00:07:58 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/printf.h"
# include <stdlib.h> 
# include <unistd.h> 
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN (-2147483648)

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}		t_stack;

// external functions
int		ft_strlen(const char *str);
double	ft_atoi(const char *str);
int		ft_isdigit(const int x);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);

// program initialization and parsing
int		parse_input(int argc, char **argv, t_stack *a);
void	fill_stack(char **tokens, t_stack *stack);
t_node	*create_node(int num, int index);
char	**join_args(int argc, char **argv);

// safety and program exit
void	panic_exit(const char *msg, t_stack **a, t_stack **b, char **tokens);
int		check_input_chars(int argc, char **argv);
int		check_duplicates(t_stack *stack);
int		is_valid_token(const char *str);
int		is_valid_int(const char *str);

// safety and memory cleanup
int		is_sorted(t_stack *stack);
int		free_stack(t_stack *stack);

//---------------//Operations//-----------------//
// push
void	push(t_node **dest, t_node **src);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

//rotate
void	rotate(t_node **head);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

//rroate
void	rev_rotate(t_node **head);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//swap
void	swap(t_node **head);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

#endif
