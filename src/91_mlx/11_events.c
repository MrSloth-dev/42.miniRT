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
	else if (keysym == 65451)
		canvas->iter.max += 1;
	else if ((keysym == XK_minus || keysym == 65453) && canvas->iter.max > 1)
		canvas->iter.max -= 1;
	else if (keysym == XK_r)
	{
		// canvas->offset_x = 0;
		// canvas->offset_y = 0;
		// canvas->scale = 1;
		// canvas->iter.max = 42;
	}
	ft_refreshframe(canvas);
	return (0);
}
//
// int	mouse_handler(int mousecode, int x, int y, t_canvas *canvas)
// {
// 	if (mousecode == 4)
// 	{
// 		canvas->scale *= 0.9;
// 		if (canvas->mousetrack)
// 		{
// 			canvas->offset_x += (0.75 * (x - (double)IMG_WIDTH / 2)
// 					/ IMG_WIDTH * canvas->scale);
// 			canvas->offset_y += (0.75 * (y - (double)IMG_HEIGHT / 2)
// 					/ IMG_HEIGHT * canvas->scale);
// 		}
// 	}
// 	else if (mousecode == 5)
// 		canvas->scale /= 0.9;
// 	ft_refreshframe(canvas);
// 	return (0);
// }

int	close_handler(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->img->img);
	mlx_destroy_window(canvas->mlx, canvas->win);
	mlx_destroy_display(canvas->mlx);
	free(canvas->img);
	free(canvas->mlx);
	exit (0);
}

int	ft_refreshframe(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->img->img);
	canvas->img->img = mlx_new_image(canvas->mlx, IMG_W, IMG_H);
	canvas->img->addr = mlx_get_data_addr(canvas->img->img,
			&canvas->img->bits_per_pixel,
			&canvas->img->size_line, &canvas->img->endian);
	// ft_renderimage(canvas);
	return (0);
}
