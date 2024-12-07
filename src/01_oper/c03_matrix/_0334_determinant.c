#include "minirt.h"

double	ft_determinant(t_matrix m)
{
	double	det;
	int		c;

	c = -1;
	det = 0;
	ft_assert(m.cols == m.rows, "Matrix not square!");
	if (m.cols == 2)
		det = m.data[0][0] * m.data[1][1] - m.data[1][0] * m.data[0][1];
	else
		while (++c < m.cols)
			det += m.data[0][c] * ft_cofactor(m, 0, c);
	return (det);
}
