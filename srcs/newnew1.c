#include "push.h"

void	newnew2(t_swap *swap, t_sd *sd)
{
	int	a;
	int	b;
	int	rez;

	a = swap->variant;
	b = swap->otcuda;
	rez = swap->scolko;
	if (newnew3(swap, sd) != 1)
		newnew4(swap, sd);
	if (rez < swap->scolko || (rez == swap->scolko && \
				sd->element_one > sd->element_two))
	{
		swap->variant = a;
		swap->otcuda = b;
		swap->scolko = rez;
	}
	else
	{
		sd->element_one = sd->element_two;
		sd->sdveg_a_down1 = sd->sdveg_a_down2;
		sd->sdveg_a_up1 = sd->sdveg_a_up2;
		sd->sdveg_b_down1 = sd->sdveg_b_down2;
		sd->sdveg_b_up1 = sd->sdveg_b_up2;
	}
}
