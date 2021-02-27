#include "push.h"

void		write_answer(t_swap *swap)
{
	if (len_stec(swap->stec_b) == 0 && sort_true(swap->stec_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int			checker_a(t_swap *swap)
{
	char	*line;

	if (check_double(swap) < 0)
	{
		ft_putendl_fd("Error", 2);
		free_swap(swap);
		return (0);
	}
	swap->len_a = len_stec(swap->stec_a);
	while (get_next_line(0, &line))
	{
		if (treatment_str(line, swap) < 0)
		{
			ft_putendl_fd("Error", 2);
			free(line);
			free_swap(swap);
			return (0);
		}
		free(line);
	}
	write_answer(swap);
	free_swap(swap);
	return (0);
}

int			main(int argc, char *argv[])
{
	int		i;
	t_swap	swap;

	i = 1;
	if (argc == 1)
		return (0);
	else
	{
		init_struct(&swap);
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
		return (checker_a(&swap));
	}
	return (0);
}
