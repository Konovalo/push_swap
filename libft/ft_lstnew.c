#include "libft.h"

t_list		*ft_lstnew(int content, size_t content_size)
{
	t_list	*newt;

	newt = (t_list*)malloc(sizeof(t_list));
	if (newt)
	{
		newt->content = content;
		newt->content_size = content_size;
		newt->next = NULL;
		return (newt);
	}
	return (NULL);
}
