#include "push.h"

t_list		*sdvig_vnis(t_list *stec)
{
	t_list	*new;
	t_list	*a;

	new = stec;
	if (len_stec(stec) == 1)
		return (new);
	while (stec->next->next)
		stec = stec->next;
	stec->next->next = new;
	a = stec->next;
	stec->next = NULL;
	return (a);
}

t_list		*sdvig_vverh(t_list *stec)
{
	t_list	*new;
	t_list	*a;

	new = stec->next;
	a = stec;
	if (len_stec(stec) == 1)
		return (a);
	while (stec->next)
		stec = stec->next;
	stec->next = a;
	stec->next->next = NULL;
	return (new);
}

void		pa(t_list **stec_one, t_list **stec_two)
{
	t_list	*new;

	new = (*stec_two)->next;
	(*stec_two)->next = (*stec_one);
	(*stec_one) = (*stec_two);
	(*stec_two) = new;
}

void		sdvig_pb(t_list **stec_one, t_list **stec_two, t_swap *swap, int k)
{
	t_list	*new;

	pa(stec_two, stec_one);
	new = ft_lstnew(k, 1);
	ft_lstadd_n(&(swap->rez), new);
	if (swap->flag == 1)
		print_screen(swap, k);
}

void		sdvig_ab_down(int a, int b, t_swap *swap)
{
	int		i;
	int		kol_min;
	t_list	*new;

	i = 0;
	kol_min = ft_min(a, b);
	while (i < kol_min)
	{
		swap->stec_a = sdvig_vnis(swap->stec_a);
		swap->stec_b = sdvig_vnis(swap->stec_b);
		new = ft_lstnew(11, 2);
		ft_lstadd_n(&(swap->rez), new);
		if (swap->flag == 1)
			print_screen(swap, 11);
		i++;
	}
	sdvig_ab_down1(a, b, swap);
}
