#include "minirt.h"

t_color	ft_color_at(t_canvas *canvas, t_ray ray)
{
	t_color		color;
	t_interlst	*lst;
	t_inter		*hit;
	t_comp		comp;
	t_interlst	*head;

	lst = ft_intersect_world(canvas, ray);
	head = lst;
	hit = ft_hit_inter(&lst);
	if (!hit)
		return (ft_free_objects(head), (t_color){0, 0, 0, 3});
	comp = ft_prepare_comp(hit, ray, canvas);
	color = ft_lighting_shadow(canvas, comp);
	return (ft_free_objects(head), color);
}
