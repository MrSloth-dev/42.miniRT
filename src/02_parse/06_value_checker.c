/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_value_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:16:33 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:23:45 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief 
 *
 * @param a 
 * @param b 
 * @param c 
 * @return 0 if have invalid numbers (returned by atod) 1 if no errors
 */
int	ft_check_values(double a, double b, double c)
{
	if (ft_is_float_equal(a, -43.42)
		|| ft_is_float_equal(b, -43.42)
		|| ft_is_float_equal(c, -43.42))
		return (0);
	return (1);
}

/**
 * @brief 
 *
 * @param tuple 
 * @return 0 if have invalid numbers (returned by atod) 1 if no errors
 */
int	ft_vector_check(t_tuple tuple)
{
	if (ft_is_float_equal(tuple.x, -43.42))
		return (0);
	if (ft_is_float_equal(tuple.y, -43.42))
		return (0);
	if (ft_is_float_equal(tuple.z, -43.42))
		return (0);
	if (ft_is_float_equal(tuple.w, -43.42))
		return (0);
	return (1);
}

/**
 * @brief 
 *
 * @param color 
 * @return 0 if it's out of bounds, 1 if it's not
 */
int	ft_rgb_check(t_color color)
{
	if (color.x < 0 || color.x > 255)
		return (0);
	if (color.y < 0 || color.y > 255)
		return (0);
	if (color.z < 0 || color.z > 255)
		return (0);
	return (1);
}

/**
 * @brief 
 *
 * @param norm 
 * @return 0 if it's out of bounds, 1 if it's not
 */
int	ft_norm_check(t_tuple norm)
{
	if (norm.x < -1 || norm.x > 1)
		return (0);
	if (norm.y < -1 || norm.y > 1)
		return (0);
	if (norm.z < -1 || norm.z > 1)
		return (0);
	if (norm.w < -1 || norm.w > 1)
		return (0);
	return (1);
}
