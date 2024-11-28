#include "minirt.h"

void	operations_testing(void)
{
	// t_tuple	result;
	t_tuple	point1;
	// t_tuple	point2;
	ft_tuple_init(&point1, (t_point){1,2,3}, T_VECTOR);
	// ft_tuple_init(&point2, (t_point) {0,0,1}, T_VECTOR);
	// ft_print_tuple(point1, "point1");
	// ft_print_tuple(point2, "point2");
	// ft_print_tuple(ft_add_tuple(point1, point2), "add");
	// ft_print_tuple(ft_sub_tuple(point1, point2), "sub");
	// printf("\n");
	// printf("magn %f\n", ft_magn_tuple(point2));
	// printf("\n");
	// ft_print_tuple(ft_neg_tuple(point1), "neg");
	// printf("\n");
	// ft_print_tuple(ft_norm_vector(point2), "normalize");
	// printf("\n");
	// printf("dotprod = %lf\n", ft_dotprod_vector(point2, point2));
	// printf("\n");
	// printf("dotprod = %lf\n", ft_dotprod_vector(point1, point2));
	// printf("\n");
	// result = ft_crossprod_vector((t_tuple){1,0,0,T_VECTOR}, (t_tuple){0,1,0,T_VECTOR});
	// ft_print_tuple(result, "Cross Prod");
	// printf("\n");
	t_matrix A;
	t_matrix B;
	t_matrix C;
	A = ft_create_matrix(4, 4, 0);
	B = ft_create_matrix(4, 4, 0);
	C = ft_create_matrix(4, 4, 0);
	ft_set_matrix_values(&A, (double[4][4]){{1,2,3,4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}});
	ft_set_matrix_values(&B, (double[4][4]){{-2,1,2,3}, {3, 2, 1, -1}, {4, 3, 6, 5}, {1, 2, 7, 8}});
	printf("Matrix A:\n");
	ft_print_matrix(A);
	printf("Matrix B:\n");
	ft_print_matrix(B);
	C = ft_matrix_mult(A, B);
	printf("Matrix Result:\n");
	ft_print_matrix(C);
	printf("Matrix mult with tuple:\n");
	printf("Matrix A:\n");
	ft_print_matrix(A);
	printf("Tuple point1:\n");
	ft_print_tuple(point1, "point1");
}
