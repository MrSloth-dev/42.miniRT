#include "minirt.h"

// int	main()
// {
// 	t_matrix a, b;
// 	double m_a[4][4] = {
// 		{1, 5, 2, 6},
// 		{-3, 2, -2, 3},
// 		{3, 8, 7, 6},
// 		{5, 7, 3, 2}
// 	};
//
// 	a = ft_create_matrix(3, 3, 0); 
//
// 	for (int r = 0; r < a.rows; r++) {
//         for (int c = 0; c < a.cols; c++) {
//             a.data[r][c] = m_a[r][c];
//         }
//     }
// 	printf("\n");
// 	ft_print_matrix(a);
//
// 	printf("\n");
// 	printf("rem 0 0\n");
// 	b = ft_submatrix(a, 0, 0);
// 	ft_print_matrix(b);
//
// 	printf("\n");
// 	printf("rem 1 0\n");
// 	b = ft_submatrix(a, 1, 0);
// 	ft_print_matrix(b);
//
// 	printf("\n");
// 	printf("rem 2 2\n");
// 	b = ft_submatrix(a, 2, 2);
// 	ft_print_matrix(b);
//
// 	printf("\n");
// 	printf("rem 3 3\n");
// 	b = ft_submatrix(a, 3, 3);
// 	ft_print_matrix(b);
//
// 	printf("\n");
// 	printf("rem 0 3\n");
// 	b = ft_submatrix(a, 0, 3);
// 	ft_print_matrix(b);
//
// 	return (0);
// }

int	main()
{
	t_matrix a ;
	double m_a[4][4] = {
		{1, 5, 2, 6},
		{-3, 2, -2, 3},
		{3, 8, 7, 6},
		{5, 7, 3, 2}
	};
	double deter;

	a = ft_create_matrix(3, 3, 0);  
	for (int r = 0; r < a.rows; r++) {
        for (int c = 0; c < a.cols; c++) {
            a.data[r][c] = m_a[r][c];
        }
    }

	deter = ft_determinant_mtx_two_by_two(a, 0, 0);
	printf("determinant: %f\n", deter);

	deter = ft_determinant_mtx_two_by_two(a, 0, 1);
	printf("determinant: %f\n", deter);

	deter = ft_determinant_mtx_two_by_two(a, 1, 0);
	printf("determinant: %f\n", deter);

	deter = ft_determinant_mtx_two_by_two(a, 2, 2);
	printf("determinant: %f\n", deter);

	return (0);
}
// int	main()
// {
// 	t_matrix a, b;
// 	double m_a[4][4] = {
// 		{1, 2, 3, 4},
// 		{5, 6, 7, 8},
// 		{9, 8, 7, 6},
// 		{5, 4, 3, 2}
// 	};
// 	double m_b[4][4] = {
// 		{-2, 1, 2, 3},
// 		{3, 2, 1, -1},
// 		{4, 3, 6, 5},
// 		{1, 2, 7, 8}
// 	};
//
//
// 	a = ft_create_matrix(4, 4, 1);
// 	b = ft_create_matrix(4, 4, 1);
//
// 	for (int c = 0; c < 4; c++) {
//         for (int r = 0; r < 4; r++) {
//             a.data[r][c] = m_a[c][r];
//         }
//     }
// 	for (int c = 0; c < 4; c++) {
//         for (int r = 0; r < 4; r++) {
//             b.data[r][c] = m_b[c][r];
//         }
//     }
// 	
// 	return (0);
// }
