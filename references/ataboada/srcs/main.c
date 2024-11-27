/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:43:54 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/18 12:38:49 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_world	w;

	if (ac != 2)
		ft_perror(NULL, NULL, "Invalid number of arguments");
	ft_bzero(&w, sizeof(t_world));
	w.width = WIDTH;
	w.height = WIDTH / RATIO;
	ft_parser(av[1], &w);
	ft_open_window(&w);
	ft_render(w.camera, &w);
	ft_set_hooks(&w);
	mlx_put_image_to_window(w.mlx, w.win, w.img.img, 0, 0);
	mlx_loop(w.mlx);
}
