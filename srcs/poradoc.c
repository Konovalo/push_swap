#include "push.h"

void		poradoc_a(t_swap *swap)
{
	t_list	*new;
	int		max;

	new = swap->stec_a;
	max = max_list(swap->stec_a);
	if (max < len_stec(swap->stec_a) - max)
		sdvig_a_up(max, swap, &swap->stec_a, 6);
	else
		sdvig_a_down(len_stec(swap->stec_a) - max, swap, &(swap->stec_a), 9);
}
