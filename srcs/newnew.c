#include "push.h"

void	newnew1(t_swap *swap, t_sd *sd)
{
	if (ft_max(sd->sdveg_a_up1, sd->sdveg_b_up1) <= \
			sd->sdveg_a_up1 + sd->sdveg_b_down1 && \
			ft_max(sd->sdveg_a_up1, sd->sdveg_b_up1) <= \
			sd->sdveg_a_down1 + sd->sdveg_b_up1 && \
			ft_max(sd->sdveg_a_up1, sd->sdveg_b_up1) <= \
			ft_max(sd->sdveg_a_down1, sd->sdveg_b_down1))
	{
		swap->variant = 2;
		swap->otcuda = 1;
		swap->scolko = ft_max(sd->sdveg_a_up1, sd->sdveg_b_up1);
	}
	else
	{
		swap->variant = 4;
		swap->otcuda = 1;
		swap->scolko = ft_max(sd->sdveg_a_down1, sd->sdveg_b_down1);
	}
}

void	newnew(t_swap *swap, t_sd *sd)
{
	if (sd->sdveg_a_up1 + sd->sdveg_b_down1 <= \
			ft_max(sd->sdveg_a_up1, sd->sdveg_b_up1) && sd->sdveg_a_up1 + \
			sd->sdveg_b_down1 <= sd->sdveg_a_down1 + sd->sdveg_b_up1 && \
			sd->sdveg_a_up1 + sd->sdveg_b_down1 <= \
			ft_max(sd->sdveg_a_down1, sd->sdveg_b_down1))
	{
		swap->variant = 1;
		swap->otcuda = 1;
		swap->scolko = sd->sdveg_a_up1 + sd->sdveg_b_down1;
	}
	else
	{
		if (sd->sdveg_a_down1 + sd->sdveg_b_up1 <= sd->sdveg_a_up1 + \
				sd->sdveg_b_down1 && sd->sdveg_a_down1 + \
				sd->sdveg_b_up1 <= ft_max(sd->sdveg_a_up1, sd->sdveg_b_up1) \
				&& sd->sdveg_a_down1 + sd->sdveg_b_up1 <= \
				ft_max(sd->sdveg_a_down1, sd->sdveg_b_down1))
		{
			swap->variant = 3;
			swap->otcuda = 1;
			swap->scolko = sd->sdveg_a_down1 + sd->sdveg_b_up1;
		}
		else
			newnew1(swap, sd);
	}
}

void	newnew5(t_swap *swap, t_sd *sd)
{
	if (ft_max(sd->sdveg_a_up2, sd->sdveg_b_up2) <= sd->sdveg_a_up2 + \
			sd->sdveg_b_down2 && ft_max(sd->sdveg_a_up2, sd->sdveg_b_up2) \
			<= sd->sdveg_a_down2 + sd->sdveg_b_up2 && \
			ft_max(sd->sdveg_a_up2, sd->sdveg_b_up2) <= \
			ft_max(sd->sdveg_a_down2, sd->sdveg_b_down2))
	{
		swap->variant = 2;
		swap->otcuda = 2;
		swap->scolko = ft_max(sd->sdveg_a_up2, sd->sdveg_b_up2);
	}
	else
	{
		swap->variant = 4;
		swap->otcuda = 2;
		swap->scolko = ft_max(sd->sdveg_a_down2, sd->sdveg_b_down2);
	}
}

void	newnew4(t_swap *swap, t_sd *sd)
{
	if (sd->sdveg_a_down2 + sd->sdveg_b_up2 <= sd->sdveg_a_up2 + \
			sd->sdveg_b_down2 && sd->sdveg_a_down2 + sd->sdveg_b_up2 <= \
			ft_max(sd->sdveg_a_up2, sd->sdveg_b_up2) && \
			sd->sdveg_a_down2 + sd->sdveg_b_up2 <= \
			ft_max(sd->sdveg_a_down2, sd->sdveg_b_down2))
	{
		swap->variant = 3;
		swap->otcuda = 2;
		swap->scolko = sd->sdveg_a_down2 + sd->sdveg_b_up2;
	}
	else
		newnew5(swap, sd);
}

int		newnew3(t_swap *swap, t_sd *sd)
{
	if (sd->sdveg_a_up2 + sd->sdveg_b_down2 <= \
			ft_max(sd->sdveg_a_up2, sd->sdveg_b_up2) && sd->sdveg_a_up2 + \
			sd->sdveg_b_down2 <= sd->sdveg_a_down2 + sd->sdveg_b_up2 && \
			sd->sdveg_a_up2 + sd->sdveg_b_down2 <= \
			ft_max(sd->sdveg_a_down2, sd->sdveg_b_down2))
	{
		swap->variant = 1;
		swap->otcuda = 2;
		swap->scolko = sd->sdveg_a_up2 + sd->sdveg_b_down2;
		return (1);
	}
	return (0);
}
