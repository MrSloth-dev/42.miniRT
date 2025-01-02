#include "minirt.h"

t_ray	ft_translate_ray(t_tuple translation, t_ray ray)
{
	return ((t_ray){ft_translate(translation, ray.pos),
		ft_translate(translation, ray.dir)});
}
