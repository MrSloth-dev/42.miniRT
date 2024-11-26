#include "minirt.h"

void	operations_testing(void)
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
