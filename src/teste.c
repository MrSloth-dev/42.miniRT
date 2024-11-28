#include "minirt.h"

int	main()
{
	// t_canvas	canvas;
	// ft_init_canvas(&canvas);
	// ft_mlx_init(&canvas);
	// ft_setup(&canvas);
	//jumpingball(&canvas);
	
//	t_color color1, color2, color;
//
//	color1 = (t_tuple){0.15, 0.40, 0.60, 3};
//	color2 = (t_tuple){0.10, 0.30, 0.20, 3};
//
//	color = ft_operator(color1, '+', color2);
//	ft_print_tuple((t_tuple)color, "teste cor");
//
//	color = ft_operator(color1, '-', color2);
//	ft_print_tuple((t_tuple)color, "teste cor");
//
//	color = ft_operator(color1, '*', color2);
//	ft_print_tuple((t_tuple)color, "teste cor");

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
