#include "minirt.h"

t_matrix	ft_create_matrix(int rows, int cols, int identity)
{
	t_matrix	m;
	t_iter		h;

	h = ft_iter(0);
	m.rows = rows;
	m.cols = cols;
	while (h.r < rows)
	{
		h.c = 0;
		while (h.c < cols)
		{
			if (identity && rows == cols && h.c == h.r)
				m.data[h.r][h.c] = 1;
			else
				m.data[h.r][h.c] = 0;
			h.c++;
		}
		h.r++;
	}
	return (m);
}
