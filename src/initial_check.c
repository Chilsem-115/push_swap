
#include "../inc/push_swap.h"

static void	check_argument(char *arg, t_state *state)
{
	int	j;
	int	num_flag;

	j = 0;
	while (arg[j])
	{
		if (num_flag && !ft_isdigit(arg[j]) && !ft_isspace(arg[j]))
			panic_exit(2, "Error", state);
		if (ft_issign(arg[j]))
		{
			if ((j > 0 && !ft_isspace(arg[j - 1]))
				|| !ft_isdigit(arg[j + 1]))
				panic_exit(2, "Error", state);
			num_flag = 1;
		}
		else if (ft_isdigit(arg[j]))
			num_flag = 0;
		else if (!ft_isspace(arg[j]))
			panic_exit(2, "Error", state);
		j++;
	}
}

void	initial_check(t_state *state, int argc, char **argv)
{
	int	i;

	i = 1;
	check_empty(argc, argv, state);
	while (i < argc)
	{
		check_argument(argv[i], state);
		i++;
	}
}
