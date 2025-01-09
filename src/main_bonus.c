/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:44:29 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:44:31 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_mlx_end(t_canvas *canvas)
{
	mlx_do_key_autorepeatoff(canvas->mlx);
	mlx_hook(canvas->win, KeyPress, KeyPressMask, key_handler, canvas);
	mlx_hook(canvas->win, KeyRelease, KeyReleaseMask, key_release, canvas);
	mlx_hook(canvas->win, ButtonPress, ButtonPressMask, mouse_handler, canvas);
	mlx_hook(canvas->win, ButtonRelease, ButtonReleaseMask,
		mouse_handler_release, canvas);
	mlx_hook(canvas->win, MotionNotify, CWBackingStore, mouse_motion, canvas);
	mlx_hook(canvas->win, DestroyNotify, StructureNotifyMask,
		close_handler, canvas);
	mlx_loop_hook(canvas->mlx, ft_refreshframe, canvas);
	mlx_loop(canvas->mlx);
	ft_free_canvas(canvas);
}

static int	ft_count_objects(t_canvas *canvas)
{
	int	count;

	count = 0;
	count += canvas->count.sphere;
	count += canvas->count.plane;
	count += canvas->count.cylinder;
	ft_printf(2, "%d\n", count);
	return (count);
}

int	ft_refreshframe(void *ptr)
{
	t_canvas	*canvas;

	canvas = ptr;
	mlx_destroy_image(canvas->mlx, canvas->img.img);
	canvas->img.img = mlx_new_image(canvas->mlx, IMG_W, IMG_H);
	canvas->img.addr = mlx_get_data_addr(canvas->img.img,
			&canvas->img.bits_per_pixel,
			&canvas->img.size_line, &canvas->img.endian);
	ft_update_world_camera(canvas);
	ft_render_bonus(canvas);
	draw_axis(canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img.img, 0, 0);
	ft_menu(canvas);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_canvas	canvas;

	if (argc != 2)
		return (ft_printf(2, "Error\nUsage: ./miniRT <path/to/file.rt>\n"), 1);
	ft_init_canvas(&canvas);
	if (ft_parse(&canvas, argv[1]) == 0
		|| (canvas.debug && ft_count_objects(&canvas) == 0))
		return (ft_free_canvas(&canvas), 1);
	if (canvas.debug)
		return (ft_free_canvas(&canvas), 0);
	ft_mlx_init(&canvas);
	ft_refreshframe(&canvas);
	ft_mlx_end(&canvas);
	return (0);
}
