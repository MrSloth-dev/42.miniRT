/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2024/06/13 16:48:12 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_transform_camera(t_matrix m, int key)
{
	if (key == XK_a)
		return (ft_matrix_mult(m, ft_translation_matrix(1, 0, 0)));
	else if (key == XK_d)
		return (ft_matrix_mult(m, ft_translation_matrix(-1, 0, 0)));
	else if (key == XK_w)
		return (ft_matrix_mult(m, ft_translation_matrix(0, 0, -1)));
	else if (key == XK_s)
		return (ft_matrix_mult(m, ft_translation_matrix(0, 0, 1)));
	else if (key == XK_space)
		return (ft_matrix_mult(m, ft_translation_matrix(0, -1, 0)));
	else if (key == XK_c)
		return (ft_matrix_mult(m, ft_translation_matrix(0, 1, 0)));
	else if (key == XK_Right)
		return (ft_matrix_mult(m, ft_rotate_matrix_y(M_PI / 20)));
	else if (key == XK_Left)
		return (ft_matrix_mult(m, ft_rotate_matrix_y(-M_PI / 20)));
	else if (key == XK_Up)
		return (ft_matrix_mult(m, ft_rotate_matrix_x(-M_PI / 20)));
	else if (key == XK_Down)
		return (ft_matrix_mult(m, ft_rotate_matrix_x(M_PI / 20)));
	return (m);
}



bool	ft_change_step(int keysym, t_canvas *canvas)
{
	if (keysym == XK_o && canvas->step > 1)
		return (canvas->step--, true);
	if (keysym == XK_p && canvas->step < 9)
		return (canvas->step++, true);
	return (false);
}

void	ft_clear_select(t_canvas *canvas)
{
	t_list *cur;

	if (!canvas->objects && !canvas->objects->cont)
		return ;
	cur = canvas->objects;
	while (cur && cur->cont)
	{
		((t_shapes *)cur->cont)->selected = false;
		cur = cur->next;
	}
}

int	key_handler(int keysym, t_canvas *canvas)
{
	if (keysym == XK_Escape)
		close_handler(canvas);
	else if (keysym == XK_h)
		canvas->help = !canvas->help;
	else if (ft_change_step(keysym, canvas))
		;
	else if (keysym == XK_x)
		ft_clear_select(canvas);
	else
	{
		if (keysym == XK_r) // Maybe add reset to objects also
			canvas->camera.transf = canvas->camera.reset;
		else
			canvas->camera.transf = ft_transform_camera(canvas->camera.transf, keysym);
		canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
	}
	return (0);
}

void	ft_select_obj(int x, int y, t_canvas *canvas)
{
	t_ray	ray;
	t_interlst *lst;
	t_inter	*hit;

	ray.pos = ft_mult_matrix_tuple(canvas->camera.inverted, (t_tuple){0, 0, 0, 1});
	ft_ray_for_pixel(canvas->camera, x, y, &ray);
	lst = ft_intersect_world(canvas, ray);
	hit = ft_hit_inter(&lst);
	ft_clear_select(canvas);
	if (hit)
		hit->shape->selected = true;
}

int	mouse_handler_release(int mousecode, int x, int y, t_canvas *canvas)
{
	(void)x;
	(void)y;
	if (mousecode == 3)
	{
		canvas->drag = 0;
		printf("release\n");
	}
	return (0);
}

t_matrix	ft_transform_camera_mouse(t_matrix m, int key)
{
	if (key == 1)
		return (ft_matrix_mult(m, ft_rotate_matrix_y(M_PI / 20)));
	else if (key == 2)
		return (ft_matrix_mult(m, ft_rotate_matrix_y(-M_PI / 20)));
	else if (key == 3)
		return (ft_matrix_mult(m, ft_rotate_matrix_x(-M_PI / 20)));
	else if (key == 4)
		return (ft_matrix_mult(m, ft_rotate_matrix_x(M_PI / 20)));
	return (m);
}

int	mouse_motion(int x, int y, t_canvas *canvas)
{
	(void)y;
	if (canvas->drag == 1)
	{
		if (canvas->mouse_x == 0)
			canvas->mouse_x = x;
		else if (canvas->mouse_calc == 1)
			canvas->mouse_x = x;

		printf("canvas mouse x = %d\n", canvas->mouse_x);
		if (canvas->mouse_x > 200)
		{
			printf("x = %d, mouse_x = %d\n", x, canvas->mouse_x);
			canvas->camera.transf = ft_transform_camera_mouse(canvas->camera.transf, 2);
			canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
			canvas->mouse_x = 0;
		}
		else if (canvas->mouse_x < -200)
		{
			printf("x = %d, mouse_x = %d\n", x, canvas->mouse_x);
			canvas->camera.transf = ft_transform_camera_mouse(canvas->camera.transf, 1);
			canvas->camera.inverted = ft_invert_matrix(canvas->camera.transf);
			canvas->mouse_x = 0;
		}

	}
	return (0);
}


int	mouse_handler(int mousecode, int x, int y, t_canvas *canvas)
{
	if (mousecode == 3) // 5
	{
		canvas->drag = 1;
		printf("press\n");
	}
	if (mousecode == 1) // 4
		ft_select_obj(x, y, canvas);
	else if (mousecode == 4) // 5
		canvas->camera.field_v -= M_PI / 30;
	else if (mousecode == 5) // 5
		canvas->camera.field_v += M_PI / 30;
	return (0);
}

int	close_handler(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->img->img);
	mlx_destroy_window(canvas->mlx, canvas->win);
	mlx_destroy_display(canvas->mlx);
	ft_free_canvas(canvas);
	exit (0);
}

int	ft_refreshframe(void *ptr)
{
	t_canvas *canvas;

	canvas = ptr;
	mlx_destroy_image(canvas->mlx, canvas->img->img);
	canvas->img->img = mlx_new_image(canvas->mlx, IMG_W, IMG_H);
	canvas->img->addr = mlx_get_data_addr(canvas->img->img,
			&canvas->img->bits_per_pixel,
			&canvas->img->size_line, &canvas->img->endian);
	ft_update_world_camera(canvas);
	ft_render(canvas);
	ft_menu(canvas);
	return (0);
}
