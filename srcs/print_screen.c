#include "push.h"

int			razn(t_swap *swap)
{
	int		raz;

	swap->len_a = len_stec(swap->stec_a);
	swap->len_b = len_stec(swap->stec_b);
	if (swap->len_a > swap->len_b)
		raz = swap->len_a - swap->len_b;
	else
		raz = swap->len_b - swap->len_a;
	return (raz);
}

void		print_screen_min(t_swap *swap, t_list *steca, t_list *stecb)
{
	int		min;

	min = ft_min(swap->len_a, swap->len_b);
	while (min > 0)
	{
		ft_printf("%-11d| %d\n", steca->content, stecb->content);
		steca = steca->next;
		stecb = stecb->next;
		min--;
	}
}

void		print_screen2(t_swap *swap, t_list *steca, t_list *stecb, int raz)
{
	while (raz > 0)
	{
		if (swap->len_a > swap->len_b)
		{
			ft_printf("%-11d| \n", steca->content);
			steca = steca->next;
		}
		else
		{
			ft_printf("           | %d\n", stecb->content);
			stecb = stecb->next;
		}
		raz--;
	}
	print_screen_min(swap, steca, stecb);
}

void		print_screen(t_swap *swap, int oper)
{
	int		raz;
	t_list	*steca;
	t_list	*stecb;

	steca = swap->stec_a;
	stecb = swap->stec_b;
	swap->kol_operations++;
	if (swap->kol_operations == len_stec(swap->rez) && \
	sort_true(swap->stec_a) == 1 && len_stec(swap->stec_b) == 0 && \
	swap->flag2 == 1)
		write(1, YELLOW, 5);
	ft_printf("\noperation: ");
	print_rez1(oper);
	ft_printf("stec_a     | stec_b\n\n");
	if (swap->kol_operations == len_stec(swap->rez) && \
	sort_true(swap->stec_a) == 1 && len_stec(swap->stec_b) == 0 && \
	swap->flag2 == 1)
		write(1, RED, 5);
	raz = razn(swap);
	print_screen2(swap, steca, stecb, raz);
}
