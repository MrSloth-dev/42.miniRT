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

t_color	ft_lighting_shadow(t_canvas *canvas, t_comp comp)
{
	t_color	ef_color;
	t_color	diffuse;
	t_color	specular;
	t_color	ambient;
	t_tuple	lightv;
	double	reflect_dot_eye;
	double	light_dot_normal;

	ef_color = ft_operator(comp.shape->material.color, '*', canvas->light.color);
	ambient = ft_scalar_tuple(ef_color, comp.shape->material.ambient);
	if (comp.in_shadow == true)
		return (ambient);
	lightv = ft_norm_vector(ft_operator(canvas->light.coord, '-', comp.over_point));
	light_dot_normal = ft_dotprod_vector(lightv, comp.normalv);
	reflect_dot_eye = 0;
	if (light_dot_normal < 0)
	{
		diffuse = (t_color){0, 0, 0, 3};
		specular = (t_color){0, 0, 0, 3};
	}
	else
	{
		diffuse = ft_scalar_tuple(ft_scalar_tuple(ef_color, comp.shape->material.diffuse), light_dot_normal);
		reflect_dot_eye = ft_dotprod_vector(ft_reflect(ft_neg_tuple(lightv), comp.normalv), ft_neg_tuple(canvas->camera.norm));
	}
	if (reflect_dot_eye <= 0)
		specular = (t_color){0, 0, 0, 3};
	else
	{
		double factor = pow(reflect_dot_eye, comp.shape->material.shininess);
		specular = ft_scalar_tuple(canvas->light.intensity, comp.shape->material.specular * factor);
		//ft_print_tuple(specular, "specular");
		//ft_print_tuple(canvas->light.color, "canvas color");
		//exit (1);
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

