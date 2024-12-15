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
#include <math.h>
#include <stdio.h>

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

	((t_shapes *)canvas->objects->cont)->material.color = (t_color){0.8, 1.0, 0.6, 3};
	((t_shapes *)canvas->objects->cont)->material.diffuse = 0.7;
	((t_shapes *)canvas->objects->cont)->material.specular = 0.2;
	t_camera cam = ft_create_world_camera(IMG_W, IMG_H, M_PI / 2);
	t_tuple	from = {0, 0, -5, 1};
	t_tuple	to = {0, 0, 0, 1};
	t_tuple	up = {0, 1, 0, 0};
	cam.transf = ft_view_transformation(from, to, up);
	cam.inverted = ft_invert_matrix(cam.transf);

	ft_render(canvas, cam);
}

int	main(int argc, char *argv[])
{
	t_canvas canvas;
	ft_init_canvas(&canvas);
	if (ft_parse(&canvas, argv[1]) == 0)
		return 1;
	test_render(&canvas);
	(void)argc;
	(void)argv;
	ft_free_canvas(&canvas);
	return (0);
}

void	test_list()
{
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
