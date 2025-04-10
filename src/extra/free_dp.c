#include "../../inc/push_swap.h"

void	free_dp(char **buffer)
{
	int	i;

	i = 0;
	if (!buffer || !*buffer)
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	buffer = NULL;
}
