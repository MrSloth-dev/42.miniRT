/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   41_change_obj_properties.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:00:25 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/08 02:07:55 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_change_cyl_spec(t_shapes *cyl_selected, double scl, int invert)
{
	if (!cyl_selected)
		return ;
	if (invert && scl < 0)
		scl += 0.1;
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
			ft_change_cyl_spec(canvas->object_selected, scale, 0);
	}
	else if (keysym == XK_2 && canvas->object_selected->type == CYLINDER)
		ft_change_cyl_spec(canvas->object_selected, scale, 0);
	else if (keysym == XK_3 && canvas->object_selected->type == CYLINDER)
	{
		inverted_scale = 1 - (double)canvas->shift_press / 10;
		ft_get_transf_obj(canvas->object_selected, (t_tuple){0}, (t_tuple){0},
			(t_tuple){scale, scale, scale, 0});
		ft_change_cyl_spec(canvas->object_selected, inverted_scale, 1);
	}
	else
		return (false);
	return (true);
}

static bool	ft_change_obj_position(int keysym, t_shapes *obj_sel)
{
	t_matrix	temp;

	if (keysym != XK_w && keysym != XK_s && keysym != XK_a
		&& keysym != XK_d && keysym != XK_q && keysym != XK_e)
		return (false);
	if (obj_sel->type != SPHERE)
		obj_sel->transform = ft_matrix_mult(obj_sel->transform,
				obj_sel->inv_rotate);
	temp = ft_sel_transform(keysym, obj_sel->transform);
	if (temp.cols != 1)
		obj_sel->transform = temp;
	else
		return (false);
	obj_sel->transform = ft_matrix_mult(obj_sel->transform, obj_sel->rotate);
	obj_sel->transposed = ft_transpose_matrix(obj_sel->transform);
	obj_sel->inverted = ft_invert_matrix(obj_sel->transform);
	return (true);
}

static bool	ft_change_obj_rotation(int keysym, t_shapes *obj_sel)
{
	t_matrix	rotate;

	if (keysym == XK_Left)
		rotate = ft_rotate_matrix_x(-0.1);
	else if (keysym == XK_Right)
		rotate = ft_rotate_matrix_x(0.1);
	else if (keysym == XK_Up)
		rotate = ft_rotate_matrix_z(0.1);
	else if (keysym == XK_Down)
		rotate = ft_rotate_matrix_z(-0.1);
	else
		return (false);
	obj_sel->transform = ft_matrix_mult(obj_sel->transform, rotate);
	obj_sel->rotate = ft_matrix_mult(obj_sel->rotate, rotate);
	obj_sel->inv_rotate = ft_invert_matrix(obj_sel->rotate);
	obj_sel->inverted = ft_invert_matrix(obj_sel->transform);
	return (true);
}

bool	ft_change_obj_properties(int keysym, t_canvas *canvas, bool state)
{
	if (canvas->object_selected)
	{
		state = true;
		if (ft_change_obj_dimension(keysym, canvas))
			;
		else if (ft_change_obj_position(keysym, canvas->object_selected))
			;
		else if (canvas->object_selected->type != SPHERE
			&& ft_change_obj_rotation(keysym, canvas->object_selected))
			;
		else if (ft_change_object_color(keysym, canvas))
			;
		else
			state = false;
	}
	return (state);
}
