#include "minirt.h"

void	ft_intersection_sphere(t_interlst **lst, t_ray ray, t_shapes *shap)
{
	t_iter	h;
	double	discriminant;
	t_tuple	sphere_to_ray;
	
	sphere_to_ray = ft_sub_tuple(ray.pos, (t_tuple){0, 0, 0, 1});
	h.a = ft_dotprod_vector(ray.dir, ray.dir);
	h.b = 2 * ft_dotprod_vector(ray.dir, sphere_to_ray);
	h.d = ft_dotprod_vector(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = (h.b * h.b) - (4 * h.a * h.d);
	if (discriminant < 0)
		return ;
	else
	{
		ft_lstadd_sort_inter(lst, ((-h.b - sqrt(discriminant)) / (2 * h.a)), shap);
		ft_lstadd_sort_inter(lst, ((-h.b + sqrt(discriminant)) / (2 * h.a)), shap);
	}
}
