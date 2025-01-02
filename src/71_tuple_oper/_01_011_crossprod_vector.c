#include "minirt.h"

t_tuple	ft_crossprod_vector(t_tuple a, t_tuple b)
{
	ft_assert(a.w == 0, "a is Not a Vector: crossprod");
	ft_assert(b.w == 0, "b is Not a Vector: crossprod");
	return ((t_tuple){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
		0});
}
