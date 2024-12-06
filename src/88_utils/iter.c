#include "minirt.h"

t_iter	ft_iter(int n)
{
	t_iter	h;

	h.r = n;
	h.c = n;
	h.rs = n;
	h.cs = n;
	h.k = n;
	return (h);
}

//r = row
//c = colum
//rs = row_spared
//cs = col_spared
//k = helper var
