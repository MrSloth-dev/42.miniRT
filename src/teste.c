/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:46:04 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/23 10:54:59 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#include "teste_done.c"
#include <math.h>

void	test_inter_world(t_canvas *canvas, char *argv[])
{
	t_interlst	*lst;
	if (ft_parse(canvas, argv[1]) == 0)
		return ;
	t_ray	ray = ft_create_ray((t_tuple) {0,0,-5, 1}, (t_tuple) {0,0,1,0});
	((t_shapes *)canvas->objects->cont)->material.diffuse = 0.7;
	((t_shapes *)canvas->objects->cont)->material.specular = 0.2;
	lst  = ft_inter_world(canvas, ray);
	for (t_interlst *temp = lst; temp; temp = temp->next)
		printf("inter value %f\n", ((t_inter *)temp->cont)->value);
	ft_free_objects(lst);
}

void	test_shade(t_canvas *canvas)
{
	t_interlst	*lst;
	lst = NULL;
	t_ray	ray = ft_create_ray((t_tuple) {0,0,0, 1}, (t_tuple) {0,0,1,0});
	ft_intersection_sphere(&lst, ray, canvas->objects->cont);
	t_inter	*hit = ft_hit_inter(&lst);
	t_comp	temp = ft_prepare_comp(hit, ray);
	t_color	c = ft_shade_hit(canvas, temp);
	ft_print_tuple(c, "color");
	ft_free_objects(lst);
}

void	test_color_at(t_canvas *canvas)
{
	((t_shapes *)canvas->objects->cont)->material.diffuse = 0.7;
	((t_shapes *)canvas->objects->cont)->material.specular = 0.2;
	t_ray	ray = ft_create_ray((t_tuple) {0, 0, -5, 1},
			(t_tuple){0, 0, 1, 0});
	ft_print_tuple(ft_color_at(canvas, ray), "color at");
}

void	test_color_at_mult(t_canvas *canvas)
{
	t_shapes *outer = ((t_shapes *)canvas->objects->cont);
	t_shapes *inner = ((t_shapes *)canvas->objects->next->cont);

	outer->material.ambient = 1;
	inner->material.ambient = 1;

	printf("inner dia %f\n", inner->sph.diameter);
	printf("outer dia %f\n", outer->sph.diameter);
	t_ray	ray = ft_create_ray((t_tuple) {0, 0, 0.75, 1},
		(t_tuple) {0, 0, -1, 0});
	ft_print_tuple(ft_color_at(canvas, ray), "color at");
}

void	test_viewtransform()
{
	printf("\ntest 1\n");
	t_tuple from = {0, 0, 0, 1};
	t_tuple to = {0, 0, -1, 1};
	t_tuple up = {0, 1, 0, 0};
	ft_print_matrix(ft_view_transformation(from, to, up));
	printf("\ntest 2\n");
	from = (t_tuple){0, 0, 0, 1};
	to = (t_tuple){0, 0, 1, 1};
	up = (t_tuple){0, 1, 0, 0};
	ft_print_matrix(ft_view_transformation(from, to, up));
	printf("\ntest 3\n");
	from = (t_tuple){0, 0, 8, 1};
	to = (t_tuple){0, 0, 0, 1};
	up = (t_tuple){0, 1, 0, 0};
	ft_print_matrix(ft_view_transformation(from, to, up));
	printf("\ntest 4\n");
	from = (t_tuple){1, 3, 2, 1};
	to = (t_tuple){4, -2, 8, 1};
	up = (t_tuple){1, 1, 0, 0};
	ft_print_matrix(ft_view_transformation(from, to, up));
}

