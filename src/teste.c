#include "minirt.h"

void teste_matrix_mult()
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


	a = ft_create_matrix(4, 4, 0);
	b = ft_create_matrix(4, 4, 0);

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

}

//testing multiplication matrix by  tuple
void	teste_matrix_mult_tuple()
{
	t_tuple b = (t_tuple){-1, 24, 3.2, 0};
	ft_print_tuple(b, "b");
	t_matrix A;
	
	A = ft_create_matrix(4, 5, 1);
	ft_print_matrix(A);
	t_tuple res = ft_mult_matrix_tuple(A, b);
	ft_print_tuple(res, "res");
}

int	main()
{
    teste_matrix_mult();
    teste_matrix_mult_tuple();
	return (0);
}
