#include "minirt.h"

t_color	ft_shade_hit(t_canvas *canvas, t_comp comp)
{
	return (ft_lighting(comp.shape->material, comp.point,
			canvas->light, canvas->camera, comp.normalv));
}

t_camera	ft_create_world_camera_old(double h_size, double v_size, double field_v)
{
	t_camera	cam;
	double		aspect;

	cam.h_size = h_size;
	cam.v_size = v_size;
	cam.field_v = field_v;
	cam.transf = ft_create_matrix(4, 4, 1);
	cam.inverted = ft_invert_matrix(cam.transf);
	cam.half_view = tan(cam.field_v / 2);
	aspect = cam.h_size / cam.v_size;
	if (aspect >= 1)
	{
		cam.half_width = cam.half_view;
		cam.half_height = cam.half_view / aspect;
	}
	else
	{
		cam.half_width = cam.half_view * aspect;
		cam.half_height = cam.half_view;
	}
	cam.px_size = (cam.half_width * 2) / cam.h_size;
	return (cam);
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

t_color	OLD_ft_lighting_shadow(t_material m, t_tuple point, t_light light, t_camera camera, t_tuple normal, bool in_shadow)
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
	if (in_shadow)
		return (ambient);
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


