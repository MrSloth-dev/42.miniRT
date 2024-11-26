#include "minirt.h"

int	main()
{
	t_canvas	canvas;
	ft_init_canvas(&canvas);
	// ft_mlx_init(&canvas);
	ft_setup(&canvas);
	jumpingball(&canvas);
	return (0);
}
