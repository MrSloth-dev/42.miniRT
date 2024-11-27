/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_interactions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:46:03 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/17 17:57:21 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_create_strings(t_world *w)
{
	int		index;

	index = -1;
	while (++index < w->ui.n_buttons)
	{
		if (w->ui.tags[index] == NULL)
			break ;
		mlx_set_font(w->mlx, w->win, "9x15");
		mlx_string_put(w->mlx, w->win, w->ui.begin + GAP_RIGHT + index
			% BTN_ROW * GAP_ROW, GAP_TOP + STR_GAP_UP + index / BTN_ROW
			* GAP_COL, w->ui.theme[2], w->ui.tags[index]);
	}
	mlx_set_font(w->mlx, w->win, "9x15bold");
	index = -1;
	while (++index < 7)
	{
		mlx_string_put(w->mlx, w->win, w->ui.begin + HEADER_TOP, HEADER_TOP
			+ HEADER_STR_GAP * index, w->ui.theme[4], w->ui.header[index]);
	}
}

void	ft_menu_obj(t_world *w, int choice)
{
	if (choice == 1)
		ft_mlx_string_put(w, w->ui.ranges[0], w->ui.theme[0]);
	else if (choice == 2)
	{
		ft_mlx_string_put(w, w->ui.ranges[1], w->ui.theme[0]);
		ft_mlx_string_put(w, w->ui.ranges[2], w->ui.theme[3]);
	}
	else if (choice == 4)
	{
		ft_mlx_string_put(w, w->ui.ranges[3], w->ui.theme[0]);
		ft_mlx_string_put(w, w->ui.ranges[4], w->ui.theme[3]);
		ft_mlx_string_put(w, w->ui.ranges[5], w->ui.theme[3]);
	}
	else if (choice >= 8 && choice <= 256)
	{
		ft_mlx_string_put(w, w->ui.ranges[6], w->ui.theme[0]);
		ft_mlx_string_put(w, w->ui.ranges[7], w->ui.theme[3]);
		ft_mlx_string_put(w, w->ui.ranges[8], w->ui.theme[3]);
	}
}

void	ft_mlx_string_put(t_world *w, t_range range, int color)
{
	int		index;

	mlx_set_font(w->mlx, w->win, "9x15bold");
	index = range.min;
	while (++index < range.max)
	{
		mlx_string_put(w->mlx, w->win, w->ui.begin + GAP_RIGHT + index
			/ LINES_ROW * UI_WIDTH / 2, GAP_TOP + 2.2 * GAP_ROW
			+ index % LINES_ROW * STR_GAP_UP, color, w->ui.keys[index]);
	}
}
