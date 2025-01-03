/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2024/06/13 16:48:12 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	ft_change_obj_dimension(int keysym, t_canvas *canvas)
{
	if (keysym == XK_0)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0},
				 (t_tuple){1.1, 1.1, 1.1, 0});
	else if (keysym == XK_9)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0},
				 (t_tuple){0.9, 0.9, 0.9, 0});
	else if (keysym == XK_8 && canvas->object_selected->type == CYLINDER)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0},
				 (t_tuple){1, 1.2, 1, 0});
	else if (keysym == XK_7 && canvas->object_selected->type == CYLINDER)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0},
				 (t_tuple){1, 0.8, 1, 0});
	else
		return (false);
	return (true);
}

static bool	ft_change_obj_position(int keysym, t_canvas *canvas)
{
	if (keysym == XK_w)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0, 0.3, 0, 0}, (t_tuple){0},
				 (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_s)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0, -0.3, 0, 0}, (t_tuple){0},
				 (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_a )
		ft_get_transf_obj(canvas->object_selected, (t_tuple){-0.3, 0, 0, 0}, (t_tuple){0},
				 (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_d)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0.3, 0, 0, 0}, (t_tuple){0},
				 (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_q)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0, 0, 0.3, 0}, (t_tuple){0},
				 (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_e)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0, 0, -0.3, 0}, (t_tuple){0},
				 (t_tuple){1, 1, 1, 0});
	else
		return (false);
	return (true);
}

static bool	ft_change_obj_rotation(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Left )
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){-0.3, 0, 0, 0},
				 (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_Right)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0.3, 0, 0, 0},
				 (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_Up)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0, 0, 0.3, 0},
				 (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_Down)
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0, 0, -0.3, 0},
				 (t_tuple){1, 1, 1, 0});
	else
		return (false);
	return (true);
}

bool	ft_change_obj_propriety(int keysym, t_canvas *canvas, bool state)
{
	if (canvas->object_selected)
	{
		state = true;
		if (ft_change_obj_dimension(keysym, canvas))
			;
		else if (ft_change_obj_position(keysym, canvas))
			;
		else if (canvas->object_selected->type != SPHERE 
				&& ft_change_obj_rotation(keysym, canvas))
			;
		else
			state = false;
	}
	return (state);
}


int	key_handler(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Escape)
		close_handler(canvas);
	else if (keysym == XK_h)
		canvas->help = !canvas->help;
	else if (ft_change_resolution(keysym, canvas))
		;
	else if (ft_change_obj_propriety(keysym, canvas, false))
		;
	else if (keysym == XK_x)
		ft_clear_select(canvas);
	else
	{
		if (keysym == XK_r) // Maybe add reset to objects also
			canvas->camera.transf = canvas->camera.reset;
		else if (!canvas->object_selected)
			canvas->camera.transf = ft_transform_camera_key(canvas->camera.transf, keysym);
		canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	}
	return (0);
}

int	mouse_handler_release(int mousecode, int x, int y, t_canvas *canvas)
{
	(void)x;
	(void)y;
	if (mousecode == 3)
		canvas->mouse_drag = 0;
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_canvas *canvas)
{
	if (mousecode == 3)
		canvas->mouse_drag = 1;
	if (mousecode == 1) // 4
		ft_select_obj(x, y, canvas);
	else if (mousecode == 4) // 5
		canvas->camera.field_v -= M_PI / 30;
	else if (mousecode == 5) // 5
		canvas->camera.field_v += M_PI / 30;
	return (0);
}

int	close_handler(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->img->img);
	mlx_destroy_window(canvas->mlx, canvas->win);
	mlx_destroy_display(canvas->mlx);
	ft_free_canvas(canvas);
	exit (0);
}

int	ft_refreshframe(void *ptr)
{
	t_canvas *canvas;

	canvas = ptr;
	mlx_destroy_image(canvas->mlx, canvas->img->img);
	canvas->img->img = mlx_new_image(canvas->mlx, IMG_W, IMG_H);
	canvas->img->addr = mlx_get_data_addr(canvas->img->img,
			&canvas->img->bits_per_pixel,
			&canvas->img->size_line, &canvas->img->endian);
	ft_update_world_camera(canvas);
	ft_render(canvas);
	ft_menu(canvas);
	return (0);
}
