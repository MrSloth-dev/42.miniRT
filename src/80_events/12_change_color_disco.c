/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_change_color_disco.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:59:42 by isilva-t          #+#    #+#             */
/*   Updated: 2025/01/06 09:59:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_set_color(t_canvas *canvas, double r, double g, double b)
{
	t_objects	*cur;
	t_shapes	*cur_shape;
	double		dance;

	dance = canvas->disco_dance;
	canvas->light.color = (t_tuple){r, g, b, 3};
	cur = canvas->objects;
	while (cur)
	{
		cur_shape = cur->cont;
		if (cur_shape->type != PLANE)
		{
			ft_get_transf_obj(cur_shape,
				(t_tuple){dance, dance, dance, 0},
				(t_tuple){0}, (t_tuple){1, 1, 1, 0});
		}
		cur = cur->next;
	}
	canvas->disco_dance = -dance;
}

void	ft_change_color_disco(t_canvas *canvas, int *type)
{
	double		hi;
	double		lo;

	hi = 10;
	lo = 2;
	*type = *type + 1;
	if (*type == 1)
		ft_set_color(canvas, hi, lo, lo);
	else if (*type == 2)
		ft_set_color(canvas, lo, hi, hi);
	else if (*type == 3)
		ft_set_color(canvas, lo, lo, hi);
	else if (*type == 4)
		ft_set_color(canvas, hi, hi, lo);
	else if (*type == 5)
		ft_set_color(canvas, lo, hi, lo);
	else if (*type == 6)
		ft_set_color(canvas, hi, lo, hi);
	else if (*type == 7)
		ft_set_color(canvas, hi + 10, hi + 10, hi + 10);
	if (*type == 7)
		*type = 0;
}
