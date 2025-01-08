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

#include "minirt.h"

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
	mlx_hook(canvas->win, DestroyNotify, 0l, &close_handler, &canvas);
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

int	main(int argc, char *argv[])
{
	t_canvas	canvas;

	if (argc != 2)
		return (ft_printf(2, "Error\nUsage: ./miniRT <path/to/file.rt>\n"), 1);
	ft_init_canvas(&canvas);
	if (ft_parse(&canvas, argv[1]) == 0
		|| (DEBUG && ft_count_objects(&canvas) == 0))
		return (1);
	if (DEBUG)
		return (0);
	ft_mlx_init(&canvas);
	ft_refreshframe(&canvas);
	ft_mlx_end(&canvas);
	return (0);
}
