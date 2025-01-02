#include "minirt.h"

t_matrix	ft_transpose_matrix(t_matrix src)
{
	double	tmp;
	t_iter	h;

	h = ft_iter(-1);
	while (++h.r < src.rows)
	{
		h.c = h.r;
		while (++h.c < src.cols)
		{
			if (h.c != h.r)
			{
				tmp = src.data[h.r][h.c];
				src.data[h.r][h.c] = src.data[h.c][h.r];
				src.data[h.c][h.r] = tmp;
			}
		}
	}
	return (src);
}
