#include "../../inc/push_swap.h"

static void    *ft_memcpy(void *dst, const void *src, size_t n)
{
        unsigned char           *d;
        const unsigned char     *s;

        if ((dst == src) || n == 0)
                return (dst);
        s = (const unsigned char *)src;
        d = (unsigned char *)dst;
        while (n--)
                *d++ = *s++;
        return (dst);
}

static unsigned int	count_words(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	free_words(char **words, int i)
{
	while (i--)
		free(words[i]);
	free(words);
}

static char	*get_next_word(const char *s, int *start, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[*start] == c)
		(*start)++;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, &s[*start], len);
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char			**words;
	unsigned int	i;
	int				start;

	if (!s)
		return (NULL);
	words = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	start = 0;
	while (i < count_words(s, c))
	{
		words[i] = get_next_word(s, &start, c);
		if (!words[i])
		{
			free_words(words, i);
			return (NULL);
		}
		start += ft_strlen(words[i]);
		i++;
	}
	words[i] = NULL;
	return (words);
}
