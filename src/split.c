#include <downy.h>

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (i > 0 && s[i - 1] == c && s[i] != c)
				words++;
			else if (i == 0 && s[i] != c)
				words++;
			i++;
		}
	}
	return (words);
}

static void	free_array(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

static void	check_word(char const *s, char c, size_t *i, size_t *j)
{
	while (s[*i] && s[*i] == c)
		*i += 1;
	*j = *i;
	while (s[*i] && s[*i] != c)
		*i += 1;
}

static char	*substr(char const *str, unsigned int start, size_t len)
{
	char		*sub;
	size_t	i;

	if (start >= strlen(str))
		len = 0;
	else if (len > strlen(str + start))
		len = strlen(str + start);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = str[i + start];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}

char	**split(char const *str, char sep)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char		**arr;

	arr = (char **)malloc((count_words(str, sep) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (k < count_words(str, sep))
	{
		check_word(str, sep, &i, &j);
		arr[k] = substr(str, j, i - j);
		if (!arr[k])
		{
			free_array(arr, k);
			return (NULL);
		}
		k++;
	}
	arr[k] = NULL;
	return (arr);
}