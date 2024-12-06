#include "minirt.h"

t_tuple	ft_normal_at_sph(t_shapes *shape, t_tuple w_point)
{
	t_tuple	o_point;
	t_tuple	o_normal;
	t_tuple	w_normal;

	o_point = ft_mult_matrix_tuple(shape->inverted, w_point);
	o_normal = ft_sub_tuple(o_point, (t_tuple){0});
	w_normal = ft_mult_matrix_tuple(ft_transpose_matrix(shape->inverted),
			o_normal);
	w_normal.w = 0;
	return (ft_norm_vector(w_normal));
}

t_tuple	ft_reflect(t_tuple incoming, t_tuple normal)
{
	return (ft_sub_tuple(incoming, ft_scalar_tuple(normal,
				ft_dotprod_vector(incoming, normal) * 2)));
}

t_material ft_create_material(void)
{
	t_material	m;
	m.color = (t_color){1, 1, 1, 3};
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0f;
	return (m);
}

t_light	ft_create_light_a(t_tuple pos, t_color color, float bright) // this must go to the parser
{
	t_light	light;

	light.coord = pos;
	light.color = color;
	light.bright = bright;
	return (light);
}
t_camera	ft_create_camera_a(t_tuple pos, t_tuple norm, float fov) // this must go to the parser
{
	t_camera	camera;

	camera.coord = pos;
	camera.norm = norm;
	camera.fov = fov;
	return (camera);
}
void	ft_material_to_shape(t_material m, t_shapes *shape)
{
	shape->material = m;
	shape->material.ambient = 1;
}

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
	lightv = ft_norm_vector(ft_sub_tuple(light.coord, point));
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
		reflect_dot_eye = ft_dotprod_vector(ft_reflect(ft_neg_tuple(lightv), normal), camera.norm);
	}
	if (reflect_dot_eye <= 0)
		specular = (t_color){0, 0, 0, 3};
	else
	{
		double factor = pow(reflect_dot_eye, m.shininess);

		specular = ft_scalar_tuple(ft_scalar_tuple(light.color, m.specular), factor);

	}
	return (ft_add_tuple(ft_add_tuple(specular, ambient), diffuse));
}
