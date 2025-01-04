#include "minirt.h"

static bool	ft_camera_wasd_keys(t_matrix *m, int key)
{
	if (key == XK_a)
		*m = ft_matrix_mult(*m, ft_translation_matrix(1, 0, 0));
	else if (key == XK_d)
		*m = ft_matrix_mult(*m, ft_translation_matrix(-1, 0, 0));
	else if (key == XK_w)
		*m = ft_matrix_mult(*m, ft_translation_matrix(0, 0, -1));
	else if (key == XK_s)
		*m = ft_matrix_mult(*m, ft_translation_matrix(0, 0, 1));
	else
		return (false);
	return (true);
}

static bool	ft_camera_arrow_keys(t_matrix *m, int key)
{
	if (key == XK_Right)
		*m = ft_matrix_mult(*m, ft_rotate_matrix_y(M_PI / 20));
	else if (key == XK_Left)
		*m = ft_matrix_mult(*m, ft_rotate_matrix_y(-M_PI / 20));
	else if (key == XK_Up)
		*m = ft_matrix_mult(*m, ft_rotate_matrix_x(-M_PI / 20));
	else if (key == XK_Down)
		*m = ft_matrix_mult(*m, ft_rotate_matrix_x(M_PI / 20));
	else
		return (false);
	return (true);
}

t_matrix	ft_transform_camera_key(t_matrix m, int key)
{
	ft_matrix_mult(m, ft_scale_matrix(1.1, 1, 1.1));
	if (ft_camera_wasd_keys(&m, key))
		;
	else if (ft_camera_arrow_keys(&m, key))
		;
	else if (key == XK_space)
		return (ft_matrix_mult(m, ft_translation_matrix(0, -1, 0)));
	else if (key == XK_c)
		return (ft_matrix_mult(m, ft_translation_matrix(0, 1, 0)));
	else if (key == XK_q)
		return (ft_matrix_mult(m, ft_rotate_matrix_z(-M_PI / 20)));
	else if (key == XK_e)
		return (ft_matrix_mult(m, ft_rotate_matrix_z(M_PI / 20)));
	return (m);
}
