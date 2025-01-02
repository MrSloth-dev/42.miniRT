#include "minirt.h"

double	ft_cofactor(t_matrix m, int row, int col)
{
	if ((row + col) % 2 == 1)
		return (-ft_minor(m, row, col));
	else
		return (ft_minor(m, row, col));
}
