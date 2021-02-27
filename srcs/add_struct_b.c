#include "push.h"

void		push_b(t_swap *swap, int comparison)
{
	if (swap->stec_a->content < comparison)
		sdvig_pb(&(swap->stec_a), &(swap->stec_b), swap, 5);
	else
		sdvig_a_up(1, swap, &swap->stec_a, 6);
}

int			comparison_number(t_swap *swap, int kol)
{
	t_list	*new;
	int		i;

	i = 1;
	new = swap->stec_my;
	while (i < kol)
	{
		new = new->next;
		i++;
	}
	return (new->content);
}

int			add_struct_b(t_swap *swap)
{
	int		kol;
	int		kol1;
	int		comparison;

	kol1 = 0;
	swap->len_a = len_stec(swap->stec_a);
	kol = swap->len_a / 2 + 1;
	while (len_stec(swap->stec_a) > 3)
	{
		kol1 += kol;
		comparison = comparison_number(swap, kol1);
		while (len_stec(swap->stec_b) < kol1 - 1 && len_stec(swap->stec_a) > 3)
			push_b(swap, comparison);
		swap->len_a = len_stec(swap->stec_a);
		kol = swap->len_a / 2;
	}
	return (1);
}
