#include "minirt.h"

t_matrix	ft_invert_matrix(t_matrix m)
{
	t_matrix	temp;
	double		det;
	t_iter		h;

	h = ft_iter(-1);
	det = ft_determinant(m);
	ft_assert(det != 0, "Matrix not invertible!\n");
	temp = ft_create_matrix(m.rows, m.cols, 0);
	while (++h.r < m.rows)
	{
		h.c = -1;
		while (++h.c < m.cols)
			temp.data[h.c][h.r] = ft_cofactor(m, h.r, h.c) / det;
	}
	return (temp);
}
