# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_node
{
	int		num;
	int		index;
	s_node	next;
	s_node	prev;
}		t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}		t_stack;

// parsing
void	parse_input(int argc, char **argv, t_stack *a);
int		is_valid_number(const char *str);
int		check_duplicates(t_stack *a);

// Operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
