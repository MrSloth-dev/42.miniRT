#include "minirt.h"

t_matrix	ft_scale_matrix(double x, double y, double z)
{
	t_matrix	temp;

	temp = ft_create_matrix(4, 4, 1);
	temp.data[0][0] = x;
	temp.data[1][1] = y;
	temp.data[2][2] = z;
	return (temp);
}
/*
given  4, 5, 6

on identity matrix
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1

then
4 0 0 0
0 5 0 0
0 0 6 0
0 0 0 1

*/
