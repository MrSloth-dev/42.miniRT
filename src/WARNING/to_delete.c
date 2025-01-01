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

void	test_inter_cyl_178(t_canvas *canvas)
{
//parse
//cy 1.0,0.0,0.0	0.0,1.0,0.0	2	30	255,255,255
//cy 0.0,0.0,0.0	0.0,1.0,0.0	2	40	255,255,255
//cy 0.0,0.0,-5.0	1.0,1.0,1.0	2	50	255,255,255

//intersect cyl only this to add intersect
//ft_lstadd_sort_inter(lst, 1, shap);
	t_shapes	*_1 = (t_shapes *)canvas->objects->cont;
	t_shapes	*_2 = (t_shapes *)canvas->objects->next->cont;
	t_shapes	*_3 = (t_shapes *)canvas->objects->next->next->cont;

	ft_print_tuple(_1->cyl.coord, "cyl origin");
	ft_print_tuple(_1->cyl.norm, "cyl norm");
	printf("cyl diameter %f\n", _1->cyl.size.diameter);
	printf("cyl height %f\n\n", _1->cyl.size.height);
	ft_print_tuple(_2->cyl.coord, "cyl origin");
	ft_print_tuple(_2->cyl.norm, "cyl norm");
	printf("cyl diameter %f\n", _2->cyl.size.diameter);
	printf("cyl height %f\n\n", _2->cyl.size.height);
	ft_print_tuple(_3->cyl.coord, "cyl origin");
	ft_print_tuple(_3->cyl.norm, "cyl norm");
	printf("cyl diameter %f\n", _3->cyl.size.diameter);
	printf("cyl height %f\n", _3->cyl.size.height);

	t_interlst	*lst;
	t_ray		ray;

	lst = NULL;
	ray = ft_create_ray(_1->cyl.coord, _1->cyl.norm);
	ft_intersection_cyl(&lst, ray, _1);
	ft_print_intersections(lst);

	lst = NULL;
	ray = ft_create_ray(_2->cyl.coord, _2->cyl.norm);
	ft_intersection_cyl(&lst, ray, _2);
	ft_print_intersections(lst);

	lst = NULL;
	ray = ft_create_ray(_3->cyl.coord, _3->cyl.norm);
	ft_intersection_cyl(&lst, ray, _3);
	ft_print_intersections(lst);
}

void	test_inter_cyl_180(t_canvas *canvas)
{
//parse
/*cy 1.0,0.0,-5.0		0.0,0.0,1.0	2	1000	255,255,255*/
/*cy 0.0,0.0,-5.0		0.0,0.0,1.0	2	1000	255,255,255*/
/*cy 0.5,0.0,-5.0		0.1,1.0,1.0	2	1000	255,255,255*/
/**/
	t_shapes	*_1 = (t_shapes *)canvas->objects->cont;
	t_shapes	*_2 = (t_shapes *)canvas->objects->next->cont;
	t_shapes	*_3 = (t_shapes *)canvas->objects->next->next->cont;
	ft_print_tuple(_1->cyl.coord, "cyl origin");
	ft_print_tuple(_1->cyl.norm, "cyl norm");
	printf("cyl diameter %f\n", _1->cyl.size.diameter);
	printf("cyl height %f\n\n", _1->cyl.size.height);
	ft_print_tuple(_2->cyl.coord, "cyl origin");
	ft_print_tuple(_2->cyl.norm, "cyl norm");
	printf("cyl diameter %f\n", _2->cyl.size.diameter);
	printf("cyl height %f\n\n", _2->cyl.size.height);
	ft_print_tuple(_3->cyl.coord, "cyl origin");
	ft_print_tuple(_3->cyl.norm, "cyl norm");
	printf("cyl diameter %f\n", _3->cyl.size.diameter);
	printf("cyl height %f\n", _3->cyl.size.height);
	t_interlst	*lst;
	t_ray		ray;

	lst = NULL;
	ray = ft_create_ray(_1->cyl.coord, _1->cyl.norm);
	ft_intersection_cyl(&lst, ray, _1);
	ft_print_intersections(lst);

	lst = NULL;
	ray = ft_create_ray(_2->cyl.coord, _2->cyl.norm);
	ft_intersection_cyl(&lst, ray, _2);
	ft_print_intersections(lst);

	lst = NULL;
	t_tuple pos = (t_tuple){0.5, 0, -5, 1};
	t_tuple dir = (t_tuple){0.1, 1, 1, 0};
	_3->cyl.coord = pos;
	_3->cyl.norm = ft_norm_vector(dir);
	ray = ft_create_ray(_3->cyl.coord, _3->cyl.norm);
	ft_intersection_cyl(&lst, ray, _3);
	ft_print_intersections(lst);
}

void	test_normal_at_cyl_181(t_canvas *canvas)
{
//parse
	t_shapes	*_1 = (t_shapes *)canvas->objects->cont;
	t_shapes	*_2 = (t_shapes *)canvas->objects->next->cont;
	t_shapes	*_3 = (t_shapes *)canvas->objects->next->next->cont;
	ft_print_tuple(_1->cyl.coord, "cyl origin");
	ft_print_tuple(_1->cyl.norm, "cyl norm");
	printf("cyl diameter %f\n", _1->cyl.size.diameter);
	printf("cyl height %f\n\n", _1->cyl.size.height);
	ft_print_tuple(_2->cyl.coord, "cyl origin");
	ft_print_tuple(_2->cyl.norm, "cyl norm");
	printf("cyl diameter %f\n", _2->cyl.size.diameter);
	printf("cyl height %f\n\n", _2->cyl.size.height);
	ft_print_tuple(_3->cyl.coord, "cyl origin");
	ft_print_tuple(_3->cyl.norm, "cyl norm");
	printf("cyl diameter %f\n", _3->cyl.size.diameter);
	printf("cyl height %f\n", _3->cyl.size.height);

	t_interlst	*lst;
	t_ray		ray;

	lst = NULL;
	ray = ft_create_ray(_1->cyl.coord, _1->cyl.norm);
	ft_intersection_cyl(&lst, ray, _1);
	ft_print_intersections(lst);

	lst = NULL;
	ray = ft_create_ray(_2->cyl.coord, _2->cyl.norm);
	ft_intersection_cyl(&lst, ray, _2);
	ft_print_intersections(lst);

	lst = NULL;
	t_tuple pos = (t_tuple){0.5, 0, -5, 1};
	t_tuple dir = (t_tuple){0.1, 1, 1, 0};
	_3->cyl.coord = pos;
	_3->cyl.norm = ft_norm_vector(dir);
	ray = ft_create_ray(_3->cyl.coord, _3->cyl.norm);
	ft_intersection_cyl(&lst, ray, _3);
	ft_print_intersections(lst);
}

