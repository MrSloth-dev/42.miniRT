#include "minirt.h"

t_inter	*ft_hit_inter(t_interlst **lst)
{
	t_interlst	*head;

	head = *lst;
	while(head)
	{
		if (((t_inter *)head->cont)->value > 0)
		{
			// printf("value hit = %f\n", ((t_inter *)head->cont)->value);
			// printf("diameter %f\n", ((t_inter *)head->cont)->shape->sph.diameter);
			return ((t_inter *)head->cont);
		}
		head = head->next;
	}
	return (NULL);
}
/*
the hit pointer, will be always the slowest positive value,
because the list is ordered.*/
