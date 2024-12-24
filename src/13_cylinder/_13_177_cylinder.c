#include "minirt.h"

void	ft_intersection_cyl(t_interlst **lst, t_ray ray, t_shapes *shap)
{
	t_iter	h;
	double	discriminant;

	h.a = (ray.dir.x * ray.dir.x) + (ray.dir.z * ray.dir.z);
	if (h.a < ROUND_ERROR)
		return ;
	h.b = 2 * ray.pos.x * ray.dir.x + 2 * ray.pos.z * ray.dir.z;
	h.c = ray.pos.x * ray.pos.x + ray.pos.z * ray.pos.z - 1;
	discriminant = h.b * h.b - 4 * h.a * h.c;
	if (discriminant < 0)
		return ;
	//ft_lstadd_sort_inter(lst, 1, shap);

	ft_lstadd_sort_inter(lst, ((-h.b - sqrt(discriminant)) / (2 * h.a)), shap);
	ft_lstadd_sort_inter(lst, ((-h.b + sqrt(discriminant)) / (2 * h.a)), shap);

}
