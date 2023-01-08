 

#include "mylibc.h"

char	*mystrnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!big)
		return (NULL);
	little_len = mystrlen(little);
	if (mystrlen(big) < little_len || len < little_len)
		return (NULL);
	if (!little_len)
		return ((char *) big);
	i = 0;
	while (len && big[i] && i + little_len <= len)
	{
		if (!mystrncmp(&big[i], little, little_len))
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
