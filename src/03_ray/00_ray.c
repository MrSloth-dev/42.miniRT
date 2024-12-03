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
	t_tuple	sphere_to_ray;
	
	sphere_to_ray = ft_sub_tuple(ray.pos, (t_tuple){0, 0, 0, 1});
	// sphere_to_ray = ft_sub_tuple(ray.pos, shap->sph.coord);
	h.a = ft_dotprod_vector(ray.dir, ray.dir);
	h.b = 2 * ft_dotprod_vector(ray.dir, sphere_to_ray);
	h.d = ft_dotprod_vector(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = (h.b * h.b) - (4 * h.a * h.d);
	// printf("discriminant = %f\n", discriminant);
	// printf("quadratic = %f\n", quadratic);
	if (discriminant < 0)
		printf(RED"Missed discriminant negative\n"RESET);
	else
	{
		// printf("hello from here = %f\n", ((-h.b - sqrt(discriminant)) / (2 * h.a)));
		ft_lstadd_sort_inter(lst, ((-h.b - sqrt(discriminant)) / (2 * h.a)), shap);
		// printf("hello from here = %f\n", ((-h.b + sqrt(discriminant)) / (2 * h.a)));
		ft_lstadd_sort_inter(lst, ((-h.b + sqrt(discriminant)) / (2 * h.a)), shap);
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

t_ray	ft_translate_ray(t_tuple translation, t_ray ray)
{
	return ((t_ray){ft_translate(translation, ray.pos),
		ft_translate(translation, ray.dir)});
}

t_ray	ft_scale_ray(t_tuple scaling, t_ray ray)
{
	return ((t_ray){ft_scale(scaling, ray.pos),
		ft_scale(scaling, ray.dir)});
}

t_ray	ft_set_transf_ray(t_ray ray, t_matrix inverted)
{
	t_ray	temp;

	temp.pos = ft_mult_matrix_tuple(inverted, ray.pos);
	temp.dir = ft_mult_matrix_tuple(inverted, ray.dir);
	return (temp);
}

t_matrix	ft_create_transf_matrix(double x, double y, double z)
{
	t_matrix	temp;

	temp = ft_create_matrix(4, 4, 1);
	temp.data[0][3] = x;
	temp.data[1][3] = y;
	temp.data[2][3] = z;
	return (temp);
}

t_matrix	ft_create_scale_matrix(double x, double y, double z)
{
	t_matrix	temp;

	temp = ft_create_matrix(4, 4, 1);
	temp.data[0][0] = x;
	temp.data[1][1] = y;
	temp.data[2][2] = z;
	return (temp);
}

void ft_get_transf_obj(t_shapes *s, t_tuple coord, t_tuple orientation, double diam)
{
	t_matrix translation;
	t_matrix scale;

	translation = ft_create_transf_matrix(coord.x, coord.y, coord.z);
	scale = ft_create_matrix(4, 4, 1);
	if (s->type != PLANE)
		scale = ft_create_scale_matrix(diam, diam, diam);
	// if (s->type != SPHERE)
	(void)orientation; //rotation rotation rotation
	s->transform = ft_matrix_mult(translation, scale);
	s->transposed = ft_transpose_matrix(s->transform);
	s->inverted = ft_invert_matrix(s->transform);
}