void	test_camera()
{
	t_camera	cam;
	t_ray		ray;

	printf("test creation camera\n");
	cam = ft_create_world_camera(200, 125, M_PI / 2);
	printf("cam 200, 125, pi/2 -> px_size 0.01? check %f\n", cam.px_size);
	cam = ft_create_world_camera(125, 200, M_PI / 2);
	printf("cam 200, 125, pi/2 -> px_size 0.01? check %f\n", cam.px_size);

	printf("\ntest ray_for_pixel\n");
	cam = ft_create_world_camera(201, 101, M_PI / 2);

	ray = ft_ray_for_pixel(cam, 100, 50);
	printf("\nConstructing a ray through the CENTER of the canvas\n");
	ft_print_tuple(ray.pos, "ray.pos (origin)\n0, 0, 0 ?");
	ft_print_tuple(ray.dir, "ray.direction\n0, 0, -1 ?");

	printf("\nConstructing a ray through a CORNER of the canvas\n");
	ray = ft_ray_for_pixel(cam, 0, 0);
	ft_print_tuple(ray.pos, "ray.pos (origin)\n0, 0, 0?");
	ft_print_tuple(ray.dir, "ray.direction \n0.66519, 0.33259, -0,66851?");  

	printf("\nConstructing a ray when the camera is transformed\n"); 
	t_matrix rotated = ft_rotate_matrix_y(M_PI / 4);
	t_matrix translated = ft_translation_matrix(0, -2, 5);
	cam.transf = ft_matrix_mult(rotated, translated);
	cam.inverted = ft_invert_matrix(cam.transf);
	ray = ft_ray_for_pixel(cam, 100, 50);
	ft_print_tuple(ray.pos, "ray.pos (origin)\n0\t\t2\t\t-5  ?????");
	printf("ray.direction 0.707106781, 0, -0.707106781?\n");
	ft_print_tuple(ray.dir, "ray.direction sqrt(2) / 2, 0, sqrt(2) / 2 ?????");
}

void	test_render(t_canvas *canvas)
{
	// needs this on parse
	//A 1.0		0,0,0
	//L -10,10.0,-10.0		0.1		255,255,255
	// sp 0.0,0,0.0			1.0		204,255,153
	((t_shapes *)canvas->objects->cont)->material.color = (t_color){0.8, 1.0, 0.6, 3};
	((t_shapes *)canvas->objects->cont)->material.diffuse = 0.7;
	((t_shapes *)canvas->objects->cont)->material.specular = 0.9;
	t_camera cam = ft_create_world_camera(IMG_W, IMG_H, M_PI / 4);
	t_tuple	from = {0, 0, -5, 1};
	t_tuple	to = {0, 0, 0, 1};
	t_tuple	up = {0, 1, 0, 0};
	cam.norm = (t_tuple){0, 0, 1, 1};
	cam.transf = ft_view_transformation(from, to, up);
	cam.inverted = ft_invert_matrix(cam.transf);
	cam.fov = 30 * M_PI / 180;
	ft_render(canvas, cam);
}

void	test_mlx_start(t_canvas *canvas)
{
	ft_setup(canvas);
	mlx_hook(canvas->win, DestroyNotify, 0l, &close_handler, &canvas);
}

void	test_mlx_end(t_canvas *canvas)
{
	mlx_loop(canvas->mlx);
	ft_free_canvas(canvas);
}




void	ft_start_rays(t_canvas *canvas, t_shapes shape);
void	test_draw_ball_light(t_canvas *canvas)
{
	t_shapes	shape;
	shape.type = SPHERE;
	shape.sph.coord = (t_tuple){0, 0, 0, 1};
	shape.sph.diameter = 1;
	shape.material = ft_create_material();
	shape.material.color = (t_color){1, 0.2, 1, 1};
	shape.material.shininess = 100;
	shape.material.specular = 0.9;
	shape.material.diffuse = 0.9;
	shape.material.ambient = 0.1;
	t_tuple point;
	 ft_tuple_init(&point, (t_point){0,0,0}, T_POINT);
	ft_get_transf_obj(&shape, point, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	ft_start_rays(canvas, shape);
}
void	ft_start_rays(t_canvas *canvas, t_shapes shape)
{
	double	wall_z = 10;
	double	wall_size = 7.0;
	double	pixel_size = wall_size / IMG_W;
	double	half = wall_size / 2;

	double 	world_y;
	double 	world_x;
	t_tuple position;
	t_tuple normal;
	t_ray 	ray;
	t_tuple dir;
	t_camera  camera = ft_create_camera_a((t_tuple){0 , 0, -25, 1}, (t_tuple){0, 0, 0, 0}, 70);
	t_light	light = ft_create_light_a((t_tuple){-10 , 10, -10, 1}, (t_color){1, 1, 1, 3}, 10);
	ray.pos = camera.coord;
	int x_step;
	int y_step;
	ft_refreshframe(canvas);
	for(int y = 0; y < IMG_H; y += STEP)
	{
		world_y = half - pixel_size * y;

		for(int x = 0; x < IMG_H; x += STEP)
		{
			y_step = 0;
			t_interlst	*lst;
			lst = NULL;
			world_x = -half + pixel_size * x;
			position = (t_tuple){ world_x, world_y, wall_z, 1};
			dir = ft_norm_vector(ft_sub_tuple(position, ray.pos));
			ray = ft_set_transf_ray(ft_create_ray(ray.pos, dir), shape.inverted);
			ft_intersection_sphere(&lst, ray, &shape);
			t_inter	*hit;
			hit = ft_hit_inter(&lst);
			if (hit != NULL)
			{
				t_tuple point = ft_distance_ray(ray, hit->value);
				normal = ft_normal_at_sph(hit->shape, point);
				camera.norm = ft_neg_tuple(ray.dir);
				while (y_step < STEP)
				{
					x_step = 0;
					while(x_step < STEP)
					{
						t_color lighting = ft_lighting(hit->shape->material, point, light, camera, normal);
						int color = ft_get_mlx_color(lighting);
						ft_pixel_put(canvas->img, x + x_step++, y + y_step, color);
					}
					y_step++;
				}
			}
			}
	}
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
}


void	ft_start_rays_2(t_canvas *canvas);
void	test_draw_ball_light_2(t_canvas *canvas)
{
	ft_start_rays_2(canvas);
}
void	ft_start_rays_2(t_canvas *canvas)
{
	ft_refreshframe(canvas);

	ft_create_world_camera_test(IMG_W, IMG_H, canvas);
	// t_tuple	from = {0, 0, -5, 1};
	t_tuple	to = {0, 0, 1, 1};
	t_tuple	up = {0, 1, 0, 0};

	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,
						to, up);
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);

	ft_render(canvas, (t_camera)(canvas->camera));
}

