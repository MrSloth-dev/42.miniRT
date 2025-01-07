/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   41_change_obj_propriety.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:00:25 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 10:00:28 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_change_cyl_spec(t_shapes *cyl_selected, double scl)
{
	if (!cyl_selected)
		return ;
	cyl_selected->cyl.size.height *= scl;
	cyl_selected->cyl.size.max = cyl_selected->cyl.size.height / 2;
	cyl_selected->cyl.size.min = -cyl_selected->cyl.size.max;
}

static bool	ft_change_obj_dimension(int keysym, t_canvas *canvas)
{
	double	scale;
	double	inverted_scale;

	scale = (double)canvas->shift_press / 10 + 1;
	if (canvas->object_selected->type == PLANE)
		return (false);
	if (keysym == XK_1)
	{
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0},
			(t_tuple){scale, scale, scale, 0});
		if (canvas->object_selected->type == CYLINDER)
			ft_change_cyl_spec(canvas->object_selected, scale);
	}
	else if (keysym == XK_2 && canvas->object_selected->type == CYLINDER)
		ft_change_cyl_spec(canvas->object_selected, scale);
	else if (keysym == XK_3 && canvas->object_selected->type == CYLINDER)
	{
		inverted_scale = 1 - (double)canvas->shift_press / 10;
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0},
			(t_tuple){scale, scale, scale, 0});
		ft_change_cyl_spec(canvas->object_selected, inverted_scale);
	}
	else
		return (false);
	return (true);
}

static bool	ft_change_obj_position(int keysym, t_canvas *canvas)
{
	if (keysym == XK_w)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0, 0.3, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_s)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0, -0.3, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_a)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){-0.3, 0, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_d)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0.3, 0, 0, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_q)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0, 0, 0.3, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_e)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0, 0, -0.3, 0}, (t_tuple){0}, (t_tuple){1, 1, 1, 0});
	else
		return (false);
	return (true);
}

static bool	ft_change_obj_rotation(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Left)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0}, (t_tuple){-0.3, 0, 0, 0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_Right)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0}, (t_tuple){0.3, 0, 0, 0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_Up)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0}, (t_tuple){0, 0, 0.3, 0}, (t_tuple){1, 1, 1, 0});
	else if (keysym == XK_Down)
		ft_get_transf_obj(canvas->object_selected,
			(t_tuple){0}, (t_tuple){0, 0, -0.3, 0}, (t_tuple){1, 1, 1, 0});
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
		else if (ft_change_object_color(keysym, canvas))
			;
		else
			state = false;
	}
	return (state);
}
