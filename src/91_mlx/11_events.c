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

bool	ft_camera_transform(int keysym, t_canvas *canvas)
{
	if (keysym == XK_z)
		canvas->camera.transf = canvas->camera.reset;
	else if (!canvas->object_selected && !canvas->light_selected)
		canvas->camera.transf = ft_transform_camera_key(
				canvas->camera.transf, keysym);
	else
		return (false);
	canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	return (true);
}

bool	ft_light_transform(int keysym, t_canvas *canvas)
{
	if (keysym == XK_l)
	{
		if (canvas->object_selected)
			ft_clear_select(canvas);
		canvas->light_selected = 1;
		return (true);
	}
	else if (canvas->light_selected == 1)
	{
		if (ft_change_light_position(keysym, canvas))
			;
		else if (ft_change_light_color(keysym, canvas))
			;
		else
			return (false);
		return (true);
	}
	return (false);
}

int	key_release(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Shift_L)
		canvas->shift_press = 1;
	return (0);
}

int	key_handler(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Escape)
		close_handler(canvas);
	else if (keysym == XK_h)
		canvas->help = !canvas->help;
	if (keysym == XK_Shift_L)
		canvas->shift_press = -1;
	else if (ft_light_transform(keysym, canvas))
		;
	else if (ft_change_resolution(keysym, canvas))
		;
	else if (ft_change_obj_propriety(keysym, canvas, false))
		;
	else if (ft_camera_transform(keysym, canvas))
		;
	else if (keysym == XK_x)
		ft_clear_select(canvas);
	return (0);
}

int	mouse_handler_release(int mousecode, int x, int y, t_canvas *canvas)
{
	(void)x;
	(void)y;
	if (mousecode == 3)
		canvas->mouse_drag = 0;
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_canvas *canvas)
{
	if (mousecode == 3)
		canvas->mouse_drag = 1;
	if (mousecode == 1)
		ft_select_obj(x, y, canvas);
	else if (mousecode == 4)
		canvas->camera.field_v -= M_PI / 30;
	else if (mousecode == 5)
		canvas->camera.field_v += M_PI / 30;
	return (0);
}

int	close_handler(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->img.img);
	mlx_destroy_window(canvas->mlx, canvas->win);
	mlx_destroy_display(canvas->mlx);
	ft_free_canvas(canvas);
	exit (0);
}

int	ft_refreshframe(void *ptr)
{
	t_canvas *canvas;

	canvas = ptr;
	mlx_destroy_image(canvas->mlx, canvas->img.img);
	canvas->img.img = mlx_new_image(canvas->mlx, IMG_W, IMG_H);
	canvas->img.addr = mlx_get_data_addr(canvas->img.img,
			&canvas->img.bits_per_pixel,
			&canvas->img.size_line, &canvas->img.endian);
	ft_update_world_camera(canvas);
	ft_render(canvas);
	ft_menu(canvas);
	return (0);
}
