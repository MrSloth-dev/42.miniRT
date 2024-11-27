#include "minirt.h"

t_tuple	ft_operator(t_tuple a, char op, t_tuple b)
{
	double	w;
	t_tuple	r;

	r = (t_tuple){0, 0, 0, 0};
	w = a.w || b .w;
	if (a.w == 3)
		w = 3;
	if (op == '+')
		r = (t_tuple){a.x + b.x, a.y + b.y, a.z + b.z, w};
	else if (op == '-')
	{
		if (a.w && b.w && a.w != 3)
			w = 0;
		r = (t_tuple){a.x - b.x, a.y - b.y, a.z - b.z, w};
	}
	else if (op == '*')
		r = (t_tuple){a.x * b.x, a.y * b.y, a.z * b.z, w};
	return (r);
}
