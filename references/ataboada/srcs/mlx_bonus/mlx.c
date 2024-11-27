/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:33:41 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/07 15:44:12 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_open_window(t_world *w)
{
	int	height;

	height = UI_WIN_WIDTH / UI_RATIO;
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, UI_WIN_WIDTH, height, "MiniRT");
	if (!w->win || !w->mlx)
		ft_perror(w, NULL, "Failed to start program");
	w->img.img = mlx_new_image(w->mlx, w->width, w->height);
	w->img2.img = mlx_new_image(w->mlx, UI_WIDTH, height);
	if (!w->img.img || !w->img2.img)
		ft_perror(w, NULL, "Failed to create image");
	w->img.addr = mlx_get_data_addr(w->img.img, &w->img.bpp,
			&w->img.line_length, &w->img.endian);
	w->img2.addr = mlx_get_data_addr(w->img2.img, &w->img2.bpp,
			&w->img2.line_length, &w->img2.endian);
	ft_print_buttons(w);
}

void	ft_print_buttons(t_world *w)
{
	int		index;
	t_area	area;

	area.origin = (t_pixel){0, 0};
	area.width = UI_WIDTH;
	area.height = UI_WIN_WIDTH / UI_RATIO;
	ft_create_button(w, area, w->ui.theme[0]);
	area.origin = (t_pixel){GAP_RIGHT, GAP_TOP};
	area.width = BTN_W;
	area.height = BTN_H;
	index = -1;
	while (++index <= w->ui.n_buttons)
	{
		ft_create_button(w, area, w->ui.theme[1]);
		area.origin = (t_pixel){GAP_RIGHT + index % BTN_ROW * GAP_ROW,
			GAP_TOP + index / BTN_ROW * GAP_COL};
	}
}

void	ft_create_button(t_world *w, t_area area, int color)
{
	int		button_width;
	int		button_height;
	t_pixel	pixel;
	char	*dst;

	button_width = area.origin.col + area.width;
	button_height = area.origin.row + area.height;
	pixel.col = area.origin.row - 1;
	while (++pixel.col < button_height)
	{
		pixel.row = area.origin.col - 1;
		while (++pixel.row < button_width)
		{
			dst = w-> img2.addr + (pixel.col * w->img2.line_length
					+ pixel.row * (w->img2.bpp / 8));
			*(unsigned int *)dst = color;
		}
	}
}
