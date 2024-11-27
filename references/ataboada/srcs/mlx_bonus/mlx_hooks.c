/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:35:48 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/17 17:48:28 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_set_hooks(t_world *w)
{
	mlx_do_key_autorepeatoff(w->mlx);
	mlx_hook(w->win, KeyPress, KeyPressMask, ft_button_press, w);
	mlx_hook(w->win, KeyRelease, KeyReleaseMask, ft_button_release, w);
	mlx_hook(w->win, DestroyNotify, ButtonPressMask, ft_close, w);
	mlx_loop_hook(w->mlx, ft_update, w);
	mlx_mouse_hook(w->win, ft_mouse_hook, w);
}

int	ft_button_press(int k, t_world *img)
{
	if (k == ESC)
		ft_close(img);
	else if (k == W || k == A || k == S || k == D || k == M || k == N
		|| k == UP || k == DOWN || k == LEFT || k == RIGHT
		|| k == ALT || k == SPACE || k == PLUS || k == MINUS
		|| k == Z || k == TAB)
	{
		img->status_key = k;
		if (k == TAB)
			img->ui.tflag++;
	}
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
	mlx_do_key_autorepeaton(w->mlx);
	mlx_destroy_image(w->mlx, w->img.img);
	mlx_destroy_image(w->mlx, w->img2.img);
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	ft_free_ui(w);
	ft_free_all_allocated_memory(w);
	get_next_line(-1, 1);
	exit(EXIT_SUCCESS);
}

int	ft_mouse_hook(int keycode, int x, int y, t_world *w)
{
	int		index;

	ft_place_tags(w, 42);
	if (keycode == 1)
	{
		index = ft_within_limits(w, x, y);
		if (index >= 1 && index <= 9)
		{
			ft_set_flags(w, ft_get_new_index(w, index));
			ft_place_tags(w, index);
			if (w->ui.flags == 1)
				ft_menu_obj(w, w->ui.flags);
			if (w->ui.flags == 2)
				ft_menu_obj(w, w->ui.flags);
			else if (w->ui.flags == 4)
				ft_menu_obj(w, w->ui.flags);
			else if (w->ui.flags >= 8 && w->ui.flags <= 256)
				ft_menu_obj(w, w->ui.flags);
		}
	}
	return (0);
}
