#include "push.h"

int	check_max_min(char *str, int one, int two)
{
	if (str[0] != '-' && ((two - one < 10) || \
	((two - one == 10) && strcmp("2147483648", str) > 0)))
		return (1);
	if (str[0] == '-' && ((two - one < 11) || \
	((two - one == 11) && strcmp("2147483649", &str[1]) > 0)))
		return (1);
	return (-1);
}
