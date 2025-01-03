#include "minirt.h"

t_matrix	ft_transform_camera_key(t_matrix m, int key)
{
	ft_matrix_mult(m, ft_scale_matrix(1.1, 1, 1.1));
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
	else if (key == XK_q)
		return (ft_matrix_mult(m, ft_rotate_matrix_z(-M_PI / 20)));
	else if (key == XK_e)
		return (ft_matrix_mult(m, ft_rotate_matrix_z(M_PI / 20)));

	return (m);
}
