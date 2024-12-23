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
	temp.normalv = ft_normal_at(temp.shape, temp.point);
	temp.over_point = ft_add_tuple(temp.point, ft_scalar_tuple(temp.normalv, ROUND_ERROR));
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

t_color	ft_shade_hit_shadow(t_canvas *canvas, t_comp comp)
{
	comp.in_shadow = ft_is_shadowed(canvas, comp.over_point);
	return (ft_lighting_shadow(canvas, comp));
}

t_interlst	*ft_inter_world(t_canvas *canvas, t_ray ray)
{
	t_interlst	*lst;
	t_objects	*temp_o;
	t_ray		new_ray;

	lst = NULL;
	temp_o = canvas->objects;
	while (temp_o)
	{
		new_ray = ft_set_transf_ray(ray, ((t_shapes *)temp_o->cont)->inverted);
		if (((t_shapes *)temp_o->cont)->type == SPHERE)
			ft_intersection_sphere(&lst, new_ray, temp_o->cont);
		if (((t_shapes *)temp_o->cont)->type == PLANE)
			ft_intersection_plane(&lst, new_ray, temp_o->cont);
		/* if (((t_shapes *)temp_o->cont)->type == CYLINDER)
			ft_intersection_cyl(&lst, new_ray, temp_o->cont); */
		temp_o = temp_o->next;
	}
	return (lst);
}

t_color	ft_color_at(t_canvas *canvas, t_ray ray)
{
	t_color		color;
	t_interlst	*lst;
	t_inter		*hit;
	t_comp		comp;

	lst = ft_inter_world(canvas, ray);
	hit = ft_hit_inter(&lst);
	if (!hit)
		return (canvas->ambient.color);
	// if (hit && hit->shape->type == SPHERE)
	// 	ft_print_intersections(lst);
	comp = ft_prepare_comp(hit, ray);
	color = ft_shade_hit_shadow(canvas, comp);
	ft_free_objects(lst);
	return (color);
}

t_matrix	ft_view_transformation(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix m;
	t_tuple	forward;
	t_tuple	left;
	t_tuple	true_up;

	m = ft_create_matrix(4, 4, 1);
	forward = ft_norm_vector(ft_sub_tuple(to, from));
	left = ft_crossprod_vector(forward, ft_norm_vector(up));

	true_up = ft_crossprod_vector(left, forward);

	ft_set_matrix_values(&m, (double[4][4])
		{{left.x, left.y, left.z, 0},
		{true_up.x, true_up.y, true_up.z, 0},
		{-forward.x, -forward.y, -forward.z, 0},
		{0, 0, 0, 1}});
	m = ft_matrix_mult(m, ft_translation_matrix(-from.x, -from.y, -from.z));
	return (m);
}
