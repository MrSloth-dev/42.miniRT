#include "minirt.h"

t_matrix	ft_submatrix(t_matrix src, int row, int col)
{
	t_matrix	dst;
	int			r;
	int			c;
	int			rs;
	int			cs;

	ft_assert(!(src.rows <= row || src.cols <= col), "ft_submatrix\n");
	dst = ft_create_matrix(src.rows - 1, src.cols - 1, 0);
	r = 0;
	rs = -1;
	while (++rs < src.rows)
	{
		if (rs == row)
			continue ;
		cs = -1;
		c = 0;
		while (++cs < src.cols)
		{
			if (cs == col)
				continue ;
			dst.data[r][c] = src.data[rs][cs];
			c++;
		}
		r++;
	}
	return (dst);
}

double	ft_minor(t_matrix m, int row, int col)
{
	return (ft_determinant(ft_submatrix(m, row, col)));
}

double	ft_cofactor(t_matrix m, int row, int col)
{
	if ((row + col) % 2 == 1)
		return (-ft_minor(m, row, col));
	else
		return (ft_minor(m, row, col));
}

double	ft_determinant(t_matrix m)
{
	double	det;
	int		c;

	c = -1;
	det = 0;
	ft_assert(m.cols ==m.rows, "Matrix not square!");
	if (m.cols == 2)
		det = m.data[0][0] * m.data[1][1] - m.data[1][0] * m.data[0][1];
	else
		while (++c < m.cols)
			det += m.data[0][c] * ft_cofactor(m, 0, c);
	return (det);
}

t_matrix ft_invert_matrix(t_matrix m)
{
	t_matrix temp;
	double det;
	t_iter	h;

	h = ft_iter(-1);
	det = ft_determinant(m);
	printf("%f\n\n", det);
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
