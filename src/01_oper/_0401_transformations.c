#include "minirt.h"

t_tuple	ft_translate(t_tuple translation, t_tuple to_translate)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4]){
	{1, 0, 0, translation.x},
	{0, 1, 0, translation.y},
	{0, 0, 1, translation.z},
	{0, 0, 0, translation.w}});
	return (ft_mult_matrix_tuple(m, to_translate));
}
	// 1 0 0 2    1     1
	// 0 1 0 3 *  2  =  2
	// 0 0 1 4    3     3
	// 0 0 0 0    0     0

t_tuple	ft_scale(t_tuple scale, t_tuple to_scale)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4])
	{{scale.x, 0, 0, 0},
	{0, scale.y, 0, 0},
	{0, 0, scale.z, 0},
	{0, 0, 0, 1}});
	return (ft_mult_matrix_tuple(m, to_scale));
}

t_tuple ft_rotation_x(t_tuple tuple, double angle)
{
	t_matrix	m;
	double		rad;

	rad = angle * (M_PI / 180);
	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4])
	{{1, 0, 0, 0},
	{0, cos(rad), -sin(rad), 0},
	{0, sin(rad), cos(rad), 0},
	{0, 0, 0, 1}});
	return (ft_mult_matrix_tuple(m, tuple));
}

t_tuple ft_rotation_y(t_tuple tuple, double angle)
{
	t_matrix	m;
	double		rad;

	rad = angle * (M_PI / 180);
	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4])
	{{cos(rad), 0, sin(rad), 0},
	{0, 1, 0, 0},
	{sin(rad), 0, cos(rad), 0},
	{0, 0, 0, 1}});
	return (ft_mult_matrix_tuple(m, tuple));
}

t_tuple ft_rotation_z(t_tuple tuple, double angle)
{
	t_matrix	m;
	double		r;

	r = angle * (M_PI / 180);
	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4])
	{{cos(r), -sin(r), 0, 0},
	{sin(r), cos(r), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}});
	return (ft_mult_matrix_tuple(m, tuple));
}

// NOT IMPLEMENTED
t_tuple ft_shear(t_tuple tuple, double angle)
{
	t_matrix	m;
	double		rad;

	rad = angle * (M_PI / 180);
	m = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&m, (double [4][4])
	{{cos(rad), -sin(rad), 0, 0},
	{sin(rad), cos(rad), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}});
	return (ft_mult_matrix_tuple(m, tuple));
}
