/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:58:31 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 09:58:34 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_top_menu_options(t_canvas *canvas, int *j, int i)
{
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE, "Press 'h' to close help");
	i--;
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - 6 - HEIGHT_POS * i--, WHITE, "Keyboard commands:");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE, "\"Esc\"       --> exit");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"o p         --> adjust pixel upscale");
	*j = --i;
}

static void	ft_general_options(t_canvas *canvas, int *j, int i)
{
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"w a s d q e --> move");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"Arrow keys  --> rotate");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"Space/c     --> camera move up / down");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"z           --> reset camera position");
	i--;
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"mouse left click --> select object");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"l           --> select light");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"x           --> abort selection");
	*j = --i;
}

static void	ft_last_options(t_canvas *canvas, int *j, int i)
{
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"Left Shift hold --> subtract enable");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"r g b      --> adjust R-G-B color");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"t    --> adjust bright object/light");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"1 2 3      --> adjust dimensions");
	i--;
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"Left shift + 0        --> SURPRISE!");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"(only with pixel upscale minimum 2)");
	*j = --i;
}

static void	ft_small_menu_info(t_canvas *canvas, int i)
{
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i--, WHITE,
		"Press 'h' for help");
	mlx_string_put(canvas->mlx, canvas->win,
		W_POS, WIN_H - HEIGHT_POS * i, WHITE,
		"Pixel upscale:");
	if (canvas->step > 9)
	{
		canvas->char_step[0] = '1';
		canvas->char_step[1] = canvas->step - 10 + '0';
	}
	else
	{
		canvas->char_step[0] = '0';
		canvas->char_step[1] = canvas->step + '0';
	}
	mlx_string_put(canvas->mlx, canvas->win, W_POS + 105,
		WIN_H - HEIGHT_POS * i--, WHITE,
		canvas->char_step);
}

static void	ft_print_selection(t_canvas *canvas)
{
	if (canvas->object_selected)
	{
		if (canvas->object_selected->type == SPHERE)
			mlx_string_put(canvas->mlx, canvas->win,
				IMG_W / 2 - 65, WIN_H - HEIGHT_POS - 15, WHITE,
				"   SPHERE Selected");
		else if (canvas->object_selected->type == PLANE)
			mlx_string_put(canvas->mlx, canvas->win,
				IMG_W / 2 - 65, WIN_H - HEIGHT_POS - 15, WHITE,
				"   PLANE Selected");
		else if (canvas->object_selected->type == CYLINDER)
			mlx_string_put(canvas->mlx, canvas->win,
				IMG_W / 2 - 65, WIN_H - HEIGHT_POS - 15, WHITE,
				"  CYLINDER Selected");
	}
	else if (canvas->light_selected)
		mlx_string_put(canvas->mlx, canvas->win,
			IMG_W / 2 - 65, WIN_H - HEIGHT_POS - 15, WHITE,
			"   LIGHT Selected");
	else
		return ;
	mlx_string_put(canvas->mlx, canvas->win,
		IMG_W / 2 - 65, WIN_H - HEIGHT_POS, WHITE,
		" 'x' key to unselect");
}

void	ft_menu(t_canvas *canvas)
{
	int	i;

	ft_print_selection(canvas);
	if (canvas->help)
	{
		i = 22;
		ft_top_menu_options(canvas, &i, i);
		ft_general_options(canvas, &i, i);
		ft_last_options(canvas, &i, i);
	}
	else
	{
		i = 2;
		ft_small_menu_info(canvas, i);
	}
	mlx_string_put(canvas->mlx, canvas->win, canvas->local_x.next.x
		+ canvas->local_x.x_str,
		canvas->local_x.next.y + canvas->local_x.y_str, WHITE, "X");
	mlx_string_put(canvas->mlx, canvas->win, canvas->local_y.next.x
		+ canvas->local_y.x_str,
		canvas->local_y.next.y + canvas->local_y.y_str, WHITE, "Y");
	mlx_string_put(canvas->mlx, canvas->win, canvas->local_z.next.x
		+ canvas->local_z.x_str,
		canvas->local_z.next.y + canvas->local_z.y_str, WHITE, "Z");
}
