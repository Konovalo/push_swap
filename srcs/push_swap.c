#include "push.h"

int			sorte_stec(t_swap *swap)
{
	if (check_double(swap) < 0)
	{
		ft_putendl_fd("Error", 2);
		free_swap(swap);
		return (0);
	}
	if (sort_true(swap->stec_a) == 1)
	{
		free_swap(swap);
		return (0);
	}
	sort_my(swap);
	if (add_struct_b(swap) < 0)
	{
		ft_putendl_fd("Error", 2);
		free_swap(swap);
		return (0);
	}
	swap->stec_a = sort_list_a(swap);
	full_stec_a(swap);
	poradoc_a(swap);
	if (swap->flag == 0)
		print_rez(*swap);
	free_swap(swap);
	return (0);
}

int			valid_flags(t_swap *swap, char **argv, int argc)
{
	int		i;

	i = 1;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		swap->flag = 1;
		i = 2;
	}
	if (argc > 1 && ft_strcmp(argv[1], "-c") == 0)
	{
		swap->flag2 = 1;
		i = 2;
	}
	else
	{
		if (argc > 2 && ft_strcmp(argv[1], "-v") == 0 && \
				ft_strcmp(argv[2], "-c") == 0)
		{
			swap->flag2 = 1;
			i = 3;
		}
	}
	return (i);
}

int			main(int argc, char *argv[])
{
	int		i;
	t_swap	swap;

	if (argc == 1)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	init_struct(&swap);
	i = valid_flags(&swap, argv, argc);
	while (i < argc)
	{
		if (zap1(argv[i], &swap) < 0)
		{
			ft_putendl_fd("Error", 2);
			free_swap(&swap);
			return (0);
		}
		i++;
	}
	return (sorte_stec(&swap));
}
