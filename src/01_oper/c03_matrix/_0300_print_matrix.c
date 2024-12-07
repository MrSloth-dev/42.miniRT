#include "minirt.h"

void	ft_print_matrix(t_matrix m)
{
	t_iter	h;

	h = ft_iter(0);
	while (h.r < m.rows)
	{
		h.c = 0;
		while (h.c < m.cols)
		{
			printf("% .5f    ", m.data[h.r][h.c]);
			h.c++;
		}
		printf("\n");
		h.r++;
	}
}
