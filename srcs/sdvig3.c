#include "push.h"

void		sa(t_list **stec, int len)
{
	t_list	*new;

	if (len >= 2)
	{
		new = (*stec)->next;
		(*stec)->next = (*stec)->next->next;
		new->next = *stec;
		(*stec) = new;
	}
}

void		sdvig_sa(t_swap *swap, int k)
{
	t_list	*new;

	sa(&(swap->stec_a), swap->len_a);
	if (k != 0)
	{
		new = ft_lstnew(1, 1);
		ft_lstadd_n(&(swap->rez), new);
	}
	if (swap->flag == 1)
		print_screen(swap, 1);
}

void		sdvig_sb(t_list **stec, t_swap *swap)
{
	t_list	*new;

	new = (*stec)->next;
	(*stec)->next = (*stec)->next->next;
	new->next = (*stec);
	(*stec) = new;
	new = ft_lstnew(2, 1);
	ft_lstadd_n(&(swap->rez), new);
	if (swap->flag == 1)
		print_screen(swap, 2);
}

void		sdvig_a_up(int kol, t_swap *swap, t_list **stec, int k)
{
	int		i;
	t_list	*new;

	i = 0;
	while (i < kol)
	{
		(*stec) = sdvig_vverh((*stec));
		new = ft_lstnew(k, 1);
		ft_lstadd_n(&(swap->rez), new);
		i++;
		if (swap->flag == 1)
			print_screen(swap, k);
	}
}

void		sdvig_a_down(int kol, t_swap *swap, t_list **stec, int k)
{
	int		i;
	t_list	*new;

	i = 0;
	while (i < kol)
	{
		(*stec) = sdvig_vnis((*stec));
		if (k == 10)
			new = ft_lstnew(k, 2);
		else
			new = ft_lstnew(k, 1);
		ft_lstadd_n(&(swap->rez), new);
		if (swap->flag == 1)
			print_screen(swap, k);
		i++;
	}
}
