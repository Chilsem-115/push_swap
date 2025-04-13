#include "../inc/push_swap.h"

static char	*join_args(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	int		i;
	
	joined = ft_strdup(argv[1]);
	if (!joined)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		temp = ft_strjoin(joined, " ");
		free(joined);
		if (!temp)
			return (NULL);
		joined = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!joined)
			return (NULL);
		i++;
	}
	return (joined);
}

static int	*setup_tokens(char **tokens, int count)
{
	int	*result;
	int	i;

	if (tokens == NULL)
		return (NULL);
	result = malloc(count * sizeof(int));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		result[i] = ft_atoi(tokens[i]);
		i++;
	}
	return (result);
}

static int count_elements(char **tokens)
{
	int	count;

	count = 0;
	if (!tokens)
		return (0);
	while (tokens[count])
		count++;
	return (count);
}

static void error_handler(int fd, char *str, t_state *state, char **tokens)
{
	if (tokens)
		free_dp(tokens);
	panic_exit(fd, str, state);
}

void	parse_input(t_state *state, int argc, char **argv)
{
	char	**tokens;
	char	*joined_args;

	joined_args = join_args(argc, argv); 
	if (!joined_args)
		error_handler(2, "Error: Failed Allocation", state, NULL);
	tokens = ft_split(joined_args, ' ');
	free(joined_args);
	if (!tokens || !*tokens)
		error_handler(2, "Error: Failed Allocation", state, tokens);
	state->token_count = count_elements(tokens);
	if (validate_tokens(tokens))
		error_handler(2, "Error: Invalid tokens", state, tokens);
	state->tokens = setup_tokens(tokens, state->token_count);
	if (!state->tokens)
		error_handler(2, "Error: Invalid tokens", state, tokens);
	free_dp(tokens);
}
