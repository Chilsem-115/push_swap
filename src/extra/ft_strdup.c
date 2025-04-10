
#include "../../inc/push_swap.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	i;

	i = ft_strlen(src) + 1;
	dst = (char *)malloc(i);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, i);
	return (dst);
}
