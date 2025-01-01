#include "minirt.h"

t_interlst	*ft_intersect_world(t_canvas *canvas, t_ray ray)
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
		if (((t_shapes *)temp_o->cont)->type == CYLINDER)
			ft_intersection_cyl(&lst, new_ray, temp_o->cont);
		temp_o = temp_o->next;
	}
	return (lst);
}
