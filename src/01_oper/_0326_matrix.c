#include "minirt.h"

void	ft_print_matrix(t_matrix m)
{
	t_iter	h;

	h = ft_iter(0);
	while (h.r < m.rows)
	{
		h.c = 0;
		while (h.c < m.cols)
		{
			printf("% .5f    ", m.data[h.r][h.c]);
			h.c++;
		}
		printf("\n");
		h.r++;
	}
}

t_matrix	ft_matrix_mult(t_matrix A, t_matrix B)
{
	t_matrix		res;
	t_iter			h;

	h = ft_iter(0);
	ft_assert(A.cols == B.rows, "diff array size");
	res = ft_create_matrix(A.cols, B.rows, 0);
	while (h.c < A.cols)
	{
		h.r = 0;
		while (h.r < B.rows)
		{
			h.k = 0;
			while (h.k < B.rows)
			{
				res.data[h.r][h.c] += A.data[h.k][h.c] * B.data[h.r][h.k];
				h.k++;
			}
			h.r++;
		}
		h.c++;
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
	t_iter			h;

	if (a.rows != b.rows || a.cols != b.cols)
		return (0);
	h = ft_iter(-1);
	while (h.r < a.rows)
	{
		h.c = -1;
		while (++h.c < a.cols)
			if (ft_is_float_equal(a.data[h.r][h.c], b.data[h.r][h.c]) == 0)
				return (0);
	}
	return (1);
}

t_matrix	ft_transpose_matrix(t_matrix src)
{
	double	tmp;
	t_iter	h;

	h = ft_iter(-1);
	while (++h.r < src.rows)
	{
		h.c = h.r;
		while (++h.c < src.cols)
		{
			if (h.c != h.r)
			{
				tmp = src.data[h.r][h.c];
				src.data[h.r][h.c] = src.data[h.c][h.r];
				src.data[h.c][h.r] = tmp;
			}
		}
	}
	return (src);
}
