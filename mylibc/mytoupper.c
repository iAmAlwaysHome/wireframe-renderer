 
#include "mylibc.h"

int	mytoupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
