#include "push.h"

int			check_double(t_swap *swap)
{
	t_list	*new;
	t_list	*newnew;
	int		k;
	int		kk;

	newnew = swap->stec_a;
	while (newnew && newnew->next)
	{
		kk = newnew->content;
		new = newnew->next;
		while (new)
		{
			k = new->content;
			if (k == kk)
				return (-1);
			new = new->next;
		}
		newnew = newnew->next;
	}
	return (1);
}
