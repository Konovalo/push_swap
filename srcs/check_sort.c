#include "push.h"

int		sort_true(t_list *stec)
{
	int	one;
	int	two;

	if (len_stec(stec) == 1)
		return (1);
	one = stec->content;
	while (stec->next)
	{
		two = stec->next->content;
		if (one > two)
			return (-1);
		one = two;
		stec = stec->next;
	}
	return (1);
}
