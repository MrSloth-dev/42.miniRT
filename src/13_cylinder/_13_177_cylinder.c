#include "minirt.h"

static bool	ft_is_a_cyl_cap(t_ray ray, double intersect)
{
	double	x;
	double	z;

	x = ray.pos.x + intersect * ray.dir.x;
	z = ray.pos.z + intersect * ray.dir.z;
	return (x * x + z * z <= 1);
}

static void	ft_intersect_cyl_caps(t_interlst **lst, t_ray ray, t_shapes *shap)
{
	double	inter_one;
	double	inter_two;

	inter_one = (shap->cyl.size.min - ray.pos.y) / ray.dir.y;
	if (ft_is_a_cyl_cap(ray, inter_one))
		ft_lstadd_sort_inter(lst, inter_one, shap);
	inter_two = (shap->cyl.size.max - ray.pos.y) / ray.dir.y;
	if (ft_is_a_cyl_cap(ray, inter_two))
		ft_lstadd_sort_inter(lst, inter_two, shap);
}
//truncate cylinder - page 184
static void	ft_cyl_limits_and_intersect(t_interlst **lst, t_ray ray, t_shapes *shap, t_iter *h)
{
	double	temp;
	double	y_one;
	double	y_two;

	if (h->inter_one > h->inter_two)
	{
		temp = h->inter_one;
		h->inter_one = h->inter_two;
		h->inter_two = temp;
	}
	y_one = ray.pos.y + h->inter_one * ray.dir.y;
	if (shap->cyl.size.min < y_one && y_one < shap->cyl.size.max)
		ft_lstadd_sort_inter(lst, h->inter_one, shap);
	y_two = ray.pos.y + h->inter_two * ray.dir.y;
	if (shap->cyl.size.min < y_two && y_two < shap->cyl.size.max)
		ft_lstadd_sort_inter(lst, h->inter_two, shap);
}

void	ft_intersection_cyl(t_interlst **lst, t_ray ray, t_shapes *shap)
{
	t_iter	h;
	double	discriminant;
	double	sqrt_discriminant;
	double	two_a;

	h.a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	if (!(h.a < ROUND_ERROR && h.a > -ROUND_ERROR))
	{
		while (1)
		{
			h.b = 2 * ray.pos.x * ray.dir.x + 2 * ray.pos.z * ray.dir.z;
			h.cc = ray.pos.x * ray.pos.x + ray.pos.z * ray.pos.z - 1;
			discriminant = h.b * h.b - 4 * h.a * h.cc;
			if (discriminant < 0)
				break ;
			two_a = 2 * h.a;
			sqrt_discriminant = sqrt(discriminant);
			h.inter_one = (-h.b - sqrt_discriminant) / two_a;
			h.inter_two = (-h.b + sqrt_discriminant) / two_a;
			ft_cyl_limits_and_intersect(lst, ray, shap, &h);
			break ;
		}
	}
	ft_intersect_cyl_caps(lst, ray, shap);
}
//ft_lstadd_sort_inter(lst, 1, shap); //for begginer tests on cyl intersection
