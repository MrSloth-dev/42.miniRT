/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:09:41 by ataboada          #+#    #+#             */
/*   Updated: 2024/05/23 09:52:10 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Calculates whether the specified ray intersects the cube.
void	ft_cube_intersections(t_intrs **xs, t_shapes *cube, t_ray r)
{
	double	xt[2];
	double	yt[2];
	double	zt[2];
	double	tmin;
	double	tmax;

	ft_cube_check_axis(xt, r.origin.x, r.direction.x);
	ft_cube_check_axis(yt, r.origin.y, r.direction.y);
	ft_cube_check_axis(zt, r.origin.z, r.direction.z);
	tmin = fmax(fmax(xt[0], yt[0]), zt[0]);
	tmax = fmin(fmin(xt[1], yt[1]), zt[1]);
	if (tmin > tmax)
		return ;
	ft_add_sorted_intersection(xs, cube, tmin);
	ft_add_sorted_intersection(xs, cube, tmax);
}

// Checks if the specified ray intersects the cube.
void	ft_cube_check_axis(double *t, double origin, double direction)
{
	double	tmin_numerator;
	double	tmax_numerator;
	double	temp;

	tmin_numerator = -1 - origin;
	tmax_numerator = +1 - origin;
	if (fabs(direction) >= EPSILON)
	{
		t[0] = tmin_numerator / direction;
		t[1] = tmax_numerator / direction;
	}
	else
	{
		t[0] = tmin_numerator * INFINITY;
		t[1] = tmax_numerator * INFINITY;
	}
	if (t[0] > t[1])
	{
		temp = t[0];
		t[0] = t[1];
		t[1] = temp;
	}
}

// Returns the normal vector at the specified point on the cube.
t_vec3	ft_cube_normal_at(t_point point)
{
	double	max;

	max = fmax(fabs(point.x), fmax(fabs(point.y), fabs(point.z)));
	if (max == fabs(point.x))
		return ((t_vec3){point.x, 0, 0, 0});
	else if (max == fabs(point.y))
		return ((t_vec3){0, point.y, 0, 0});
	return ((t_vec3){0, 0, point.z, 0});
}
