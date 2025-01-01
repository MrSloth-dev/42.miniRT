#include "minirt.h"

/*
the hit pointer, will be always the slowest positive value,
because the list is ordered.
*/
t_inter	*ft_hit_inter(t_interlst **lst)
{
	t_interlst	*head;

	head = *lst;
	while (head)
	{
		if (((t_inter *)head->cont)->value > 0)
		{
			return ((t_inter *)head->cont);
		}
		head = head->next;
	}
	return (NULL);
}
