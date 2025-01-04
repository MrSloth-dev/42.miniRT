#include "minirt.h"

t_light	ft_create_light_a(t_tuple pos, t_color color, float bright) // this must go to the parser
{
	t_light	light;

	light.coord = pos;
	light.color = ft_scalar_tuple(color, bright);
	return (light);
}

t_camera	ft_create_camera_a(t_tuple pos, t_tuple norm, float fov) // this must go to the parser
{
	t_camera	camera;

	camera.coord = pos;
	camera.norm = norm;
	camera.field_v = fov;
	return (camera);
}
