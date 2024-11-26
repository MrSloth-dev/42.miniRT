#include "minirt.h"

void	ft_print_tuple(t_tuple tuple, char *name)
{
	printf("%s\n", name);
	printf("x= %f\n",tuple.x);
	printf("y= %f\n",tuple.y);
	printf("z= %f\n",tuple.z);
	if (tuple.w == 0)
		printf("is a Vector\n");
	else
		printf("is a Point\n");
}

