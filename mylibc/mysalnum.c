 
#include "mylibc.h"

int	myisalnum(int c)
{
	return (myisalpha(c) || myisdigit(c));
}
