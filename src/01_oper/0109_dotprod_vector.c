#include "minirt.h"

double	ft_dotprod_vector(t_tuple a, t_tuple b)//p10
{
	ft_assert(a.w == 0, "a is Not a Vector: dotprod");
	ft_assert(b.w == 0, "b is Not a Vector: dotprod");
	return (a.x * b.x
		+ a.y * b.y
		+ a.z * b.z
		+ a.w * b.w);
}
