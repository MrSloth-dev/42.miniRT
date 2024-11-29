#include "minirt.h"

double ft_determinant_mtx_two_by_two(t_matrix m, int r, int c)
{

	return (m.data[r][c] * m.data[r + 1][c + 1] - m.data[r + 1][c] * m.data[r][c + 1]);
}


