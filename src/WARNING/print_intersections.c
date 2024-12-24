#include "minirt.h"

void	ft_print_intersections(t_interlst *lst)
{
	for (t_interlst *temp = lst; temp; temp = temp->next)
	{
		switch (((t_inter *)temp->cont)->shape->type) {
			case SPHERE: printf(YELLOW"SPHERE "RESET); break;
			case PLANE: printf(YELLOW"PLANE "RESET); break;
			case CYLINDER: printf(YELLOW"cylinder "RESET); break;
			default:printf(YELLOW"NO TYPE???"RESET); break;
		}
		printf("inter value %f\n", ((t_inter *)temp->cont)->value);

	}
	printf("\n");
}
