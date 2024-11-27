#include "minirt.h"

t_matrix	ft_create_matrix(int rows, int cols)
{
	t_matrix	m;
	int			i;
	int			j;

	m.rows = rows;
	m.cols = cols;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (j == i)
				m.data[j][i] = 1;
			else
				m.data[j][i] = 0;
			j++;
		}
		i++;
	}
	return (m);
}

void	ft_set_matrix_values(t_matrix *m, double values[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->cols)
		{
			m->data[i][j] = values[j][i];
			j++;
		}
		i++;
	}
}

void	ft_print_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			printf("%.000f ", m.data[j][i]);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_matrix	ft_matrix_mult(t_matrix A, t_matrix B)
{
	t_matrix	res;
	int			i;
	int			j;
	int			k;

	res = ft_create_matrix(4, 4);
	i = 0;
	while (i < A.rows)
	{
		j = 0;
		while (j < B.rows)
		{
			res.data[j][i] = 0;
			k = 0;
			while (k < B.rows)
			{
				res.data[j][i] += A.data[k][i] * B.data[j][k];
				k++;
			}
			j++;
		}
		i++;
	}
	return (res);
}
/*
t_tuple	ft_mult_matrix_tuple(t_matrix A, t_tuple B)
{
	t_tuple	result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_tuple_init(&result, (t_point){0, 0, 0}, B.w);
	result.x = A.data[0][0];
	return (result);
} */
