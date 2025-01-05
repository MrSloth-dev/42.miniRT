#include "minirt.h"

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
