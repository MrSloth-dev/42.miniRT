#include "minirt.h"

double ft_determinant_mtx_two_by_two(t_matrix m, int r, int c)
{
	ft_assert(!(r + 2 > m.rows || c + 2 > m.cols), "ft_determinant_mtx_two_by_two\n");
	return (m.data[r][c] * m.data[r + 1][c + 1] - m.data[r + 1][c] * m.data[r][c + 1]);
}

t_matrix	ft_submatrix(t_matrix src, int row, int col)
{
	t_matrix dst;
	int	r;
	int	c;
	int	rs;
	int	cs;

	ft_assert(!(src.rows <= row || src.cols <= col), "ft_submatrix\n");
	dst = ft_create_matrix(src.rows - 1, src.cols - 1, 0);
	r = 0;
	rs = -1;
	while(++rs < src.rows)
	{
		if (rs == row)
			continue ;
		cs = -1;
		c = 0;
		while(++cs < src.cols)
		{
			if (cs == col)
				continue;
			dst.data[r][c] = src.data[rs][cs];
			c++;
		}
		r++;
	}
	return (dst);
}

