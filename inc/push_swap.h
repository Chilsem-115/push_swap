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

typedef struct s_state
{
	t_stack	*a;
	t_stack	*b;
	int		*tokens;
	int		token_count;
}		t_state;

// program initialization and parsing
void	initial_check(t_state *state, int argc, char **argv);
int		*parse_input(int argc, char **argv);
void	fill_stack(t_state *state);

// safety and program exit
void	panic_exit(int fd, const char *msg, t_state *state); 
int		check_dup(int *tokens);
int		validate_tokens(char **tokens);
int		is_sorted(int *tokens);
void	free_stack(t_stack **stack);
void	free_strarr(char **tokens);

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
void	sort_tokens(t_state *state, int size);
void	sort_list(t_state *state);

//---------------//Sorting Utils//-----------------//
int		find_max_index(t_stack *b, int max_val);
int		set_end_value(int len);
void	slide(int *start, int *end, int len);
void	rotate_to_max(t_stack **b, int max_val, int max_index, int middle);
int		get_max(t_stack *b);
int		list_length(t_stack *b);

// extra functions

void	free_dp(char **buffer);
int		ft_issign(int c);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
double	ft_atoi(const char *str);
int	ft_isspace(int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int	ft_isdigit(const int x);
char	**ft_split(const char *s, char c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif
