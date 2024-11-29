#include "minirt.h"

void teste_tuple_op()
{
	t_tuple	result;
	t_tuple	point1;
	t_tuple	point2;
	ft_tuple_init(&point1, (t_point){1,2,3}, T_VECTOR);
	ft_tuple_init(&point2, (t_point) {0,0,1}, T_VECTOR);
	ft_print_tuple(point1, "point1");
	ft_print_tuple(point2, "point2");
	ft_print_tuple(ft_add_tuple(point1, point2), "add");
	ft_print_tuple(ft_sub_tuple(point1, point2), "sub");
	printf("\n");
	printf("magn %f\n", ft_magn_tuple(point2));
	printf("\n");
	ft_print_tuple(ft_neg_tuple(point1), "neg");
	printf("\n");
	ft_print_tuple(ft_norm_vector(point2), "normalize");
	printf("\n");
	printf("dotprod = %lf\n", ft_dotprod_vector(point2, point2));
	printf("\n");
	printf("dotprod = %lf\n", ft_dotprod_vector(point1, point2));
	printf("\n");
	result = ft_crossprod_vector((t_tuple){1,0,0,T_VECTOR}, (t_tuple){0,1,0,T_VECTOR});
	ft_print_tuple(result, "Cross Prod");
	printf("\n");
}
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
    teste_tuple_op();
    teste_matrix_mult();
    teste_matrix_mult_tuple();
	return (0);
}
