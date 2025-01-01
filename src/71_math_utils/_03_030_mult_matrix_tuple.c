#include "minirt.h"

t_tuple	ft_mult_matrix_tuple(t_matrix A, t_tuple B)
{
	t_tuple	result;

	result.x = A.data[0][0] * B.x + A.data[0][1] * B.y + A.data[0][2]
		* B.z + A.data[0][3] * B.w;
	result.y = A.data[1][0] * B.x + A.data[1][1] * B.y + A.data[1][2]
		* B.z + A.data[1][3] * B.w;
	result.z = A.data[2][0] * B.x + A.data[2][1] * B.y + A.data[2][2]
		* B.z + A.data[2][3] * B.w;
	result.w = A.data[3][0] * B.x + A.data[3][1] * B.y + A.data[3][2]
		* B.z + A.data[3][3] * B.w;
	return (result);
}
