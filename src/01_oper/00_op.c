#include "minirt.h"

t_tuple	ft_op(t_tuple a, char op, t_tuple b)
{
	double	ret_w;

	ret_w = a.w || b .w;
	if (a.w == 3)
		ret_w = 3;
	if (op == '+')
		return ((t_tuple){a.x + b.x, a.y + b.y, a.z + b.z, ret_w});
	else if (op == '-')
		return ((t_tuple){a.x - b.x, a.y - b.y, a.z - b.z, ret_w});
	else if (op == '*')
		return ((t_tuple){a.x * b.x, a.y * b.y, a.z * b.z, ret_w});
	else
		return ((t_tuple){0, 0, 0, ret_w});
}
