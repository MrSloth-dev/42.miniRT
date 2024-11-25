#include "minirt.h"
#include <stdio.h>

t_matrix	ft_create_matrix(int rows, int cols)
{
	t_matrix	m;
	int	i;
	int	j;

	m.rows = rows;
	m.cols = cols;
	i = 0;
	while (i < rows)
	{
		j=0;
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
	int i, j;
	for (i = 0; i < m->rows; i++)
	{
		for (j = 0; j < m->cols; j++)
		{
			m->data[i][j] = values[j][i];
		}
	}
}

void ft_print_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.rows)
	{
		j=0;
		while (j < m.cols)
		{
			printf("%f ", m.data[j][i]);
		j++;
		}
		printf("\n");
		i++;
	}
}
