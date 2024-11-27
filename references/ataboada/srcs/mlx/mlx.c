/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:33:41 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/17 17:48:44 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_open_window(t_world *w)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, w->width, w->height, "MiniRT");
	if (!w->win || !w->mlx)
		ft_perror(w, NULL, "Failed to start program");
	w->img.img = mlx_new_image(w->mlx, w->width, w->height);
	if (!w->img.img)
		ft_perror(w, NULL, "Failed to create image");
	w->img.addr = mlx_get_data_addr(w->img.img, &w->img.bpp,
			&w->img.line_length, &w->img.endian);
}

void	ft_set_hooks(t_world *w)
{
	mlx_hook(w->win, KeyPress, KeyPressMask, ft_button_press, w);
	mlx_hook(w->win, KeyRelease, KeyReleaseMask, ft_button_release, w);
	mlx_hook(w->win, DestroyNotify, ButtonPressMask, ft_close, w);
	mlx_loop_hook(w->mlx, ft_update, w);
}

int	ft_button_press(int k, t_world *img)
{
	if (k == ESC)
		ft_close(img);
	else if (k == W || k == A || k == S || k == D || k == M || k == N
		|| k == UP || k == DOWN || k == LEFT || k == RIGHT
		|| k == ALT || k == SPACE || k == PLUS || k == MINUS)
		img->status_key = k;
	return (0);
}

int	ft_button_release(int k, t_world *img)
{
	if (img->status_key == k)
		img->status_key -= k;
	return (0);
}

int	ft_close(t_world *w)
{
	mlx_destroy_image(w->mlx, w->img.img);
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	ft_free_all_allocated_memory(w);
	exit(EXIT_SUCCESS);
}
