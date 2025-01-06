/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _02_000_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_color_rgb_to_int(t_color color)
{
	return ((int)(color.x) << 16
	| (int)(color.y) << 8
	| (int)(color.z));
}

t_color	ft_color_int_to_rgb(int color)
{
	t_color	col;

	col.x = (float)(color >> 16) / 255.0f;
	col.y = (float)(color >> 8) / 255.0f;
	col.z = (float)color / 255.0f;
	return (col);
}

//convert color tuple like red (10, 0, 0) 
//to int 0xff0000 to paint pixels on mlx lib.
int	ft_get_mlx_color(t_color color)
{
	if (color.x > 10)
		color.x = 10;
	if (color.y > 10)
		color.y = 10;
	if (color.z > 10)
		color.z = 10;
	if (color.x < 0)
		color.x = 0;
	if (color.y < 0)
		color.y = 0;
	if (color.z < 0)
		color.z = 0;
	return ((int)(color.x * 25.5f) << 16
	| (int)(color.y * 25.5f) << 8
	| (int)(color.z * 25.5f));
}
