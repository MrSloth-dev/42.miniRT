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

t_matrix	ft_transform_camera(t_matrix m, int key)
{
	if (key == XK_a)
		return (ft_matrix_mult(m, ft_translation_matrix(1, 0, 0)));
	else if (key == XK_d)
		return (ft_matrix_mult(m, ft_translation_matrix(-1, 0, 0)));
	else if (key == XK_w)
		return (ft_matrix_mult(m, ft_translation_matrix(0, 0, -1)));
	else if (key == XK_s)
		return (ft_matrix_mult(m, ft_translation_matrix(0, 0, 1)));
	else if (key == XK_space)
		return (ft_matrix_mult(m, ft_translation_matrix(0, -1, 0)));
	else if (key == XK_c)
		return (ft_matrix_mult(m, ft_translation_matrix(0, 1, 0)));
	else if (key == XK_Right)
		return (ft_matrix_mult(m, ft_rotate_matrix_y(M_PI / 20)));
	else if (key == XK_Left)
		return (ft_matrix_mult(m, ft_rotate_matrix_y(-M_PI / 20)));
	else if (key == XK_Up)
		return (ft_matrix_mult(m, ft_rotate_matrix_x(-M_PI / 20)));
	else if (key == XK_Down)
		return (ft_matrix_mult(m, ft_rotate_matrix_x(M_PI / 20)));
	return (m);
}

bool	ft_change_step(int keysym, t_canvas *canvas)
{
	if (keysym == XK_o && canvas->step > 1)
		return (canvas->step--, true);
	if (keysym == XK_p && canvas->step < 9)
		return (canvas->step++, true);
	return (false);
}

int	key_handler(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Escape)
		close_handler(canvas);
	else if (keysym == XK_h)
		canvas->help = !canvas->help;
	else if (ft_change_step(keysym, canvas))
		;
	else
	{
		if (keysym == XK_r) // Maybe add reset to objects also
			canvas->camera.transf = canvas->camera.reset;
		else
			canvas->camera.transf = ft_transform_camera(canvas->camera.transf, keysym);
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
	ft_menu(canvas);
	return (0);
}
