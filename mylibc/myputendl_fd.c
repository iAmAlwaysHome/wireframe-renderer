 

#include "mylibc.h"

void	myputendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	myputstr_fd(s, fd);
	myputchar_fd('\n', fd);
}
