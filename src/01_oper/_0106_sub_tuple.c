#include "minirt.h"

t_tuple	ft_sub_tuple(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	result;

	ft_assert(!(tuple1.w == 0 && tuple2.w == 1), "error subtractiong tuples\n");
	result.x = tuple1.x - tuple2.x;
	result.y = tuple1.y - tuple2.y;
	result.z = tuple1.z - tuple2.z;
	result.w = tuple1.w - tuple2.w;
	ft_assert((result.w != -1), "error subtractiong tuples\n");
	return (result);
}

void	test_ft_sub_tuple()
{
	t_tuple t1, t2, res;
//
	t1.x = 45, t1.y = 55, t1.z = 05 ,t1.w = 1;
	t2.x = 15, t2.y = 15, t2.z = 15 ,t2.w = 0;
	res = ft_sub_tuple(t1, t2);
	ft_print_tuple(res, "ok\n");

	t1.x = 15, t1.y = 15, t1.z = 15 ,t1.w = 0;
	t2.x = 15, t2.y = 10, t2.z = 15 ,t2.w = 1;
	res = ft_sub_tuple(t1, t2);
	ft_print_tuple(res, "ok\n");
}
