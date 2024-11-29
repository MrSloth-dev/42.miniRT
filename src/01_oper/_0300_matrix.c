#include "minirt.h"
#include <math.h>

t_matrix	ft_create_matrix(int rows, int cols, int identity)
{
	t_matrix	m;
	int			r;
	int			c;

	m.rows = rows;
	m.cols = cols;
	r = 0;
	while (r < rows)
	{
		c = 0;
		while (c < cols)
		{
			if (identity && rows == cols && c == r)
				m.data[r][c] = 1;
			else
				m.data[r][c] = 0;
			c++;
		}
		r++;
	}
	return (m);
}

void	ft_set_matrix_values(t_matrix *m, double values[4][4])
{
	int	r;
	int	c;

	r = 0;
	while (r < m->rows)
	{
		c = 0;
		while (c < m->cols)
		{
			m->data[r][c] = values[r][c];
			c++;
		}
		r++;
	}
}

void	ft_print_matrix(t_matrix m)
{
	int	c;
	int	r;

	r = 0;
	while (r < m.rows)
	{
		c = 0;
		while (c < m.cols)
		{
			printf("% .5f    ", m.data[r][c]);
			c++;
		}
		printf("\n");
		r++;
	}
}

t_matrix	ft_matrix_mult(t_matrix A, t_matrix B)
{
	t_matrix	res;
	int			c;
	int			r;
	int			k;

	ft_assert(A.cols == B.rows, "diff array size");
	res = ft_create_matrix(A.cols, B.rows, 0);
	c = 0;
	while (c < A.cols)
	{
		r = 0;
		while (r < B.rows)
		{
			// res.data[r][c] = 0;
			k = 0;
			while (k < B.rows)
			{
				res.data[r][c] += A.data[k][c] * B.data[r][k];
				k++;
			}
			r++;
		}
		c++;
	}
	return (res);
}

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

int	ft_are_matrixes_equal(t_matrix a, t_matrix b)
{
	int	r;
	int	c;

	if (a.rows != b.rows || a.cols != b.cols)
		return (0);
	r = -1;
	while (++r < a.rows)
	{
		c = -1;
		while (++c < a.cols)
			if (ft_is_float_equal(a.data[r][c], b.data[r][c]) == 0)
				return (0);
	}
	return (1);
}

t_matrix	ft_transpose_matrix(t_matrix src)
{
	int		r;
	int		c;
	double	tmp;

	r = -1;
	while (++r < src.rows)
	{
		c = r;
		while (++c < src.cols)
		{
			if (c != r)
			{
				tmp = src.data[r][c];
				src.data[r][c] = src.data[c][r];
				src.data[c][r] = tmp;
			}
		}
	}
	return (src);
}
