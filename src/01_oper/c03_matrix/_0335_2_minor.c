#include "minirt.h"

double	ft_minor(t_matrix m, int row, int col)
{
	return (ft_determinant(ft_submatrix(m, row, col)));
}
