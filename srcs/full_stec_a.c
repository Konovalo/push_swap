#include "push.h"

int			place_vstavki(t_swap *swap, int content)
{
	t_list	*new;
	int		number;
	int		i;

	new = swap->stec_a;
	number = content;
	i = 2;
	while (new->next)
	{
		if (number > new->content && number < new->next->content)
			return (i);
		new = new->next;
		i++;
	}
	if (number < new->content && number < swap->stec_a->content)
	{
		if (min_list(swap->stec_a) == 1)
			return (1);
		else
			return (max_list(swap->stec_a) + 1);
	}
	if (number > new->content && number > swap->stec_a->content)
		return (max_list(swap->stec_a) + 1);
	return (1);
}

void		mesto_elem(int content, t_swap *swap, t_sd *sd, int k)
{
	int		place;

	if (sd->sdveg_a_up1 == 0 && sd->sdveg_a_down1 == 0)
	{
		sd->element_one = content;
		sd->sdveg_b_down1 = len_stec(swap->stec_b);
		place = place_vstavki(swap, content);
		sd->sdveg_a_up1 = place - 1;
		sd->sdveg_a_down1 = len_stec(swap->stec_a) - place + 1;
		newnew(swap, sd);
	}
	else
	{
		sd->element_two = content;
		sd->sdveg_b_up2 = k - 1;
		sd->sdveg_b_down2 = len_stec(swap->stec_b) - k + 1;
		place = place_vstavki(swap, content);
		sd->sdveg_a_up2 = place - 1;
		sd->sdveg_a_down2 = len_stec(swap->stec_a) - place + 1;
		newnew2(swap, sd);
	}
}

void		full_stec_a(t_swap *swap)
{
	int		k;
	t_sd	sd;
	t_list	*new;

	while (len_stec(swap->stec_b) > 0)
	{
		k = 1;
		new = swap->stec_b;
		init_sd(&sd);
		while (new)
		{
			mesto_elem(new->content, swap, &sd, k);
			new = new->next;
			k++;
		}
		rabota(swap, sd);
		sdvig_pb(&(swap->stec_b), &(swap->stec_a), swap, 4);
	}
}
