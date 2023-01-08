 

#include "mylibc.h"

static char	**count_words(char const *s, char c)
{
	size_t	i;
	size_t	w_am;
	char	**split;

	i = 0;
	w_am = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] && s[i] != '\n')
			w_am++;
		while (s[i] != c && s[i])
			i++;
	}
	split = (char **)malloc(sizeof(char *) * (w_am + 1));
	return (split);
}

static char	**myfree(char	**split, size_t i)
{
	while (0 < i)
	{
		i--;
		free(split[i]);
		split[i] = NULL;
	}
	free(split);
	split = NULL;
	myputendl_fd("Malloc Error\n", 2);
	exit(1);
	return (split);
}

static char	**mystrsplit(char	**split, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		while ((*s == c || *s == '\n') && *s)
			s++;
		len = 0;
		while ((*s != c) && (*s) && (*s != '\n'))
		{
			s++;
			len++;
		}
		if (len != 0)
		{	
			split[i] = mysubstr(s - len, 0, len);
			if (!split[i])
				return (myfree(split, i));
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}

char	**mysplit(char const *s, char c)
{
	char	**strsplit;

	if (!s)
		return (NULL);
	strsplit = count_words(s, c);
	if (!strsplit)
	{
		myputendl_fd("Malloc Error\n", 2);
		exit(1);
	}
	return (mystrsplit(strsplit, s, c));
}
