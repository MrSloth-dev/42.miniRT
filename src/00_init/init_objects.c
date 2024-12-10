#include "minirt.h"

t_ambient	ft_init_ambient(int ratio, t_color color)
{
	t_ambient	new;

	new.ratio = ratio;
	new.color = color;
	return (new);
}

t_camera	ft_init_camera(t_tuple coord, t_tuple norm, int fov)
{
	t_camera	new;

	new.coord = coord;
	new.norm = norm;
	new.fov = fov;
	return (new);
}

t_light	ft_init_light(t_tuple coord, int bright, t_color color)
{
	t_light	new;

	new.coord = coord;
	new.color = ft_scalar_tuple(color, bright);
	return (new);
}

t_sphere	ft_init_sphere(t_tuple coord, int diameter)
{
	t_sphere	new;

	new.coord = coord;
	new.diameter = diameter;
	return (new);
}

t_plane	ft_init_plane(t_tuple coord, t_tuple norm)
{
	t_plane	new;

	new.coord = coord;
	new.norm = norm;
	return (new);
}

t_cylinder	ft_init_cylinder(t_tuple coord, t_tuple norm,
							t_cyl_size size)
{
	t_cylinder	new;

	new.coord = coord;
	new.norm = norm;
	new.size.diameter = size.diameter;
	new.size.height = size.height;
	return (new);
}
