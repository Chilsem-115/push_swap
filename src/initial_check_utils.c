
#include "../inc/push.swap.h"

int	is_valid_char(int c)
{
	return (ft_isdigit(c) || ft_issign(c) || ft_isspace(c));
}

void	check_sign_placement(char *arg, int j, t_state *state)
{
	if (ft_issign(arg[j]) && !(j == 0 || ft_isspace(arg[j - 1])))
		panic_exit(2, "Error", state);
}

void	check_space_placement(char *arg, int j, t_state *state)
{
	if (ft_isspace(arg[j]))
	{
		if (ft_isspace(arg[j + 1]) || (j == 0) || (arg[j + 1] == '\0'))
			panic_exit(2, "Error", state);
		if (!ft_isdigit(arg[j + 1]) && !ft_issign(arg[j + 1]))
			panic_exit(2, "Error", state);
	}
}

void	check_end_of_arg(char *arg, int j, int req_dig, t_state *state)
{
	if (j > 0 && (ft_isspace(arg[j - 1]) || req_dig))
		panic_exit(2, "Error", state);
}

void	check_empty(int argc, char **argv, t_state *state)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			panic_exit(2, "Error", state);
		i++;
	}
}
