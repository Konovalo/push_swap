#include "push.h"

void		sort_my(t_swap *swap)
{
	t_list	*new;
	int		one;

	new = swap->stec_my;
	while (new && new->next)
	{
		if (new->content > new->next->content)
		{
			one = new->content;
			new->content = new->next->content;
			new->next->content = one;
			new = swap->stec_my;
		}
		else
			new = new->next;
	}
}
