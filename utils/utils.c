#include <stdlib.h>

void	ft_free_stack(t_node *top, t_node *bottom)
{
	t_node	*cur;
	if(!top || !bottom)
		return;
	cur = top;
	while(cur->next)
	{
		cur = cur->next;
		free(cur->previous);
	}
}
