/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   91_free_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:43:22 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/07 00:43:24 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_free_mlx(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->img.img);
	mlx_destroy_window(canvas->mlx, canvas->win);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
	return (1);
}
