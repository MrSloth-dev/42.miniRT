#include "minirt.h"

t_ambient	*ft_init_ambient(int ratio, t_color color)
{
	t_ambient	*new;

	new = (t_ambient *)malloc(sizeof(t_ambient));
	if (new == NULL)
		return (NULL);
	new->ratio = ratio;
	new->color = color;
	return (new);
}

t_camera	*ft_init_camera(t_tuple coord, t_tuple norm, int fov)
{
	t_camera	*new;

	new = (t_camera *)malloc(sizeof(t_camera));
	if (new == NULL)
		return (NULL);
	new->coord = coord;
	new->norm = norm;
	new->fov = fov;
	return (new);
}

t_light	*ft_init_light(t_tuple coord, int bright, t_color color)
{
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
	if (new == NULL)
		return (NULL);
	new->coord = coord;
	new->bright = bright;
	new->color = ft_scalar_tuple(color, bright);
	return (new);
}

t_sphere	*ft_init_sphere(t_tuple coord, int diameter, t_color color)
{
	t_sphere	*new;

	new = (t_sphere *)malloc(sizeof(t_sphere));
	if (new == NULL)
		return (NULL);
	new->coord = coord;
	new->diameter = diameter;
	new->color = color;
	return (new);
}

t_plane	*ft_init_plane(t_tuple coord, t_tuple norm, t_color color)
{
	t_plane	*new;

	new = (t_plane *)malloc(sizeof(t_plane));
	if (new == NULL)
		return (NULL);
	new->coord = coord;
	new->norm = norm;
	new->color = color;
	return (new);
}

t_cylinder	*ft_init_cylinder(t_tuple coord, t_tuple norm,
							t_cyl_size size, t_color color)
{
	t_cylinder	*new;

	new = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (new == NULL)
		return (NULL);
	new->coord = coord;
	new->norm = norm;
	new->size.diameter = size.diameter;
	new->size.height = size.height;
	new->color = color;
	return (new);
}
