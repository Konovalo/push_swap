#include "libft.h"

void		ft_lstadd_n(t_list **alst, t_list *new)
{
	t_list	*add;

	add = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (add->next)
			add = add->next;
		add->next = new;
	}
}
