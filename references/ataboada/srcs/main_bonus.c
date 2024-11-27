/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:32:29 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/13 13:58:35 by ataboada         ###   ########.fr       */
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
	ft_set_camera(&w);
	ft_set_ui(&w);
	ft_open_window(&w);
	ft_render_threads(w.camera, &w);
	ft_set_hooks(&w);
	mlx_put_image_to_window(w.mlx, w.win, w.img.img, (w.ui.begin - w.width) / 2,
		(UI_WIN_WIDTH / RATIO - w.height) / 2);
	mlx_put_image_to_window(w.mlx, w.win, w.img2.img, w.ui.begin, 0);
	ft_create_strings(&w);
	mlx_loop(w.mlx);
}

void	ft_set_camera(t_world *w)
{
	w->camera = ft_create_camera(w->width, w->height, w->cam_fov * DEG2RAD);
	w->camera->transform = ft_view_transform_matrix(w->cam_coords,
			ft_op(w->cam_orient, '+', w->cam_coords), (t_point){0, 1, 0, 0});
	w->camera->inverted = ft_invert_matrix(w->camera->transform);
	w->cam_reset = w->camera->transform;
}
