#include "push.h"

void	rabota2(t_swap *swap, t_sd sd)
{
	if (swap->variant == 3 && swap->otcuda == 2)
	{
		if (sd.sdveg_b_up1 == 1)
			sdvig_sb(&(swap->stec_b), swap);
		else
			sdvig_a_up(sd.sdveg_b_up1, swap, &swap->stec_b, 7);
		sdvig_a_down(sd.sdveg_a_down1, swap, &swap->stec_a, 9);
	}
	else
	{
		if (swap->variant == 4 && swap->otcuda == 2)
			sdvig_ab_down(sd.sdveg_a_down1, sd.sdveg_b_down1, swap);
	}
}

void	rabota1(t_swap *swap, t_sd sd)
{
	if (swap->variant == 4 && swap->otcuda == 1)
	{
		sdvig_ab_down(sd.sdveg_a_down1, sd.sdveg_b_down1, swap);
	}
	else
	{
		if (swap->variant == 1 && swap->otcuda == 2)
		{
			sdvig_a_up(sd.sdveg_a_up1, swap, &swap->stec_a, 6);
			sdvig_a_down(sd.sdveg_b_down1, swap, &swap->stec_b, 10);
		}
		else
		{
			if (swap->variant == 2 && swap->otcuda == 2)
				sdvig_ab_up(sd.sdveg_a_up1, sd.sdveg_b_up1, swap);
			else
				rabota2(swap, sd);
		}
	}
}

void	rabota(t_swap *swap, t_sd sd)
{
	if (swap->variant == 1 && swap->otcuda == 1)
	{
		sdvig_a_up(sd.sdveg_a_up1, swap, &swap->stec_a, 6);
		sdvig_a_down(sd.sdveg_b_down1, swap, &swap->stec_b, 10);
	}
	else
	{
		if (swap->variant == 2 && swap->otcuda == 1)
			sdvig_ab_up(sd.sdveg_a_up1, sd.sdveg_b_up1, swap);
		else
		{
			if (swap->variant == 3 && swap->otcuda == 1)
			{
				if (sd.sdveg_b_up1 == 1)
					sdvig_sb(&(swap->stec_b), swap);
				else
					sdvig_a_up(sd.sdveg_b_up1, swap, &swap->stec_b, 7);
				sdvig_a_down(sd.sdveg_a_down1, swap, &swap->stec_a, 9);
			}
			else
				rabota1(swap, sd);
		}
	}
}
