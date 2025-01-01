/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:46:04 by joao-pol          #+#    #+#             */
/*   Updated: 2024/12/23 13:29:05 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#include "teste_done.c"

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

void	test_render_scene_shadow(t_canvas *canvas)
{
	//put inside create camera of parser
	ft_create_world_camera(IMG_W, IMG_H, canvas);
	canvas->camera.transf = ft_view_transformation(canvas->camera.coord,
					ft_add_tuple(canvas->camera.coord, canvas->camera.norm),
									(t_tuple){0, 1, 0, 0});
	ft_print_tuple(canvas->camera.norm, "camera norm");
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	ft_render(canvas, (t_camera)canvas->camera);
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

int	main(int argc, char *argv[])
{
	t_canvas canvas;
	ft_init_canvas(&canvas);
	if (ft_parse(&canvas, argv[1]) == 0)
		return 1;
	test_mlx_start(&canvas);
	ft_refreshframe(&canvas);

	test_render_scene_shadow(&canvas);
	//test_inter_cyl_178(&canvas);
	//test_inter_cyl_180(&canvas);

	test_mlx_end(&canvas);
	(void)argc;
	(void)argv;
	ft_free_canvas(&canvas);
	return (0);
}

void	test_list()
{

	

	/*
	test_inter_plane_123();
	test_plane_125(&canvas);
	test_inter_plane_123();
	test_draw_ball_light(&canvas);
	test_draw_ball_light_2(&canvas);
	test_render(&canvas);
	test_shadow_110(&canvas);
	test_shadow_111(&canvas);
	test_shadow_114(&canvas);
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
