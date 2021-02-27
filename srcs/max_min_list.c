#include "push.h"

int			max_list(t_list *stec)
{
	t_list	*new;
	int		max;
	int		nu;
	int		i;

	new = stec;
	max = new->content;
	nu = 1;
	i = 1;
	while (new)
	{
		if (new->content > max)
		{
			nu = i;
			max = new->content;
		}
		i++;
		new = new->next;
	}
	return (nu);
}

int			min_list(t_list *stec)
{
	t_list	*new;
	int		min;
	int		nu;
	int		i;

	new = stec;
	min = new->content;
	nu = 1;
	i = 1;
	while (new)
	{
		if (new->content < min)
		{
			nu = i;
			min = new->content;
		}
		i++;
		new = new->next;
	}
	return (nu);
}

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int			ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
