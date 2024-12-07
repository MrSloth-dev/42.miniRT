#include "minirt.h"

t_tuple ft_distance_ray(t_ray ray, double time)
{
	return (ft_add_tuple(ray.pos, ft_scalar_tuple(ray.dir, time)));
}
