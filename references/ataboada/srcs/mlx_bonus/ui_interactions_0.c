/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_interactions_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:35:54 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/17 17:54:32 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_place_tags(t_world *w, int i)
{
	int		index;

	index = -1;
	if (i == 42)
	{
		while (++index < w->ui.n_buttons)
		{
			mlx_set_font(w->mlx, w->win, "9x15bold");
			mlx_string_put(w->mlx, w->win, w->ui.begin + GAP_RIGHT + (index)
				% BTN_ROW * GAP_ROW, GAP_TOP + STR_GAP_UP + (index)
				/ BTN_ROW * GAP_COL, w->ui.theme[1], w->ui.tags[index]);
			mlx_set_font(w->mlx, w->win, "9x15");
			mlx_string_put(w->mlx, w->win, w->ui.begin + GAP_RIGHT + (index)
				% BTN_ROW * GAP_ROW, GAP_TOP + STR_GAP_UP + (index)
				/ BTN_ROW * GAP_COL, w->ui.theme[2], w->ui.tags[index]);
		}
	}
	if (i >= 1 && i <= 9)
	{
		index = i;
		mlx_set_font(w->mlx, w->win, "9x15bold");
		mlx_string_put(w->mlx, w->win, w->ui.begin + GAP_RIGHT + (index - 1)
			% BTN_ROW * GAP_ROW, GAP_TOP + STR_GAP_UP + (index - 1)
			/ BTN_ROW * GAP_COL, w->ui.theme[5], w->ui.tags[index - 1]);
	}
}

int	ft_within_limits(t_world *w, int x, int y)
{
	int		index;

	index = -1;
	while (++index < w->ui.n_buttons)
	{
		if (x > w->ui.limits[index][0] && x < w->ui.limits[index][1]
			&& y > w->ui.limits[index][2] && y < w->ui.limits[index][3])
			return (index + 1);
	}
	return (0);
}

void	ft_set_flags(t_world *w, int button)
{
	w->ui.flags = 0;
	w->ui.tflag = 0;
	if (button == 1)
		ft_switch_theme(w);
	else if (button == 2)
		w->ui.flags |= UI_CAMERA;
	else if (button == 3)
		w->ui.flags |= UI_LIGHT;
	else if (button == 4)
		w->ui.flags |= UI_SPHERE;
	else if (button == 5)
		w->ui.flags |= UI_PLANE;
	else if (button == 6)
		w->ui.flags |= UI_CYLINDER;
	else if (button == 7)
		w->ui.flags |= UI_CONE;
	else if (button == 8)
		w->ui.flags |= UI_CUBE;
	else if (button == 9)
		w->ui.flags |= UI_TRIANGLE;
}

int	ft_get_new_index(t_world *w, int index)
{
	if (index <= 3)
		return (index);
	if (strcmp(w->ui.tags[index - 1], "    Sphere") == 0)
		return (4);
	else if (strcmp(w->ui.tags[index - 1], "    Plane") == 0)
		return (5);
	else if (strcmp(w->ui.tags[index - 1], "   Cylinder") == 0)
		return (6);
	else if (strcmp(w->ui.tags[index - 1], "     Cone") == 0)
		return (7);
	else if (strcmp(w->ui.tags[index - 1], "     Cube") == 0)
		return (8);
	else if (strcmp(w->ui.tags[index - 1], "  Triangle") == 0)
		return (9);
	return (0);
}

void	ft_switch_theme(t_world *w)
{
	int			index;
	static int	i;

	i++;
	index = -1;
	w->ui.flags |= UI_THEME;
	while (++index < 6)
		w->ui.theme[index] = w->ui.themes[i % 2][index];
	mlx_destroy_image(w->mlx, w->img2.img);
	w->img2.img = mlx_new_image(w->mlx, UI_WIDTH, UI_WIN_WIDTH / UI_RATIO);
	w->img2.addr = mlx_get_data_addr(w->img2.img, &w->img2.bpp,
			&w->img2.line_length, &w->img2.endian);
	ft_print_buttons(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img2.img, w->ui.begin, 0);
	ft_create_strings(w);
}
