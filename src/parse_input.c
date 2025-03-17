#include "../inc/push_swap.h"

void	parse_input(int argc, char **argv, t_stack *a)
{
	char 	**tokens;
	int		i;

	**tokens = NULL;
	i = 0;
	a->top = NULL;
	a->size = 0;
	if (argc = 2)
		tokens = ft_split(argv[1], ' ');
	else if (argc > 2)
		tokens = &argv[1];
	if (!tokens || tokens[0])
	{
		ft_fprintf(stderr, "Error: No valid input provided\n");
		exit(EXIT_FAILURE);
	}
	while (tokens[i])
	{
	}
}
