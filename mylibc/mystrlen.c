 

#include "mylibc.h"

size_t	mystrlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
