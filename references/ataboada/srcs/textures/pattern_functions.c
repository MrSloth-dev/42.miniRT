/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:22:15 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/24 08:34:30 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Returns the color of the stripe at the specified point.
t_color	ft_stripe_at(t_pattern pattern, int shape_type, t_point point)
{
	double	frequency;
	t_uv	uv;
	double	u;

	frequency = 10;
	if (shape_type == PLANE)
		frequency = 0.5;
	if (shape_type == PLANE || shape_type == TRIANGLE)
		u = point.x;
	else
	{
		uv = ft_cartesian_to_spherical(point);
		u = uv.u;
	}
	if ((int)floor(u * frequency) % 2 == 0)
		return (pattern.a);
	else
		return (pattern.b);
}

// Returns the color of the gradient at the specified point.
t_color	ft_gradient_at(t_pattern pattern, t_point point)
{
	t_color	distance;
	double	fraction;

	distance = ft_op(pattern.b, '-', pattern.a);
	fraction = point.x;
	return (ft_op(pattern.a, '+', ft_ops(distance, '*', fraction)));
}

// Returns the color of the ring at the specified point.
t_color	ft_ring_at(t_pattern pattern, int shape_type, t_point point)
{
	double	dist;

	dist = 1.5 * sqrt(pow(point.x, 2) + pow(point.z, 2));
	if (shape_type == SPHERE)
		dist = 4 * sqrt(pow(point.x, 2) + pow(point.y, 2));
	else if (shape_type == CYLINDER)
		dist = 5 * sqrt(pow(point.y, 2) + pow(point.y, 2));
	else if (shape_type == CONE)
		dist = 5 * sqrt(pow(point.x, 2) + pow(point.z, 2));
	else if (shape_type == CUBE)
		dist = 15 * sqrt(pow(point.x, 2) + pow(point.y, 2) + pow(point.z, 2));
	else if (shape_type == TRIANGLE)
		dist = 10 * sqrt(pow(point.x, 2) + pow(point.y, 2) + pow(point.z, 2));
	if ((int)dist % 2 == 0)
		return (pattern.a);
	else
		return (pattern.b);
}

// Returns the color of the checkers at the specified point.
t_color	ft_checkers_at(t_pattern pattern, int shape_type, t_point point)
{
	t_uv	uv;
	double	size;

	if (shape_type == PLANE || shape_type == TRIANGLE || shape_type == CUBE)
	{
		size = 0.5;
		if (shape_type == TRIANGLE)
			size = 5;
		if (((int)floor(point.x * size)
				+ (int)floor(point.y * size)
				+ (int)floor(point.z * size)) % 2 == 0)
			return (pattern.a);
		else
			return (pattern.b);
	}
	else
	{
		size = 10;
		uv = ft_cartesian_to_spherical(point);
		if (((int)floor(uv.u * size) + (int)floor(uv.v * size)) % 2 == 0)
			return (pattern.a);
		else
			return (pattern.b);
	}
}

// Converts a cartesian point to spherical coordinates. That way, checkers and
// stripes can be applied to the sphere, cylinder and cone shapes.
t_uv	ft_cartesian_to_spherical(t_point point)
{
	t_uv	uv;
	double	theta;
	double	phi;

	theta = atan2(point.z, point.x);
	phi = acos(point.y / sqrt(point.x * point.x + point.y * point.y
				+ point.z * point.z));
	uv.u = theta / (2 * M_PI);
	uv.v = phi / M_PI;
	return (uv);
}
