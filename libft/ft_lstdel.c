#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(int, size_t))
{
	t_list	*new;

	new = *alst;
	while (new && del)
	{
		ft_lstdelone(alst, del);
		new = new->next;
		*alst = new;
	}
}