void	test_render_scene_shadow(t_canvas *canvas)
{
	t_shapes	*_1 = (t_shapes *)canvas->objects->cont;
	t_shapes	*_2 = (t_shapes *)canvas->objects->next->cont;
	t_shapes	*_3 = (t_shapes *)canvas->objects->next->next->cont;
	
	ft_get_transf_obj(_1, (t_tuple){0}, (t_tuple){0}, (t_tuple){10, 0.01, 10, 0});
	ft_get_transf_obj(_2, (t_tuple){0, 0, 5, 0}, (t_tuple){M_PI / 2, -M_PI / 4, 0, 0}, (t_tuple){10, 0.01, 10, 0});
	ft_get_transf_obj(_3, (t_tuple){0, 0, 5, 0}, (t_tuple){M_PI / 2, M_PI / 4, 0, 0}, (t_tuple){10, 0.01, 10, 0});

	/* ft_get_transf_obj(_4, (t_tuple){0, 1, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	ft_get_transf_obj(_5, (t_tuple){2.5, 1, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	ft_get_transf_obj(_6, (t_tuple){-2.5, 1, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});  */
	printf("Matrix _1");
	ft_print_matrix(_1->transform);
	printf("Matrix _2");
	ft_print_matrix(_2->transform);
	printf("Matrix _3");
	ft_print_matrix(_3->transform);
	_1->material.color = (t_color){1, 0.9, 0.9, 3};
	_1->material.specular = 0;

	_2->material = _1->material;
	_3->material = _1->material;

	//put inside create camera of parser
	ft_create_world_camera_test(IMG_W, IMG_H, canvas);
	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,
												ft_add_tuple(canvas->camera.coord, canvas->camera.norm),
												(t_tuple){0, 1, 0, 0});
	ft_print_tuple(canvas->camera.norm, "camera norm");
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	ft_render(canvas, (t_camera)canvas->camera);
}

void	test_shadow_110(t_canvas *canvas)
{
	t_tuple color;
	t_material	m;
	t_light		light;

	m = ft_create_material();
	light.coord = (t_tuple){0, 0, -10, 1};
	light.color= (t_tuple){1, 1, 1, 3};
	ft_create_world_camera_test(IMG_W, IMG_H, canvas);
	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,
												ft_add_tuple(canvas->camera.coord, canvas->camera.norm),
												(t_tuple){0, 1, 0, 0});
	ft_print_tuple(canvas->camera.norm, "camera norm");
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	color = OLD_ft_lighting_shadow(m,
							(t_tuple){0, 0, 0, 1},
							light, 
							canvas->camera, 
							(t_tuple){0, 0, -1, 0}, 
							true);
	ft_print_tuple(color, "color in shaddow");
}

