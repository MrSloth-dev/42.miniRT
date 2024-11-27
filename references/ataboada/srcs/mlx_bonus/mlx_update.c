/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:46:26 by ataboada          #+#    #+#             */
/*   Updated: 2024/06/12 14:55:56 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_update(void *ptr)
{
	t_world	*w;

	w = (t_world *)ptr;
	if (w->status_key != 0)
	{
		mlx_destroy_image(w->mlx, w->img.img);
		w->img.img = mlx_new_image(w->mlx, w->camera->hsize, w->camera->vsize);
		w->img.addr = mlx_get_data_addr(w->img.img, &w->img.bpp,
				&w->img.line_length, &w->img.endian);
		ft_update_helper(w, w->status_key);
		ft_render_threads(w->camera, w);
		mlx_put_image_to_window(w->mlx, w->win, w->img.img, (w->ui.begin
				- w->width) / 2, (UI_WIN_WIDTH / RATIO - w->height) / 2);
	}
	return (0);
}

void	ft_update_helper(t_world *w, int key)
{
	if (w->ui.flags == 2)
	{
		if (w->status_key != Z)
			w->camera->transform = ft_update_camera(w->camera->transform, key);
		else
			w->camera->transform = w->cam_reset;
		w->camera->inverted = ft_invert_matrix(w->camera->transform);
	}
	else if (w->ui.flags == 4)
		ft_update_lights(w, key);
	else if (w->ui.flags >= 8)
		ft_update_object(w, key);
}

void	ft_update_object(t_world *w, int key)
{
	t_shapes	*s;

	s = NULL;
	if (w->ui.flags == 8)
		s = (t_shapes *)w->ui.sp[w->ui.tflag % w->ui.n_objs[0]];
	else if (w->ui.flags == 16)
		s = (t_shapes *)w->ui.pl[w->ui.tflag % w->ui.n_objs[1]];
	else if (w->ui.flags == 32)
		s = (t_shapes *)w->ui.cy[w->ui.tflag % w->ui.n_objs[2]];
	else if (w->ui.flags == 64)
		s = (t_shapes *)w->ui.co[w->ui.tflag % w->ui.n_objs[3]];
	else if (w->ui.flags == 128)
		s = (t_shapes *)w->ui.cb[w->ui.tflag % w->ui.n_objs[4]];
	else if (w->ui.flags == 256)
		s = (t_shapes *)w->ui.tr[w->ui.tflag % w->ui.n_objs[5]];
	s->transform = ft_update_shapes(s->transform, key);
	s->inverted = ft_invert_matrix(s->transform);
	s->transposed = ft_transpose_matrix(s->inverted);
}
