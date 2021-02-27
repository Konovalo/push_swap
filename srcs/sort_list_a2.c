#include "push.h"

void		zap_sort(t_swap *swap, int *k, int *kk, int *kkk)
{
	*k = swap->stec_a->content;
	*kk = swap->stec_a->next->content;
	*kkk = swap->stec_a->next->next->content;
}

void		sort_list_a3(t_swap *swap, int *k, int *kk, int *kkk)
{
	t_list	*new;

	if (k > kk && kk < kkk && k > kkk)
	{
		swap->stec_a = sdvig_vverh(swap->stec_a);
		swap->kol++;
		new = ft_lstnew(6, 1);
		ft_lstadd_n(&(swap->rez), new);
		if (swap->flag == 1)
			print_screen(swap, 6);
	}
	zap_sort(swap, k, kk, kkk);
	if (k < kk && kk > kkk && k > kkk)
	{
		swap->stec_a = sdvig_vnis(swap->stec_a);
		swap->kol++;
		new = ft_lstnew(9, 1);
		ft_lstadd_n(&(swap->rez), new);
		if (swap->flag == 1)
			print_screen(swap, 9);
	}
}

t_list		*sort_list_a2(t_swap *swap)
{
	if (swap->stec_a->content > swap->stec_a->next->content)
		sdvig_sa(swap, 1);
	return (swap->stec_a);
}

t_list		*sort_list_a(t_swap *swap)
{
	t_list	*new;
	int		k;
	int		kk;
	int		kkk;

	if (len_stec(swap->stec_a) == 2)
		return (sort_list_a2(swap));
	zap_sort(swap, &k, &kk, &kkk);
	if ((k < kk && kk > kkk && kkk > k) || \
			(k > kk && kk < kkk && k < kkk) || \
			(k > kk && k > kkk && kkk < kk))
	{
		new = swap->stec_a->next;
		swap->stec_a->next = swap->stec_a->next->next;
		new->next = swap->stec_a;
		swap->stec_a = new;
		swap->kol++;
		new = ft_lstnew(1, 1);
		ft_lstadd_n(&(swap->rez), new);
		if (swap->flag == 1)
			print_screen(swap, 1);
	}
	zap_sort(swap, &k, &kk, &kkk);
	sort_list_a3(swap, &k, &kk, &kkk);
	return (swap->stec_a);
}