void	test_shadow_111(t_canvas *canvas)
{
	t_shapes	*_1 = (t_shapes *)canvas->objects->cont;
//	t_shapes	*_2 = (t_shapes *)canvas->objects->next->cont;
//	t_shapes	*_3 = (t_shapes *)canvas->objects->next->next->cont;
	bool result;

	_1->material.color = (t_color){0.8, 1.0, 0.6, 3};
	_1->material.diffuse = 0.7;
	_1->material.specular = 0.2;

	printf("\ntests IN_SHADOW or NOT page 111 - VERIFY VALUES ON PARSE LIKE BOOK!\n");
	result = ft_is_shadowed(canvas, (t_tuple){0, 10, 0, 1});
	printf("\n1st test\nshould NOT in shadow = %d\n", result);

	result = ft_is_shadowed(canvas, (t_tuple){10, -10, 10, 1});
	printf("\n2nd test \npoint is colinear: light -> shpere -> point\nshould IN shadow = %d\n", result);

	result = ft_is_shadowed(canvas, (t_tuple){-20, 20, -20, 1});
	printf("\n3rd test \npoint is behind light and sphere\nshould NOT in shadow = %d\n", result);

	result = ft_is_shadowed(canvas, (t_tuple){-2, 2, -2, 1});
	printf("\n4th test \npoint is between light and sphere\nshould NOT in shadow = %d\n", result);
}

void	test_shadow_114(t_canvas *canvas)
{
	t_shapes	*_1 = (t_shapes *)canvas->objects->cont;
	t_shapes	*_2 = (t_shapes *)canvas->objects->next->cont;
	//t_tuple color;
	//t_material	m;
	t_light		light;
	light.coord = (t_tuple){0, 0, -10, 1};
	light.color= (t_tuple){1, 1, 1, 3};
	_1->material.color = (t_color){0.8, 1.0, 0.6, 3};
	_1->material.diffuse = 0.7;
	_1->material.specular = 0.2;
	_2->material.diffuse = 0.7;
	_2->material.specular = 0.2;

	

	ft_create_world_camera_test(IMG_W, IMG_H, canvas);
	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,
												ft_add_tuple(canvas->camera.coord, canvas->camera.norm),
												(t_tuple){0, 1, 0, 0});
	ft_print_tuple(canvas->camera.norm, "camera norm");
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);

	t_ray	ray = {.pos = canvas->camera.coord, .dir = canvas->camera.norm};
	t_interlst *lst =ft_inter_world(canvas, ray);
	t_inter	*hit = ft_hit_inter(&lst);
	printf("Hit value = %f", hit->value);
	t_comp comp = ft_prepare_comp(hit, ray);
	t_color color = ft_shade_hit_shadow(canvas, comp);
	ft_print_tuple(color, "color in shaddow");


}


int	main(int argc, char *argv[])
{
	t_canvas canvas;
	ft_init_canvas(&canvas);
	if (ft_parse(&canvas, argv[1]) == 0)
		return 1;
	test_mlx_start(&canvas);
	ft_refreshframe(&canvas);

	test_render_scene_shadow(&canvas);
	
	// test_shadow_110(&canvas);
	// test_shadow_111(&canvas);
	// test_shadow_114(&canvas);

	test_mlx_end(&canvas);
	(void)argc;
	(void)argv;
	//ft_free_canvas(&canvas);
	return (0);
}

void	test_list()
{

	//test_draw_ball_light(&canvas);
	// test_draw_ball_light_2(&canvas);
	// test_render(&canvas);
	

	/*
	test_camera();
	test_viewtransform();
	test_color_at_mult(&canvas);
	test_shade(&canvas);
	test_mlx(argv);
	test_comp(canvas, argv);
	test_inter_world(&canvas, argv);
	test_mlx_clock(&canvas);
	test_draw_circle_with_ray(&canvas);
	test_norm_sphere();
	test_norm_sphere_transf();
	test_reflect();
	test_reflect_light();
	teste_tuple_op();
	teste_matrix_mult();
	teste_matrix_mult_tuple();
	test_ft_determinant_size_two();
	test_ft_submatrix();
	teste_minor_cofactor();
	test_cofators();
	test_determinant();
	test_invertion();
	test_put_together_mtx();
	test_translation();
	test_scale();
	test_rotation_x();
	test_ray_distance();
	test_intersect_sphere();
	test_multiple_intersect();
	test_transformed_ray();
	test_draw_circle_with_ray(&canvas);
	*/
}
