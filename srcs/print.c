#include "push.h"

void		print_struct(t_list *stec)
{
	int		k;
	t_list	*steca;

	steca = stec;
	while (steca)
	{
		k = steca->content;
		ft_printf("%d\n", k);
		steca = steca->next;
	}
}

void		print_rez2(int k)
{
	if (k == 6)
		write(1, "ra\n", 3);
	else if (k == 9)
		write(1, "rra\n", 4);
	else if (k == 2)
		write(1, "sb\n", 3);
	else if (k == 3)
		write(1, "ss\n", 3);
	else if (k == 7)
		write(1, "rb\n", 3);
	else if (k == 8)
		write(1, "rr\n", 3);
	else if (k == 10)
		write(1, "rrb\n", 4);
	else if (k == 11)
		write(1, "rrr\n", 4);
}

void		print_rez1(int k)
{
	if (k == 1)
		write(1, "sa\n", 3);
	else if (k == 4)
		write(1, "pa\n", 3);
	else if (k == 5)
		write(1, "pb\n", 3);
	else
		print_rez2(k);
}

void		print_rez(t_swap swap)
{
	int		k;

	while (swap.rez)
	{
		k = swap.rez->content;
		if (swap.flag2 == 1 && swap.rez->next == NULL)
			write(1, RED, 5);
		print_rez1(k);
		swap.rez = swap.rez->next;
	}
}
