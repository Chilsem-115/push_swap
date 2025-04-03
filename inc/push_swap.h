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

# include "../lib/ft_printf/inc/ft_printf.h"
# include <stdlib.h> 
# include <unistd.h> 
# include <stdio.h>
# include <limits.h>

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
size_t	ft_strlen(const char *str);
double	ft_atoi(const char *str);
int		ft_isdigit(const int x);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);

// program initialization and parsing
int		parse_input(int argc, char **argv, t_stack **a);
void	fill_stack(char **tokens, t_stack **stack);
char	**join_args(int argc, char **argv, t_stack **stack);

// safety and program exit
void	panic_exit(int fd, const char *msg, t_stack *a, t_stack *b); 
int		check_duplicates(t_stack *stack);
int		is_valid_int(const char *str);
int		is_valid_token(char *str);
int		validate_all_tokens(char **tokens);
void	free_tokens(char **tokens);

// safety and memory cleanup
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);
//---------------//Operations//-----------------//
// push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

//rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

//rev_roate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//swap
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

//---------------//Sorting//-----------------//
int		*create_sorted_array(t_stack *stack);
void	pre_sort(t_stack **a, t_stack **b, int len, int *arr);
void	sort_back(t_stack **a, t_stack **b);
void	sort_list(t_stack **a, t_stack **b);

//---------------//Sorting Utils//-----------------//
int		find_max_index(t_stack *b, int max_val);
int		set_end_value(int len);
void	slide(int *start, int *end, int len);
void	rotate_to_max(t_stack **b, int max_val, int max_index, int middle);
int		get_max(t_stack *b);
int		list_length(t_stack *b);

#endif
