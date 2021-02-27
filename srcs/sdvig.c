#include "push.h"

void		sdvig_ab_up11(int a, int b, t_swap *swap)
{
	int		i;
	t_list	*new;

	i = 0;
	if (a < b)
	{
		while (i < (b - a))
		{
			swap->stec_b = sdvig_vverh(swap->stec_b);
			new = ft_lstnew(7, 1);
			ft_lstadd_n(&(swap->rez), new);
			if (swap->flag == 1)
				print_screen(swap, 7);
			i++;
		}
	}
}

void		sdvig_ab_up1(int a, int b, t_swap *swap)
{
	int		i;
	t_list	*new;

	i = 0;
	if (a > b)
		while (i < (a - b))
		{
			swap->stec_a = sdvig_vverh(swap->stec_a);
			new = ft_lstnew(6, 1);
			ft_lstadd_n(&(swap->rez), new);
			if (swap->flag == 1)
				print_screen(swap, 6);
			i++;
		}
	else
		sdvig_ab_up11(a, b, swap);
}

void		sdvig_ab_up(int a, int b, t_swap *swap)
{
	int		i;
	int		kol_min;
	t_list	*new;

	i = 0;
	kol_min = ft_min(a, b);
	while (i < kol_min)
	{
		swap->stec_a = sdvig_vverh(swap->stec_a);
		swap->stec_b = sdvig_vverh(swap->stec_b);
		new = ft_lstnew(8, 1);
		ft_lstadd_n(&(swap->rez), new);
		if (swap->flag == 1)
			print_screen(swap, 8);
		i++;
	}
	sdvig_ab_up1(a, b, swap);
}

void		sdvig_ab_down11(int a, int b, t_swap *swap)
{
	int		i;
	t_list	*new;

	i = 0;
	if (a < b)
		while (i < (b - a))
		{
			swap->stec_b = sdvig_vnis(swap->stec_b);
			new = ft_lstnew(10, 2);
			ft_lstadd_n(&(swap->rez), new);
			if (swap->flag == 1)
				print_screen(swap, 10);
			i++;
		}
}

void		sdvig_ab_down1(int a, int b, t_swap *swap)
{
	int		i;
	t_list	*new;

	i = 0;
	if (a > b)
	{
		while (i < (a - b))
		{
			swap->stec_a = sdvig_vnis(swap->stec_a);
			new = ft_lstnew(9, 1);
			ft_lstadd_n(&(swap->rez), new);
			if (swap->flag == 1)
				print_screen(swap, 9);
			i++;
		}
	}
	else
		sdvig_ab_down11(a, b, swap);
}
