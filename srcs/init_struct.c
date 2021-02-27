#include "push.h"

void		init_struct(t_swap *swap)
{
	swap->stec_a = NULL;
	swap->stec_b = NULL;
	swap->stec_my = NULL;
	swap->rez = NULL;
	swap->kol = 0;
	swap->len_a = 0;
	swap->len_b = 0;
	swap->flag = 0;
	swap->flag2 = 0;
	swap->kol_operations = 0;
	swap->cheslo = 0;
}

void		init_sd(t_sd *sd)
{
	sd->element_one = 0;
	sd->element_two = 0;
	sd->sdveg_a_up1 = 0;
	sd->sdveg_a_down1 = 0;
	sd->sdveg_a_up2 = 0;
	sd->sdveg_a_down2 = 0;
	sd->sdveg = 0;
	sd->sdveg_b_up1 = 0;
	sd->sdveg_b_down1 = 0;
	sd->sdveg_b_up2 = 0;
	sd->sdveg_b_down2 = 0;
}

int			len_stec(t_list *stec)
{
	int		i;

	i = 0;
	while (stec)
	{
		i++;
		stec = stec->next;
	}
	return (i);
}

void		free_stec(t_list *stec)
{
	t_list	*new;
	t_list	*new2;

	new = stec;
	while (new)
	{
		new2 = new->next;
		free(new);
		new = new2;
	}
}

void		free_swap(t_swap *swap)
{
	free_stec(swap->stec_a);
	free_stec(swap->stec_b);
	free_stec(swap->stec_my);
	free_stec(swap->rez);
}
