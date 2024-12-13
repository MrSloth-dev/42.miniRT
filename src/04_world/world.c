#include "minirt.h"

/**
 * @brief this function makes this
 *
 * @param hit intersection
 * @param ray origin ray
 * @return struct that is needed for computation
 */
t_comp	ft_prepare_comp(t_inter *hit, t_ray ray)
{
	t_comp	temp;

	temp.value = hit->value;
	temp.shape = hit->shape;
	temp.eyev = ft_neg_tuple(ray.dir);
	temp.point = ft_distance_ray(ray, temp.value);
	temp.normalv = ft_normal_at_sph(temp.shape, temp.point);
	if (ft_dotprod_vector(temp.normalv, temp.eyev) < 0)
	{
		temp.inside = true;
		temp.normalv = ft_neg_tuple(temp.normalv);
	}
	else
		temp.inside = false;
	return (temp);
}

t_color	ft_shade_hit(t_canvas *canvas, t_comp comp)
{
	return (ft_lighting(comp.shape->material, comp.point,
			canvas->light, canvas->camera, comp.normalv));
}
