/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2024/06/13 16:48:12 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_handler(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Escape || keysym == XK_q)
		close_handler(canvas);
	else if (keysym == XK_a)
	{
		printf("Hello\n");
		canvas->camera.coord.x--;
		canvas->camera.transf = ft_view_transformation(canvas->camera.coord, ft_add_tuple(canvas->camera.coord, canvas->camera.norm), (t_tuple){0, 1, 0, 0});
		canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	}
	else if (keysym == XK_d)
	{
		printf("Hello\n");
		canvas->camera.coord.x++;
		canvas->camera.transf = ft_view_transformation(canvas->camera.coord, ft_add_tuple(canvas->camera.coord, canvas->camera.norm), (t_tuple){0, 1, 0, 0});
		canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	}
	else if (keysym == XK_w)
	{
		printf("Hello\n");
		canvas->camera.coord.z++;
		canvas->camera.transf = ft_view_transformation(canvas->camera.coord, ft_add_tuple(canvas->camera.coord, canvas->camera.norm), (t_tuple){0, 1, 0, 0});
		canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	}
	else if (keysym == XK_s)
	{
		printf("Hello\n");
		canvas->camera.coord.z--;
		canvas->camera.transf = ft_view_transformation(canvas->camera.coord, ft_add_tuple(canvas->camera.coord, canvas->camera.norm), (t_tuple){0, 1, 0, 0});
		canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	}
	ft_refreshframe(canvas);
	return (0);
}

int	mouse_handler(int mousecode, t_canvas *canvas)
{
	if (mousecode == 1) // 4
		printf("Left click\n");
	else if (mousecode == 3) // 5
		printf("Right click\n");
	(void)canvas;
	ft_refreshframe(canvas);
	return (0);
}

int	close_handler(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->img->img);
	mlx_destroy_window(canvas->mlx, canvas->win);
	mlx_destroy_display(canvas->mlx);
	ft_free_canvas(canvas);
	free(canvas->img);
	free(canvas->mlx);
	exit (0);
}

int	ft_refreshframe(void *ptr)
{
	t_canvas *canvas;

	canvas = ptr;
	mlx_destroy_image(canvas->mlx, canvas->img->img);
	canvas->img->img = mlx_new_image(canvas->mlx, IMG_W, IMG_H);
	canvas->img->addr = mlx_get_data_addr(canvas->img->img,
			&canvas->img->bits_per_pixel,
			&canvas->img->size_line, &canvas->img->endian);
	ft_render(canvas);
	return (0);
}
