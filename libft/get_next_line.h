#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>

typedef struct		s_line
{
	int				fd;
	char			*memorized;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
