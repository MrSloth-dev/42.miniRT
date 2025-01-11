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
#include <raylib.h>

static void	ft_top_menu_options(t_canvas *canvas, int *j, int i)
{
	(void)canvas;
	DrawText("Press 'h' to close help", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("Keyboard commands:", W_POS, WIN_H - 6 - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("\"Esc\"       --> exit", W_POS, WIN_H  - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("o p         --> adjust pixel upscale", W_POS, WIN_H  - HEIGHT_POS * i--, 5, RAYWHITE);
	*j = --i;
}

static void	ft_general_options(t_canvas *canvas, int *j, int i)
{
	(void)canvas;
	DrawText("w a s d q e --> move", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("Arrow keys  --> rotate", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("Space/c     --> camera move up / down", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("z           --> reset camera position", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("mouse left click --> select object", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("l           --> select light", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("x           --> abort selection", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	*j = --i;
}

static void	ft_last_options(t_canvas *canvas, int *j, int i)
{
	(void)canvas;
	DrawText("Left Shift hold --> subtract enable", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("r g b      --> adjust R-G-B color", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("t    --> adjust bright object/light", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("1 2 3      --> adjust dimensions", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	i--;
	DrawText("1 2 3      --> adjust dimensions", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("Left shift + 0        --> SURPRISE!", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	DrawText("(only with pixel upscale minimum 2)", W_POS, WIN_H - HEIGHT_POS * i--, 5, RAYWHITE);
	*j = --i;
}

static void	ft_small_menu_info(t_canvas *canvas, int i)
{
	(void)canvas;
	DrawText( "Press 'h' for help", W_POS, WIN_H - HEIGHT_POS * i--, 5,RAYWHITE);
	DrawText( "Pixel upscale:", W_POS, WIN_H - HEIGHT_POS * i, 5,RAYWHITE);
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
	DrawText( canvas->char_step, W_POS + 105, WIN_H - HEIGHT_POS * i--, 5,RAYWHITE);
}

static void	ft_print_selection(t_canvas *canvas)
{
	if (canvas->object_selected)
	{
		if (canvas->object_selected->type == SPHERE)
			DrawText( "   SPHERE Selected", IMG_W / 2 - 65, WIN_H - HEIGHT_POS - 15, 5,RAYWHITE);
		else if (canvas->object_selected->type == PLANE)
			DrawText( "   PLANE Selected", IMG_W / 2 - 65, WIN_H - HEIGHT_POS - 15, 5,RAYWHITE);
		else if (canvas->object_selected->type == CYLINDER)
			DrawText( "  CYLINDER Selected", IMG_W / 2 - 65, WIN_H - HEIGHT_POS - 15, 5,RAYWHITE);
	}
	else if (canvas->light_selected)
		DrawText( "   LIGHT Selected", IMG_W / 2 - 65, WIN_H - HEIGHT_POS - 15, 5,RAYWHITE);
	else
		return ;
	DrawText( " 'x' key to unselect", IMG_W / 2 - 65, WIN_H - HEIGHT_POS, 5,RAYWHITE);
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
	DrawText( "X", canvas->local_x.next.x + canvas->local_x.x_str, canvas->local_x.next.y + canvas->local_x.y_str, 5,RAYWHITE);
	DrawText( "Y", canvas->local_y.next.x + canvas->local_y.x_str, canvas->local_y.next.y + canvas->local_y.y_str, 5,RAYWHITE);
	DrawText( "Z", canvas->local_z.next.x + canvas->local_z.x_str, canvas->local_z.next.y + canvas->local_z.y_str, 5,RAYWHITE);
}
