#include "../../inc/push_swap.h"

void	free_dp(char **buffer)
{
	int	i;

	if (buffer == NULL)
		return;
	i = 0;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	buffer = NULL;
}
