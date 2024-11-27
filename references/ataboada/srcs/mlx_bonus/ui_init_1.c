/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:19:55 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/18 11:00:59 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_set_header(t_world *w)
{
	w->ui.header[0] = "                          ____    ______ ";
	w->ui.header[1] = "           __          __/\\  _`\\ /\\__  _\\ ";
	w->ui.header[2] = "  ___ ___ /\\_\\    ___ /\\_\\ \\ \\L \\\\/_/\\ \\/ ";
	w->ui.header[3] = "/' __` __`\\/\\ \\ /' _ `\\/\\ \\ \\  _ '_ \\ \\ \\  ";
	w->ui.header[4] = "/\\ \\/\\ \\/\\ \\ \\ \\/\\ \\/\\ \\ \\ \\ \\ \\ \\ \\ "
		"\\ \\ \\ ";
	w->ui.header[5] = "\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\"
		" \\ \\_\\";
	w->ui.header[6] = " \\/_/\\/_/\\/_/\\/_/\\/_/\\/_/\\/_/\\/_/\\/ /  \\/_/";
}

void	ft_set_button_limits(t_world *w)
{
	int		index;

	index = -1;
	while (++index < w->ui.n_buttons)
	{
		w->ui.limits[index][0] = w->ui.begin + GAP_RIGHT + index
			% BTN_ROW * GAP_ROW;
		w->ui.limits[index][1] = w->ui.limits[index][0] + BTN_W;
		w->ui.limits[index][2] = GAP_TOP + index / BTN_ROW * GAP_COL;
		w->ui.limits[index][3] = w->ui.limits[index][2] + BTN_H;
	}
}

void	ft_set_ranges(t_world *w)
{
	w->ui.ranges[0] = (t_range){-1, 20};
	w->ui.ranges[1] = (t_range){14, 20};
	w->ui.ranges[2] = (t_range){-1, 15};
	w->ui.ranges[3] = (t_range){5, 20};
	w->ui.ranges[4] = (t_range){-1, 6};
	w->ui.ranges[5] = (t_range){14, 18};
	w->ui.ranges[6] = (t_range){9, 20};
	w->ui.ranges[7] = (t_range){-1, 12};
	w->ui.ranges[8] = (t_range){16, 20};
}

void	ft_set_themes(t_world *w)
{
	int		index;

	w->ui.themes[0][0] = 0x008080;
	w->ui.themes[0][1] = 0xff0000;
	w->ui.themes[0][2] = 0x000000;
	w->ui.themes[0][3] = 0xffffff;
	w->ui.themes[0][4] = 0x153394;
	w->ui.themes[0][5] = 0x0000ff;
	w->ui.themes[1][0] = 0x153394;
	w->ui.themes[1][1] = 0x008080;
	w->ui.themes[1][2] = 0x0000ff;
	w->ui.themes[1][3] = 0xff0000;
	w->ui.themes[1][4] = 0xffffff;
	w->ui.themes[1][5] = 0xffffff;
	index = -1;
	while (++index < 6)
		w->ui.theme[index] = w->ui.themes[0][index];
}

void	ft_free_ui(t_world *w)
{
	if (w->ui.n_objs[0] > 0)
		free(w->ui.sp);
	if (w->ui.n_objs[1] > 0)
		free(w->ui.pl);
	if (w->ui.n_objs[2] > 0)
		free(w->ui.cy);
	if (w->ui.n_objs[3] > 0)
		free(w->ui.co);
	if (w->ui.n_objs[4] > 0)
		free(w->ui.cb);
	if (w->ui.n_objs[5] > 0)
		free(w->ui.tr);
	if (w->ui.n_li > 0)
		free(w->ui.li);
}
