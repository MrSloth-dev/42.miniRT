#include "minirt.h"

void	ft_intersection_cyl(t_interlst **lst, t_ray ray, t_shapes *shap)
{
	t_iter	h;
	double	discriminant;
	double	sqrt_discriminant;
	double	two_a;

	h.a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	if (h.a < ROUND_ERROR && h.a > -ROUND_ERROR)
		return ;
	h.b = 2 * ray.pos.x * ray.dir.x + 2 * ray.pos.z * ray.dir.z;
	h.cc = ray.pos.x * ray.pos.x + ray.pos.z * ray.pos.z - 1;
	discriminant = h.b * h.b - 4 * h.a * h.cc;
	if (discriminant < 0)
		return ;
	two_a = 2 * h.a;
	sqrt_discriminant = sqrt(discriminant);
	ft_lstadd_sort_inter(lst, ((-h.b - sqrt_discriminant) / two_a), shap);
	ft_lstadd_sort_inter(lst, ((-h.b + sqrt_discriminant) / two_a), shap);
}
//ft_lstadd_sort_inter(lst, 1, shap); //for begginer tests on cyl intersection
