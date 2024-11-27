/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:34:52 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/16 11:39:49 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Initializes a t_pattern struct with the given type and colors.
t_pattern	ft_create_pattern(char type, t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.type = NONE;
	if (type == 'S')
		pattern.type = STRIPES;
	else if (type == 'G')
		pattern.type = GRADIENT;
	else if (type == 'R')
		pattern.type = RING;
	else if (type == 'C')
		pattern.type = CHECKERS;
	else if (type == 'X')
		pattern.type = XPM;
	pattern.a = a;
	pattern.b = b;
	pattern.transform = ft_create_matrix(4, 4, YES);
	pattern.inverted = ft_create_matrix(4, 4, YES);
	pattern.xpm = (t_canvas){0};
	return (pattern);
}

// Returns the color of the pattern at the specified point.
t_color	ft_pattern_at_shape(t_pattern p, t_shapes *object, t_point world_point)
{
	t_point	object_pt;
	t_point	pattern_pt;

	object_pt = ft_multiply_matrix_tuple(object->inverted, world_point);
	pattern_pt = ft_multiply_matrix_tuple(p.inverted, object_pt);
	if (p.type == STRIPES)
		return (ft_stripe_at(p, object->type, pattern_pt));
	else if (p.type == GRADIENT)
		return (ft_gradient_at(p, pattern_pt));
	else if (p.type == RING)
		return (ft_ring_at(p, object->type, pattern_pt));
	else if (p.type == CHECKERS)
		return (ft_checkers_at(p, object->type, pattern_pt));
	else if (p.type == XPM)
	{
		if (object->type == PLANE)
			return (ft_xpm_at_shape(PLANE, p, pattern_pt));
		else if (object->type == SPHERE || object->type == CYLINDER)
			return (ft_xpm_at_shape(object->type, p, pattern_pt));
		return (ft_xpm_at(p, pattern_pt));
	}
	return ((t_color){0, 0, 0, 3});
}
