#include "minirt.h"

void	ft_print_tuple(t_tuple tuple, char *name)
{
	printf("%s\n", name);
	printf("x= %f\n",tuple.x);
	printf("y= %f\n",tuple.y);
	printf("z= %f\t", tuple.z );
	if (tuple.w == 0)
		printf("is a Vector\n");
	else if (tuple.w == 1)
		printf("is a Point\n");
	else if (tuple.w == 3)
		printf("is a Color\n\n");
}

