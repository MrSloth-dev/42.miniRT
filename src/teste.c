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

int	main(int argc, char *argv[])
{

	t_canvas canvas;
	ft_init_canvas(&canvas);
	if (ft_parse(&canvas, argv[1]) == 0)
		return 1;
	(void)argc;
	(void)argv;
	test_viewtransform();
	ft_free_canvas(&canvas);
	return (0);
}

void	test_list()
{
	/*
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
