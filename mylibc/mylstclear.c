 
#include "mylibc.h"

void	mylstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst))
		return ;
	if ((*lst)->next)
		mylstclear(&((*lst)->next), del);
	if (del)
		del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
