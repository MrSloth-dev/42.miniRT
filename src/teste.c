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

int	main(int argc, char *argv[])
{
	t_canvas canvas;
	ft_init_canvas(&canvas);
	if (ft_parse(&canvas, argv[1]) == 0)
		return 1;
	test_mlx_start(&canvas);
	ft_refreshframe(&canvas);

	test_render_scene_shadow(&canvas);

	test_mlx_end(&canvas);
	(void)argc;
	(void)argv;
	ft_free_canvas(&canvas);
	return (0);
}

void	test_list()
{
	/*
	test_inter_cyl_178(&canvas);
	test_inter_cyl_180(&canvas);
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
