/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:46:04 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/13 11:25:15 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minirt.h"

#include "teste_done.c"
#include <stdio.h>


void	ft_start_rays_mult_objs(t_canvas *canvas, t_shapes shape)
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
	t_camera  camera = ft_create_camera_a((t_tuple){0 , 0, -5, 1}, (t_tuple){0, 0, 1, 0}, 70);
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
			t_objects *temp;
			temp = canvas->objects;
			t_inter	*hit;
			ft_intersection_sphere(&lst, ray, ((t_shapes *)temp->cont));
			t_inter	*hit_min;
			hit_min= ft_hit_inter(&lst);
			while (temp)
			{
				lst = NULL;
				ft_intersection_sphere(&lst, ray, ((t_shapes *)temp->cont));
				hit = ft_hit_inter(&lst);
				if (hit && hit->value > 0 && hit->value <= hit_min->value)
				{
					hit_min = hit;
				}

				temp = temp->next;
			}
			if (hit!= NULL)
			{
				t_tuple point = ft_distance_ray(ray, hit_min->value);
				normal = ft_normal_at_sph(hit_min->shape, point);
				camera.norm = ft_neg_tuple(ray.dir);
				while (y_step < STEP)
				{
					x_step = 0;
					while(x_step < STEP)
					{
						t_color lighting = ft_lighting(hit->shape->material, point, canvas->light, camera, normal);
						int color = ft_get_mlx_color(lighting);
						ft_pixel_put(canvas->img, x + x_step++, y + y_step, color);
					}
					y_step++;
				}
			}
			else
				while (y_step < STEP)
				{
					x_step = 0;
					while(x_step < STEP)
						ft_pixel_put(canvas->img, x + x_step++, y + y_step, ft_get_mlx_color(canvas->ambient.color));
					y_step++;
				}
		}
	}
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
}


void	test_mlx_start(t_canvas *canvas)
{
	ft_init_canvas(canvas);
	ft_setup(canvas);
	mlx_hook(canvas->win, DestroyNotify, 0l, &close_handler, &canvas);
}

void	test_mlx_end(t_canvas *canvas)
{
	mlx_loop(canvas->mlx);
	ft_free_canvas(canvas);
}

void	test_draw_ball_light(t_canvas *canvas)
{
	// t_tuple point;
	// t_tuple grav;
	// t_tuple wind;
	// t_tuple vel;
	// ft_tuple_init(&point, (t_point){0.1,0,0.2}, T_POINT);
	// ft_tuple_init(&vel, (t_point){0.0,0,0.2}, T_VECTOR);
	// ft_tuple_init(&grav, (t_point){0,-0.03,0}, T_VECTOR);
	// ft_tuple_init(&wind, (t_point){0,0,0.0}, T_VECTOR);
	// while (1)
	// {
	// 	point = ft_add_tuple(point, vel);
	// 	vel = ft_add_tuple(vel, ft_add_tuple(grav, wind));
	// 	if (point.z > 17.5 || point.z < -4.5)
	// 		vel.z = -vel.z;
	// 	if (point.y > 7.5 || point.y < -7.5)
	// 		vel.y = -vel.y * 0.95;
	// 	if (point.x > 5.5 || point.x < -3.5)
	// 		vel.x = -vel.x / 0.95;
	// 	ft_get_transf_obj(canvas->objects->cont, point, (t_tuple){0}, (t_tuple) {1, 1, 1, 0});
		ft_start_rays_mult_objs(canvas, *(t_shapes *)canvas->objects->cont);
	// 	usleep(150);
	// }
}

void	test_mlx(char *argv[])
{
	t_canvas canvas;
	if (ft_parse(&canvas, argv[1]) == 0)
		return ;
	test_mlx_start(&canvas);
	test_draw_ball_light(&canvas);
	test_mlx_end(&canvas);
}

void	test_comp(t_canvas canvas, char *argv[])
{
	t_interlst	*lst;
	lst = NULL;
	if (ft_parse(&canvas, argv[1]) == 0)
		return ;
	t_ray	ray = ft_create_ray((t_tuple) {0,0,0, 1}, (t_tuple) {0,0,1,0});
	ft_intersection_sphere(&lst, ray, canvas.objects->cont);
	t_inter	*hit = ft_hit_inter(&lst);
	t_comp	temp = ft_prepare_comp(hit, ray);
	(void)temp;
	printf("\nvalue inter = %f\n", temp.value);
	ft_print_tuple(temp.shape->material.color, "sphere color");
	ft_print_tuple(temp.point, "point");
	ft_print_tuple(temp.eyev, "eyev");
	printf("\nis inside? = %i\n", temp.inside);
	ft_print_tuple(temp.normalv, "normalv");
}

void	test_inter_world(t_canvas *canvas, char *argv[])
{
	t_interlst	*lst;
	lst = NULL;
	if (ft_parse(canvas, argv[1]) == 0)
		return ;
	t_ray	ray = ft_create_ray((t_tuple) {0,0,-5, 1}, (t_tuple) {0,0,1,0});
	((t_shapes *)canvas->objects->cont)->material.diffuse = 0.7;
	((t_shapes *)canvas->objects->cont)->material.specular = 0.2;
	for (t_objects *temp_o = canvas->objects; temp_o; temp_o = temp_o->next)
	{
		lst = NULL;
		ft_intersection_sphere(&lst, ray, temp_o->cont);
		printf("\ni = %d\n", ft_lstsize(lst));
		t_inter	*hit = ft_hit_inter(&lst);
		t_comp	temp = ft_prepare_comp(hit, ray);
		t_color	c = ft_shade_hit(canvas, temp);
		ft_print_tuple(c, "color");
		printf("diameter = %f\n",(((t_shapes *)temp_o->cont)->sph.diameter));
		ft_print_tuple(((t_shapes *)temp_o->cont)->sph.coord, "sphere coord");
		for (t_interlst *temp = lst; temp; temp = temp->next)
			printf("inter value %f\n", ((t_inter *)temp->cont)->value);
		printf("next object\n");
	}
	ft_free_objects(lst);
}

void	test_shade(t_canvas *canvas, char *argv[])
{
	t_interlst	*lst;
	lst = NULL;
	if (ft_parse(canvas, argv[1]) == 0)
		return ;
	t_ray	ray = ft_create_ray((t_tuple) {0,0,-5, 1}, (t_tuple) {0,0,1,0});
	((t_shapes *)canvas->objects->cont)->material.diffuse = 0.7;
	((t_shapes *)canvas->objects->cont)->material.specular = 0.2;
	ft_intersection_sphere(&lst, ray, canvas->objects->cont);
	t_inter	*hit = ft_hit_inter(&lst);
	hit->value = 4;
	t_comp	temp = ft_prepare_comp(hit, ray);
	t_color	c = ft_shade_hit(canvas, temp);
	ft_print_tuple(c, "color");
	ft_free_objects(lst);
}

int	main(int argc, char *argv[])
{

	t_canvas canvas;
	ft_init_canvas(&canvas);
	// test_comp(canvas, argv);
	test_inter_world(&canvas, argv);
	test_shade(&canvas, argv);
	// test_mlx(argv);
	(void)argc;
	(void)argv;
	ft_free_canvas(&canvas);
	return (0);
}

void	test_list()
{
	/*
	test_mlx(argv);
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
