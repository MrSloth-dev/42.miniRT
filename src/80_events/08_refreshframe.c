/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_refreshframe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:52 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_refreshframe(void *ptr)
{
	t_canvas	*canvas;

	canvas = ptr;
	mlx_destroy_image(canvas->mlx, canvas->img.img);
	canvas->img.img = mlx_new_image(canvas->mlx, IMG_W, IMG_H);
	canvas->img.addr = mlx_get_data_addr(canvas->img.img,
			&canvas->img.bits_per_pixel,
			&canvas->img.size_line, &canvas->img.endian);
	ft_update_world_camera(canvas);
	ft_render(canvas);
	ft_menu(canvas);
	return (0);
}
