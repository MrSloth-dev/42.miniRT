#include "minirt.h"

void	ft_tuple_init(t_tuple *tuple, t_point coord, int w)
{
	ft_assert((w == T_POINT || w == T_VECTOR), "Invalid tuple w!\n");
	tuple->w = w;
	tuple->x = coord.x;
	tuple->y = coord.y;
	tuple->z = coord.z;
}
