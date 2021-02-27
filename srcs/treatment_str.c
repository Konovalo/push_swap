#include "push.h"

int	treatment_str5(char *line, t_swap *swap)
{
	if (ft_strcmp(line, "rrr") == 0)
	{
		if (len_stec(swap->stec_a) > 0 && len_stec(swap->stec_b) > 0)
		{
			swap->stec_a = sdvig_vnis(swap->stec_a);
			swap->stec_b = sdvig_vnis(swap->stec_b);
		}
		return (1);
	}
	return (-1);
}

int	treatment_str4(char *line, t_swap *swap)
{
	if (ft_strcmp(line, "rr") == 0)
	{
		if (len_stec(swap->stec_a) > 0 && len_stec(swap->stec_b) > 0)
		{
			swap->stec_a = sdvig_vverh(swap->stec_a);
			swap->stec_b = sdvig_vverh(swap->stec_b);
		}
	}
	else
	{
		if (ft_strcmp(line, "rra") == 0)
		{
			if (len_stec(swap->stec_a) > 0)
				swap->stec_a = sdvig_vnis(swap->stec_a);
			return (1);
		}
		if (ft_strcmp(line, "rrb") == 0)
		{
			if (len_stec(swap->stec_b) > 0)
				swap->stec_b = sdvig_vnis(swap->stec_b);
			return (1);
		}
		return (treatment_str5(line, swap));
	}
	return (1);
}

int	treatment_str3(char *line, t_swap *swap)
{
	if (ft_strcmp(line, "ra") == 0)
	{
		if (len_stec(swap->stec_a) > 0)
			swap->stec_a = sdvig_vverh(swap->stec_a);
	}
	else
	{
		if (ft_strcmp(line, "rb") == 0)
		{
			if (len_stec(swap->stec_b) > 0)
				swap->stec_b = sdvig_vverh(swap->stec_b);
			return (1);
		}
		return (treatment_str4(line, swap));
	}
	return (1);
}

int	treatment_str2(char *line, t_swap *swap)
{
	if (ft_strcmp(line, "pa") == 0)
	{
		if (len_stec(swap->stec_b) > 0)
			pa(&swap->stec_a, &swap->stec_b);
		return (1);
	}
	else
	{
		if (ft_strcmp(line, "pb") == 0)
		{
			if (len_stec(swap->stec_a) > 0)
				pa(&swap->stec_b, &swap->stec_a);
			return (1);
		}
		else
			return (treatment_str3(line, swap));
	}
	return (1);
}

int	treatment_str(char *line, t_swap *swap)
{
	if (ft_strcmp(line, "sa") == 0)
	{
		sa(&swap->stec_a, len_stec(swap->stec_a));
		return (1);
	}
	if (ft_strcmp(line, "sb") == 0)
	{
		sa(&swap->stec_b, len_stec(swap->stec_b));
		return (1);
	}
	if (ft_strcmp(line, "ss") == 0)
	{
		if (len_stec(swap->stec_a) > 1 && len_stec(swap->stec_b) > 1)
		{
			sa(&swap->stec_a, len_stec(swap->stec_a));
			sa(&swap->stec_b, len_stec(swap->stec_b));
		}
		return (1);
	}
	else
		return (treatment_str2(line, swap));
}
