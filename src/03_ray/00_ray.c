#include "minirt.h"

t_ray	ft_create_ray(t_tuple pos, t_tuple dir)
{
	t_ray	ray;

	ray.pos = pos;
	ray.dir = dir;
	return (ray);
}

t_tuple ft_distance_ray(t_ray ray, double time)
{
	t_tuple final;
	
	return (final = ft_add_tuple(ray.pos,
		ft_scalar_tuple(ray.dir, time)));
}

void	ft_intersection_sphere(t_interlst **lst, t_ray ray, t_shapes *shap)
{
	t_iter	h;
	double	discriminant;
	double	quadratic;
	t_tuple	sphere_to_ray;
	
	sphere_to_ray = ft_sub_tuple(ray.pos, shap->sph.coord);
	h.a = ft_dotprod_vector(ray.dir, ray.dir);
	h.b = 2 * ft_dotprod_vector(ray.dir, sphere_to_ray);
	h.d = ft_dotprod_vector(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = (h.b * h.b) - (4 * h.a * h.d);
	quadratic = ((-h.b - sqrt(discriminant)) / (2 * h.a));
	// printf("discriminant = %f\n", discriminant);
	// printf("quadratic = %f\n", quadratic);

	if (discriminant < 0)
		printf(RED"Missed\n"RESET);
	else
	{
		// printf("hello from here = %f\n", quadratic);
		ft_lstadd_sort_inter(lst, quadratic, shap);
		// printf("hello from here = %f\n", quadratic);
		ft_lstadd_sort_inter(lst, quadratic, shap);
	}
}

t_inter	*ft_hit_inter(t_interlst **lst)
{
	t_interlst	*head;

	head = *lst;
	while(head)
	{
		if (((t_inter *)head->cont)->value > 0)
		{
			printf("value %f\n", ((t_inter *)head->cont)->value);
			printf("diameter %f\n", ((t_inter *)head->cont)->shape->sph.diameter);
			return ((t_inter *)head);
		}
		head = head->next;
	}
	return (NULL);
}
