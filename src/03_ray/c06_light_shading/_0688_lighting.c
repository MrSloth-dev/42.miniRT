#include "minirt.h"

t_color	ft_lighting(t_material m, t_tuple point, t_light light, t_camera camera, t_tuple normal)
{
	t_color	ef_color;
	t_color	diffuse;
	t_color	specular;
	t_color	ambient;
	t_tuple	lightv;
	double	reflect_dot_eye;
	double	light_dot_normal;

	ef_color = ft_operator(m.color, '*', light.color);
	lightv = ft_norm_vector(ft_operator(light.coord, '-', point));
	ambient = ft_scalar_tuple(ef_color, m.ambient);
	light_dot_normal = ft_dotprod_vector(lightv, normal);
	reflect_dot_eye = 0;
	if (light_dot_normal < 0)
	{
		diffuse = (t_color){0, 0, 0, 3};
		specular = (t_color){0, 0, 0, 3};
	}
	else
	{
		diffuse = ft_scalar_tuple(ft_scalar_tuple(ef_color, m.diffuse), light_dot_normal);
		reflect_dot_eye = ft_dotprod_vector(ft_reflect(ft_neg_tuple(lightv), normal), ft_neg_tuple(camera.norm));
	}
	if (reflect_dot_eye <= 0)
		specular = (t_color){0, 0, 0, 3};
	else
	{
		double factor = pow(reflect_dot_eye, m.shininess);
		specular = ft_scalar_tuple(light.color, m.specular * factor);
	}
	return (ft_add_tuple(ft_add_tuple(specular, ambient), diffuse));
}
