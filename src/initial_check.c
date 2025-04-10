
#include "../inc/push_swap.h"

static void	check_sign(char *arg, int j, t_state *state)
{
	if (j > 0 && !ft_isspace(arg[j - 1]))
		panic_exit(2, "Error", state);
	if (!ft_isdigit(arg[j + 1]))
		panic_exit(2, "Error", state);
}

void		initial_check(t_state *state, int argc, char **argv)
{
	int	i;
	int	j;
	int	num_flag;

	check_empty(argc, argv, state);
	i = 1;
	while (i < argc)
	{
		j = 0;
		num_flag = 0;
		while (argv[i][j])
		{
			if (num_flag && !ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j]))
				panic_exit(2, "Error", state);
			if (ft_issign(argv[i][j]))
			{
				check_sign(argv[i], j, state);
				num_flag = 1;
			}
			else if (ft_isdigit(argv[i][j]))
				num_flag  = 0;
			else if (!ft_isspace(argv[i][j]))
				panic_exit(2, "Error", state);
			j++;
		}
		i++;
	}
}
