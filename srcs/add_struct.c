#include "push.h"

int			proverka(char *str, int one, int two)
{
	if (two - one > 1 && (str[one] == '-' || str[one] == '+') \
	&& ft_isdigit(str[one + 1]) == 1)
		one++;
	while (one < two)
	{
		if (ft_isdigit(str[one]) == 1)
			one++;
		else
			return (-1);
	}
	return (1);
}

int			zap_struct(t_swap *swap, char *str)
{
	int		k;
	t_list	*new;
	t_list	**stecmy;
	t_list	**steca;

	steca = &swap->stec_a;
	stecmy = &swap->stec_my;
	while (*steca)
		steca = &((*steca)->next);
	k = ft_atoi(str);
	if (!(new = ft_lstnew(k, ft_strlen(str))))
		return (-1);
	(*steca) = new;
	if (!(new = ft_lstnew(k, ft_strlen(str))))
		return (-1);
	while (*stecmy)
		stecmy = &((*stecmy)->next);
	(*stecmy) = new;
	return (0);
}

int			prov(t_swap *swap, char *str, int one, int two)
{
	if (str[two] != 0)
		str[two] = '\0';
	if (check_max_min(&str[one], one, two) < 0 || \
			(zap_struct(swap, &str[one]) < 0))
		return (-1);
	return (1);
}

int			zap1_2(char *str, int one, int two, t_swap *swap)
{
	if (one < two)
	{
		if (proverka(str, one, two) < 0 || prov(swap, str, one, two) < 0)
			return (-1);
		swap->cheslo = 1;
	}
	return (1);
}

int			zap1(char *str, t_swap *swap)
{
	int		i;
	int		one;
	int		two;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (len == 0)
		return (-1);
	while (i < len)
	{
		one = i;
		while (str[i] != ' ' && str[i] != '\0' && str[i] != '\t' \
				&& str[i] != '\n' && i < len)
			i++;
		two = i;
		if (zap1_2(&str[one], 0, two - one, swap) < 0)
			return (-1);
		i++;
	}
	if (swap->cheslo == 0)
		return (-1);
	return (1);
}
