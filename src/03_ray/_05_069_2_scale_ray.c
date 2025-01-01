#include "minirt.h"

t_ray	ft_scale_ray(t_tuple scaling, t_ray ray)
{
	return ((t_ray){ft_scale(scaling, ray.pos),
		ft_scale(scaling, ray.dir)});
}
