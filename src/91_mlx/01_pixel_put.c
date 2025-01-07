/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:43:12 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:43:24 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_pixel_put(t_img *data, int x, int y, int color)
{
	char	*pxl;

	if (x < IMG_W && y < IMG_H && x > 0 && y > 0)
	{
		pxl = data->addr + (y * data->size_line + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}
