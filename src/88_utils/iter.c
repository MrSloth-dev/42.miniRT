#include "minirt.h"

t_iter	ft_iter(int n)
{
	t_iter	h;

	h.r = n;
	h.c = n;
	h.rs = n;
	h.cs = n;
	return (h);
}
