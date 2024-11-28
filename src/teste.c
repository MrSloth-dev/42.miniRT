#include "minirt.h"

int	main()
{
	t_matrix a, b, c;
	double m_a[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	double m_b[4][4] = {
		{-2, 1, 2, 3},
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}
	};


	a = ft_create_matrix(4, 4);
	b = ft_create_matrix(4, 4);

	for (int c = 0; c < 4; c++) {
        for (int r = 0; r < 4; r++) {
            a.data[r][c] = m_a[c][r];
        }
    }
	for (int c = 0; c < 4; c++) {
        for (int r = 0; r < 4; r++) {
            b.data[r][c] = m_b[c][r];
        }
    }
	
	c = ft_matrix_mult(a, b);
	ft_print_matrix(c);
	printf("\n");
	c = ft_transpose_matrix(c);
	ft_print_matrix(c);

	t_tuple b = (t_tuple){1, 2, 3, 1};
	ft_print_tuple(b, "b");
	t_matrix A;
	
	A = ft_create_matrix(4, 4);
	ft_set_matrix_values(&A, (double[4][4]){{1,2,3,4},{2,4,4,2},{8,6,4,1},{0,0,0,1}});
	ft_print_matrix(A);
	t_tuple res = ft_mult_matrix_tuple(A, b);
	ft_print_tuple(res, "res");
	return (0);
}
