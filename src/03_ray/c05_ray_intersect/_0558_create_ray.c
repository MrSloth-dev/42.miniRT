#include "minirt.h"

t_ray	ft_create_ray(t_tuple pos, t_tuple dir)
{
	t_ray	ray;

	ray.pos = pos;
	ray.dir = dir;
	return (ray);
}
